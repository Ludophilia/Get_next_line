/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/27 20:12:22 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_stash(char **stash)
{
	if (stash == NULL)
		return (0);
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (1);
}

static long	get_char_pos(int c, const char *s)
{
	long	len;
	long	i;

	len = ft_strlen(s);
	i = -1;
	while (++i < len)
		if (s[i] == (char)c)
			return (i);
	return (-1);
}

static long	update_stash(int fd, char *buffer, char **stash)
{
	char	*new_stash;
	long	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == 0 || (bytes == -1 && free_stash(stash)))
		return (bytes);
	buffer[bytes] = 0;
	if (*stash == NULL)
	{
		*stash = ft_strdup(buffer);
		if (*stash == NULL)
			return (-1);
		return (bytes);
	}
	new_stash = ft_strjoin(*stash, buffer);
	if (new_stash == NULL && free_stash(stash))
		return (-1);
	*stash = (free(*stash), new_stash);
	return (bytes);
}

static char	*extract_line(char **stash)
{
	char	*line;
	long	nl_pos; // 28/05 - We don;t want this.
	char	*new_stash;
	long	stash_len;

	nl_pos = get_char_pos('\n', *stash);
	stash_len = ft_strlen(*stash);
	if (nl_pos == -1 || nl_pos + 1 == stash_len)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, nl_pos + 1);
	if (line == NULL && free_stash(stash))
		return (NULL);	
	new_stash = ft_substr(*stash, nl_pos + 1, stash_len - (nl_pos + 1));
	if (new_stash == NULL && (free(line), free_stash(stash)))
		return (NULL);
	*stash = (free(*stash), new_stash);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	long		bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(&stash))
		return (NULL);
	bytes = update_stash(fd, buffer, &stash);
	// 28/05 - Find a way to get rid of the need to scan TWICE nl_pos
	//		 -  After that, check the utils again
	while (bytes > 0 && get_char_pos('\n', stash) == -1)
		bytes = update_stash(fd, buffer, &stash);
	free(buffer);
	if (bytes == -1 || stash == NULL)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
