/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:00 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/27 14:24:52 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

#define FILE "file"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open(FILE, O_RDONLY);
	if (fd == -1 && dprintf(2, "There was a problem with that file\n"))
		return (1);
	line = (void *)0x01;
	while (line)
	{
		line = get_next_line(fd);
		printf("line = \"%s\"", line);
		free(line);
		printf("\n");
	}
	close(fd);
	return (0);
}
