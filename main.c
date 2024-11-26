/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:26:00 by jegerman          #+#    #+#             */
/*   Updated: 2024/11/26 18:54:50 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file", O_RDONLY);
	if (fd == -1 && dprintf(2, "There was a problem with that file\n"))
		return (1);
	line = get_next_line(fd);
	printf("line = \"%s\"", line);
	free(line);
	printf("\n");
	// line = get_next_line(fd);
	// printf("line = \"%s\"", line);
	// free(line);
	// printf("\n");
	// line = get_next_line(fd);
	// printf("line = \"%s\"", line);
	// free(line);
	// printf("\n");
	// line = get_next_line(fd);
	// printf("line = \"%s\"", line);
	// free(line);
	// printf("\n");

	// while (line)
	// {
	// 	printf("line = \"%s\"", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	return (0);
}
