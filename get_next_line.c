/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/27 16:47:59 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	swap_stash(char **stash, char *candidate)
{
	char	*old_stash;

	old_stash = *stash;
	if (candidate == NULL)
	{
		*stash = NULL;
		free(old_stash);
		return (-1);
	}
	*stash = candidate;
	free(old_stash);
	return (0);
}

ssize_t	update_stash(int fd, char *buffer, char **stash)
{
	ssize_t		bytesread;
	char		*tmp_stsh;
	int			i;

	i = -1;
	while (++i < BUFFER_SIZE + 1)
		buffer[i] = 0;
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1 || bytesread == 0)
		return (bytesread);
	if (*stash == NULL)
	{
		*stash = ft_strdup(buffer);
		if (*stash == NULL)
			return (-1);
		return (bytesread);
	}
	tmp_stsh = ft_strjoin(*stash, buffer);
	if (swap_stash(stash, tmp_stsh) == -1)
		return (-1);
	return (bytesread);
}

char	*extract_line(char **stash)
{
	ssize_t	nl_pos;
	char	*line;
	char	*tmp_stsh;

	nl_pos = get_char_pos(*stash, '\n');
	if (nl_pos == -1 || nl_pos + 1 == (ssize_t)ft_strlen(*stash))
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, nl_pos + 1);
	if (line == NULL)
	{
		free(stash);
		return (NULL);
	}
	tmp_stsh = ft_substr(*stash, nl_pos + 1, ft_strlen(*stash) \
		- (nl_pos + 1));
	if (swap_stash(stash, tmp_stsh) == -1)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	ssize_t			bytesread;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytesread = update_stash(fd, buffer, &stash);
	while (bytesread > 0 && get_char_pos(stash, '\n') == -1)
		bytesread = update_stash(fd, buffer, &stash);
	free(buffer);
	if (bytesread == -1)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
