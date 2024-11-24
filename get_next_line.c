/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:51:33 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/24 18:41:13 by jegerman         ###   ########.fr       */
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
		free(old_stash); // Inconsistent?
		if (*stash == NULL)
			return (-1);
	}
	return (bytesread);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	ssize_t			bytesread;

	if (fd < 0)
		return (NULL);
	bytesread = update_stash(int fd, char **stash, )
	while (bytesread > 0 && ft_strchr(sta) == NULL)
	// What it should do, because iForgot?
	//	- read from a fd
	//		- store the result into a buffer 
	// 	- update the stash with the buffer

	// - return the line (if '\n' or EOF)

	bytesread = ;

	
	return (NULL); // line
}