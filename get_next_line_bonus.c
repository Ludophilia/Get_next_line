/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/14 17:08:45 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

ssize_t	fill_stash(int fd, char	**stash)
{
	char		*old_stash;
	ssize_t		bytesread;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread > 0 && !*stash)
		*stash = buffer;
	else if (bytesread > 0 && *stash)
	{
		old_stash = *stash;
		*stash = ft_strjoin(old_stash, buffer);
		free(old_stash);
		free(buffer);
	}
	else
		free(buffer);
	return (bytesread);
}

// Your get_next_line() can manage multiple file descriptors at the same time. 
// For example, if you can read from the file descriptors 3, 4 and 5, 
// you should be able to read from a different fd per call without losing 
// the reading thread of each file descriptor or returning a line from another 
// fd. It means that you should be able to call get_next_line() to read from fd
// 3, then fd 4, then 5, then once again 3, once again 4, and so forth.

// read does not miss the thread when alterning with different file descriptors
 
// so the challenge of multiple fd is to have a different stash for each 
// of them... a stash (or a str, as the stash is just a pointer to a str) 
// per file descriptor.

// But how to manage different stashes ?
// -- array of strs ??
char	*get_next_line(int fd)
{
	static char		**stash;
	char			*line;
	ssize_t			bytesread;

	if (!stash)
		stash = ft_calloc(1, sizeof(char *));
	if (!stash || BUFFER_SIZE < 1 || fd < 0)
		return (0);
	bytesread = fill_stash(fd, stash);
	while (bytesread > 0 && ft_strchr_sp(*stash, '\n') == -1)
		bytesread = fill_stash(fd, stash);
	if (bytesread == 0 && (!*stash))
	{
		free(stash);
		stash = 0;
		return (0);
	}
	if (bytesread == -1)
		return (0);
	line = extract_line(stash);
	return (line);
}
