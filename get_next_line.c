/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/25 19:29:01 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	swap_stash(char **stash, char *candidate)
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

static char	*extract_line(char **stash)
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
		if (*stash)
			free(*stash);
		*stash = NULL;
		return (NULL);
	}
	tmp_stsh = ft_substr(*stash, nl_pos + 1, ft_strlen(*stash) \
		- (nl_pos + 1));
	if (swap_stash(stash, tmp_stsh) == -1)
		return (NULL);
	return (line);
}

static ssize_t	update_stash(int fd, char *buffer, char **stash)
{
	ssize_t		bytesread;
	char		*tmp_stsh;

	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytesread == 0)
		return (0);
	buffer[bytesread] = 0;
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

// 25/05 - 
//	- Please study more thoroughly the stash lifecycle.
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
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	bytesread = update_stash(fd, buffer, &stash);
	while (bytesread > 0 && get_char_pos(stash, '\n') == -1)
		bytesread = update_stash(fd, buffer, &stash);
	free(buffer);
	if (stash == NULL || bytesread == -1)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
