/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/15 18:34:36 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	**free_stash(char **stash)
{
	if (!*stash)
	{
		free(stash);
		return (0);
	}
	return (stash);
}

char	*extract_line(char **stash)
{
	char	*old_stash;
	char	*line;
	int		newline_pos;
	size_t	stash_size;

	newline_pos = ft_strchr_sp(*stash, '\n');
	stash_size = ft_strlen(*stash) - (newline_pos + 1);
	if (newline_pos >= 0 && stash_size)
	{
		old_stash = *stash;
		line = ft_substr(old_stash, 0, newline_pos + 1);
		*stash = ft_substr(old_stash, newline_pos + 1, stash_size);
		free(old_stash);
	}
	else
	{
		line = *stash;
		*stash = 0;
	}
	return (line);
}

ssize_t	update_stash(int fd, char **stash)
{
	ssize_t		bytesread;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread > 0)
		stash = write_stash(stash, bytesread, buffer);
	free(buffer);
	return (bytesread);
}

char	*get_next_line(int fd)
{
	static char		**stash;
	char			*line;
	ssize_t			bytesread;

	if (!stash)
		stash = ft_calloc(1, sizeof(char *));
	if (!stash || BUFFER_SIZE < 1 || fd < 0)
		return (0);
	bytesread = update_stash(fd, stash);
	while (bytesread > 0 && ft_strchr_sp(*stash, '\n') == -1)
		bytesread = update_stash(fd, stash);
	if (bytesread == 0 && (!*stash))
	{
		stash = free_stash(stash);
		return (0);
	}
	if (bytesread == -1)
		return (0);
	line = extract_line(stash);
	stash = free_stash(stash);
	return (line);
}
