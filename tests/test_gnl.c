/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:04:17 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/09 12:19:41 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

static void	test_line(int fd, char *expect)
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

static void	gnl_testcase(char *name, char *path,  int lines, char *expect[])
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

static void	happy_path_series(int doit)
{
	if (!doit)
		return ;
	gnl_testcase(
		"Happy Path (1)",
		"tests/testfile_hp1.txt",
		4,
		(char *[]){
			"Hello everyone,\n",
			"Glad to see you all again in such good shape :)",
			(char *)0,
			(char *)0
		}
	);
}

static void no_newline_series(int doit)
{
	if (!doit)
		return ;
	gnl_testcase(
		"No newline (1)",
		"tests/testfile_nl1.txt",
		2,
		(char *[]){
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"No newline (2)",
		"tests/testfile_nl2.txt",
		6,
		(char *[]){
			"z",
			(char *)0,
			(char *)0,
			(char *)0,
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"No newline (3)",
		"tests/testfile_nl3.txt",
		6,
		(char *[]){
			"this file still has no newline but is a little more verbose :)",
			(char *)0,
			(char *)0,
			(char *)0,
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"No newline (4)",
		"tests/testfile_nl4.txt",
		3,
		(char *[]){
			"this file will contain a decent amount of characters,"
			" but on a single line only, so let's get started. Do you"
			" know what a is? I don't know either... I didn't even"
			" correctly described it!",
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"No newline (5)",
		"tests/testfile_nl5.txt",
		3,
		(char *[]){
			"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do "
			"eiusmod tempor incididunt ut labore et dolore magna aliqua. "
			"Massa id neque aliquam vestibulum. Sit amet massa vitae tortor. "
			"In pellentesque massa placerat duis ultricies. Velit euismod in "
			"pellentesque massa. Egestas congue quisque egestas diam in arcu "
			"cursus. Tortor id aliquet lectus proin nibh nisl condimentum "
			"id. Pulvinar mattis nunc sed blandit. Blandit massa enim nec "
			"dui nunc mattis. Dui nunc mattis enim ut tellus elementum "
			"sagittis vitae. Volutpat ac tincidunt vitae semper quis lectus "
			"nulla at volutpat. Velit scelerisque in dictum non. Ut faucibus "
			"pulvinar elementum integer enim neque. Sociis natoque penatibus "
			"et magnis dis parturient montes nascetur ridiculus. Pharetra "
			"vel turpis nunc eget lorem. Leo urna molestie at elementum. "
			"Arcu bibendum at varius vel pharetra vel turpis nunc. Justo "
			"donec enim diam vulputate ut pharetra sit amet. Non odio "
			"euismod lacinia at quis risus sed vulputate. Fermentum odio eu "
			"feugiat pretium. Arcu dictum varius duis at consectetur. Et "
			"ultrices neque ornare aenean euismod elementum. Nisi est sit "
			"amet facilisis magna etiam tempor. Scelerisque fermentum dui "
			"faucibus in ornare quam viverra. Faucibus ornare suspendisse "
			"sed nisi. Sed vulputate odio ut enim blandit volutpat maecenas. "
			"Nascetur ridiculus mus mauris vitae ultricies leo integer "
			"malesuada. Vulputate eu scelerisque felis imperdiet proin "
			"fermentum. Amet facilisis magna etiam tempor. Vel quam "
			"elementum pulvinar etiam. Pellentesque pulvinar pellentesque "
			"habitant morbi tristique senectus et netus. Augue neque gravida "
			"in fermentum et sollicitudin ac orci phasellus. Lacus sed "
			"viverra tellus in hac habitasse platea dictumst. Quis hendrerit "
			"dolor magna eget.Tincidunt augue interdum velit euismod. Urna "
			"duis convallis convallis tellus id interdum velit. Nam libero "
			"justo laoreet sit amet cursus sit amet dictum. Lorem ipsum "
			"dolor sit amet consectetur adipiscing elit pellentesque. Proin "
			"nibh nisl condimentum id venenatis a condimentum vitae. Nibh "
			"ipsum consequat nisl vel pretium. Morbi enim nunc faucibus a "
			"pellentesque sit amet porttitor eget. Nunc aliquet bibendum "
			"enim facilisis gravida neque. Adipiscing enim eu turpis egestas "
			"pretium aenean pharetra. Mattis enim ut tellus elementum "
			"sagittis. Mauris ultrices eros in cursus turpis massa tincidunt "
			"dui. Aliquam ultrices sagittis orci a scelerisque purus. Quam "
			"lacus suspendisse faucibus interdum posuere lorem ipsum dolor.",
			(char *)0,
			(char *)0
		}
	);
}

int	main(void)
{
	printf("get_next_line with BUFFER_SIZE=%i\n", BUFFER_SIZE);
	happy_path_series(0);
	no_newline_series(1);
}
