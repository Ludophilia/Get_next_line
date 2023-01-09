/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:04:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/09 18:35:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "includes/test_gnl.h"

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

int	main(void)
{
	printf("get_next_line with BUFFER_SIZE=%i\n", BUFFER_SIZE);
	happy_path_series(0);
	nothing_series(0);
	no_newline_series(0);
}
