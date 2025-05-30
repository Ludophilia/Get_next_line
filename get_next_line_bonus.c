/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:27 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	free_stash(char **stash)
{
	if (stash == NULL)
		return (0);
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (1);
}

static int	get_nl_pos(char **stash, long *nl_pos)
{
	long	len;
	long	i;

	*nl_pos = -1;
	if (*stash == NULL)
		return (1);
	len = ft_strlen(*stash);
	i = -1;
	while (++i < len)
	{
		if ((*stash)[i] == '\n')
		{
			*nl_pos = i;
			break ;
		}
	}
	return (1);
}

static char	*extract_line(long nl_pos, char **stash)
{
	char	*line;
	char	*new_stash;
	long	stash_len;

	stash_len = ft_strlen(*stash);
	if (nl_pos == -1 || (nl_pos + 1) == stash_len)
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, (nl_pos + 1));
	if (line == NULL && free_stash(stash))
		return (NULL);
	new_stash = ft_substr(*stash, (nl_pos + 1), (stash_len - (nl_pos + 1)));
	if (new_stash == NULL && (free(line), free_stash(stash)))
		return (NULL);
	*stash = (free(*stash), new_stash);
	return (line);
}

static long	update_stash(int fd, char *buffer, long *nl_pos, char **stash)
{
	char	*new_stash;
	long	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if ((bytes == 0 && get_nl_pos(stash, nl_pos))
		|| (bytes == -1 && free_stash(stash)))
		return (bytes);
	buffer[bytes] = 0;
	if (*stash == NULL)
	{
		*stash = ft_strdup(buffer);
		if (*stash == NULL)
			return (-1);
		get_nl_pos(stash, nl_pos);
		return (bytes);
	}
	new_stash = ft_strjoin(*stash, buffer);
	if (new_stash == NULL && free_stash(stash))
		return (-1);
	*stash = (free(*stash), new_stash);
	get_nl_pos(stash, nl_pos);
	return (bytes);
}

char	*get_next_line(int fd)
{
	static char	*stash[65536];
	char		*line;
	char		*buffer;
	long		read;
	long		nl_pos;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL && free_stash(stash + fd))
		return (NULL);
	read = update_stash(fd, buffer, &nl_pos, (stash + fd));
	while (read > 0 && nl_pos == -1)
		read = update_stash(fd, buffer, &nl_pos, (stash + fd));
	free(buffer);
	if (read == -1 || stash[fd] == NULL)
		return (NULL);
	line = extract_line(nl_pos, (stash + fd));
	return (line);
}
