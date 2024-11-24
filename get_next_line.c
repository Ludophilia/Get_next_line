/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/24 18:59:34 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 1

ssize_t	update_stash(int fd, char **stash)
{
	char		buffer[BUFFER_SIZE];
	ssize_t		bytesread;
	char		*old_stash;
	
	bytesread = read(fd, buffer, BUFFER_SIZE);
	if (bytesread == -1)
	{
		// free the stash here?
		return (-1);
	}
	if (bytesread == 0)
	{
		// There is nothing else to read, return the stash at top level?
		return (0);
	}
	if (*stash == NULL)
	{
		*stash = ft_strdup(buffer);
		if (*stash == NULL)
			return (-1);
	}
	else
	{
		old_stash = *stash;
		*stash = ft_strjoin(old_stash, buffer);
		if (*stash == NULL)
			return (-1);
		free(old_stash);
	}
	return (bytesread);
}

char	*extract_line(char **stash)
{
	
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)

// What it should do, because iForgot?
//	- read from a fd
//		- store the result into a buffer 
// 	- update the stash with the buffer

// - return the line (if '\n' or EOF)
char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	ssize_t			bytesread;

	if (fd < 0)
		return (NULL);
	// stash = NULL // DOUBT
	bytesread = update_stash(fd, &stash);
	while (bytesread > 0 && get_char_pos(stash, '\n') == -1)
		bytesread = update_stash(fd, &stash);
	if (bytesread == -1)
	{
		free(stash);
		return (NULL);
	}
	line = extract_line(char **stash);
	return (line);
}