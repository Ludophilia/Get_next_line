/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:00 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/28 14:40:33 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include <stdio.h>
#include <fcntl.h>
#include <assert.h>

#define FILE1 "file1"
#define FILE2 "file2"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	int		fd[2];
	char	*line[2];

	printf("BUFFER_SIZE -> %i\n", BUFFER_SIZE);
	fd[0] = open(FILE1, O_RDONLY);
	if (fd[0] == -1 && dprintf(2, "There was a problem with file 1\n"))
		return (1);
	fd[1] = open(FILE2, O_RDONLY);
	if (fd[1] == -1 && dprintf(2, "There was a problem with file 2\n"))
		return (1);
	line[0] = (void *)0x01;
	line[1] = (void *)0x01;
	assert(fd[0] != fd[1]);
	while (line[0] && line[1])
	{
		line[0] = get_next_line(fd[0]);
		line[1] = get_next_line(fd[1]);
		printf("[fd = %i] line0 = \"%s\"", fd[0], line[0]);
		printf("\n[fd = %i] line1 = \"%s\"", fd[1], line[1]);
		if (line[0] != NULL && line[1] != NULL)
			assert(ft_strcmp(line[0], line[1]) == 0);
		free(line[0]);
		free(line[1]);
		printf("\n");
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}
