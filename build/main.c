/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegerman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:49:38 by jegerman          #+#    #+#             */
/*   Updated: 2025/03/22 18:22:42 by jegerman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#define PATH1 "get_next_line.h"
#define PATH2 "multiple_nl.txt"

int main(void)
{
	char	*line[2];
	int		fd[2];

	fd[0] = open(PATH1, O_RDONLY);
	if (fd[0] == -1)
		return (1);
	// fd[1] = open(PATH2, O_RDONLY);
	// if (fd[0] == -1)
	// 	return (2);
	line[0] = get_next_line(fd[0]);
	while (line[0])
	{
		printf("%s", line[0]);
		free(line[0]);
		line[0] = get_next_line(fd[0]);
	}
	// free(line[1]);
	return (0);
}
