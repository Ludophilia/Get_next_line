/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:04:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/06 17:33:47 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

void	test_line(int fd, char *expect)
{
	char	*line;
	int		test;
	char	*res[] = {"KO", "OK"};
	
	line = get_next_line(fd);
	test = expect ? strcmp(line, expect) == 0 : line == expect;
	printf("\t\tget_next_line(%i) == '%s' -> %s\n", fd, expect, res[test]);
	assert(test);
	free(line);
}

void	gnl_testcase(char *name, char *path,  int lines, char *expect[])
{
	int		fd;
	int		i;

	printf("\t%s with %s\n", name, path);
	fd = open(path, O_RDONLY);
	i = -1;
	while (++i < lines)
		test_line(fd, expect[i]);
	close(fd);
}

// GNL return the line from fd (with a \n if it contains one) as a char *
// Repeated calls to your gnl should let you read the fd one line at a time
// or NULL/(char *)0 in case of error.
int	main(void)
{
	printf("Test get_next_line:\n");
	gnl_testcase(
		"Happy Path (1)",
		"tests/testfile0.txt",
		4,
		(char *[]){
			"Hello everyone,\n",
			"Glad to see you all again in such good shape :)",
			(char *)0,
			(char *)0
		}
	);
}
