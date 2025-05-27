/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/27 15:30:01 by jegerman         ###   ########.fr       */
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

static int	swap_stash(char **stash, char *candidate)
{
	if (candidate == NULL && free_stash(stash))
		return (-1);
	free(*stash);
	*stash = candidate;
	return (0);
}

static long	update_stash(int fd, char *buffer, char **stash)
{
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
	if (swap_stash(stash, ft_strjoin(*stash, buffer)) == -1)
		return (-1);
	return (bytes);
}

static char	*extract_line(char **stash)
{
	long	nl_pos;
	char	*line;
	char	*tmp;

	nl_pos = get_char_pos(*stash, '\n');
	if (nl_pos == -1 || nl_pos + 1 == ft_strlen(*stash))
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, nl_pos + 1);
	if (line == NULL && free_stash(stash))
		return (NULL);
	tmp = ft_substr(*stash, nl_pos + 1, ft_strlen(*stash) - (nl_pos + 1));
	if (swap_stash(stash, tmp) == -1)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	long		bytes;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(&stash))
		return (NULL);
	bytes = update_stash(fd, buffer, &stash);
	while (bytes > 0 && get_char_pos(stash, '\n') == -1)
		bytes = update_stash(fd, buffer, &stash);
	free(buffer);
	if (bytes == -1 || stash == NULL)
		return (NULL);
	// 27/05 -
	line = extract_line(&stash);
	return (line);
}
