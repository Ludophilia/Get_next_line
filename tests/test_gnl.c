/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:04:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/06 13:04:54 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		turns;
	char	*line;

	fd = open("tests/test_file0.txt", O_RDONLY);
	// printf("\tfd -> %i\n", fd);
	turns = 50;
	while (turns--)
	{
		line = get_next_line(fd);
		printf("\tGNL -> '%s'\n", line);
		free(line);
		// line = get_next_line(1);
		// printf("\tGNL -> '%s'\n", line);
		// free(line);
	}
	close(fd);
}