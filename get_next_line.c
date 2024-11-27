/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/27 12:55:36 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

ssize_t	update_stash(int fd, char **stash)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytesread;
	char		*old_stash;
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
	old_stash = *stash;
	*stash = ft_strjoin(old_stash, buffer);
	if (*stash == NULL)
	{
		free(old_stash);
		return (-1);
	}
	free(old_stash);
	return (bytesread);
}

char	*extract_line(ssize_t nl_pos, char **stash)
{
	char	*line;
	char	*old_stash;

	if (nl_pos == -1 || nl_pos + 1ul == ft_strlen(*stash))
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
	old_stash = *stash;
	*stash = ft_substr(old_stash, nl_pos + 1, ft_strlen(old_stash) \
		- (nl_pos + 1));
	if (*stash == NULL)
	{
		free(old_stash);
		return (NULL);
	}
	free(old_stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	ssize_t			bytesread;
	ssize_t			nl_pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	nl_pos = -1;
	bytesread = update_stash(fd, &stash);
	while (bytesread > 0 && get_char_pos(stash, '\n', &nl_pos) == -1)
		bytesread = update_stash(fd, &stash);
	if (bytesread == -1)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash)
	{
		line = extract_line(nl_pos, &stash);
		return (line);
	}
	return (NULL);
}
