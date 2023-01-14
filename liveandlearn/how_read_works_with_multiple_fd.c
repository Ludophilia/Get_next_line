/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_read_works_with_multiple_fd.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:43:11 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/14 17:03:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 11
#endif

void	read_and_print(int fd)
{
	char	*buffer;

	buffer = calloc(BUFFER_SIZE + 1, 1);
	
	printf("fd: %i\n", fd);
	printf("Bytesread: %li\n", read(fd, buffer, BUFFER_SIZE));
	printf("Buffer: '%s'\n\n", buffer);
	
	free(buffer);
}

int	main(void)
{
	int	i = 0;
	int	fds[] = {
		open("testfiles/testfile_nl3.txt", O_RDONLY),
		open("testfiles/testfile_nl4.txt", O_RDONLY),
		open("testfiles/testfile_nnl4.txt",  O_RDONLY),
		0
	};
	read_and_print(fds[0]);
	read_and_print(fds[1]);
	read_and_print(fds[2]);
	read_and_print(fds[0]);
	read_and_print(fds[0]);
	read_and_print(fds[1]);
	read_and_print(fds[1]);
	read_and_print(fds[0]);
	read_and_print(fds[2]);
	read_and_print(fds[2]);
	while (fds[i])
		close(fds[i++]);
}