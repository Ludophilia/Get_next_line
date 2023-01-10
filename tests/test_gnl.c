/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:04:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/10 17:24:37 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "includes/test_gnl.h"

char	*format_expect(char *expect)
{
	char	*new_expect;
	char	*entry;
	int		i;

	if (!expect)
		return ((char *)0);
	if (strchr(expect, '\n'))
		new_expect = calloc(strlen(expect) + 1 + 1, sizeof(char));
	else
		return (strdup(expect));
	if (!new_expect)
		return ((char *)0);
	i = -1;
	entry = new_expect;
	while (expect[++i])
	{
		if (expect[i] == '\n')
		{
			*new_expect++ = '\\';
			*new_expect++ = 'n';
		}
		else
			*new_expect++ = expect[i];
	}
	return (entry);
}

void	test_line(int fd, char *expect)
{
	char	*res[] = {"KO", "OK"};
	char	*format_str;
	char	*format_exp;
	char	*line;
	int		test;
	
	line = get_next_line(fd);
	format_exp = format_expect(expect);
	test = expect ? strcmp(line, expect) == 0 : line == expect;
	if (expect && strlen(expect) > 15)
		format_str = "\t\tget_next_line(%i) == '%.15s...' -> '%s'\n";
	else
		format_str = "\t\tget_next_line(%i) == '%s' -> '%s'\n";
	printf(format_str, fd, format_exp, res[test]);
	assert(test);
	free(line);
	free(format_exp);
}

void	gnl_testcase(char *name, char *path, off_t offset, int lines,
		char *expect[])
{
	int		fd;
	int		i;

	if (path)
	{
		printf("\n\t%s with %s\n", name, path);
		fd = open(path, O_RDONLY);
		lseek(fd, offset, SEEK_SET);
	}
	else
		fd = 0;
	i = -1;
	while (++i < lines)
		test_line(fd, expect[i]);
	close(fd);
}

int	main(void)
{
	printf("\nget_next_line with BUFFER_SIZE=%i\n", BUFFER_SIZE);
	happy_path_series(1);
	nothing_series(1);
	no_newline_series(1);
	newline_series(1);
	file_descriptor_series(1);
}
