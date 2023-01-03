/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:29 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/03 21:54:30 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

// should work without BUFFER_SIZE size, maybe with an ifndef
// Use read (WITH constant macro BUFFER_SIZE), malloc, free. static vars can 
// help.

// return the line from fd (with a \n if it contains one) as a char *
// Repeated calls to your gnl should let you read the fd one line at a time
// or NULL/(char *)0 in case of error.

// static for now ? in get_next_line.h ?
static void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(char *)s++ = '\x0';
}

char	*get_next_line(int fd)
{
	char		*buffer;
	ssize_t		bytesread;
	
	printf("\tBuffer size: %i\n", BUFFER_SIZE);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytesread = read(fd, buffer, BUFFER_SIZE);
	while (bytesread)
	{
		printf("\tAmount of things read: %li\n", bytesread);
		printf("\tBuffer state: '%s'\n\n", buffer);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytesread = read(fd, buffer, BUFFER_SIZE);
	}
	// What to do next ?
		// How to keep the lines read up to a certain point ?
	return (0); // Obviously, this will change
}

int	main(void)
{
	int	fd;

	fd = open("tests/test_file0.txt", O_RDONLY);
	// printf("\tfd -> %i\n", fd);
	get_next_line(fd);
	close(fd);
}