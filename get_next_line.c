/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/08 18:18:59 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	fill_stash(int fd, char	**stash)
{
	char		*old_stash;
	ssize_t		bytesread;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (-1);
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread > 0)
	{
		old_stash = *stash;
		*stash = ft_strjoin(old_stash, buffer);
		free(old_stash);
	}
	free(buffer);
	return (bytesread);
}

char	*extract_line(char **stash)
{
	int		sep;
	char	*line;
	char	*old_stash;

	sep = ft_strchr_sp(*stash, '\n');
	if (sep != -1)
	{
		old_stash = *stash;
		line = ft_substr(old_stash, 0, sep + 1);
		*stash = ft_substr(old_stash, sep + 1,
				ft_strlen(old_stash) - (sep + 1));
		free(old_stash);
	}
	else
	{
		line = *stash;
		*stash = (char *)0;
		free(*stash);
	}
	return (line);
}

// The challenge of multiple fd is to have a different stash for each of them
char	*get_next_line(int fd)
{
	static char		*stash;
	ssize_t			bytesread;

	if (!stash)
		stash = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (stash)
	{
		bytesread = fill_stash(fd, &stash);
		if (bytesread == 0 && !*stash)
		{
			free(stash);
			stash = (char *)0;
			return ((char *)0);
		}
		while (bytesread > 0 && ft_strchr_sp(stash, '\n') == -1)
			bytesread = fill_stash(fd, &stash);
		if (bytesread == -1)
			return ((char *)0);
		return (extract_line(&stash));
	}
	return ((char *)0);
}
