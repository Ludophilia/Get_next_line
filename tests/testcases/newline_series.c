/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newline_series.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 09:56:20 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/10 12:29:07 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_gnl.h"

void	newline_series(int do_it)
{
	if (!do_it)
		return ;
	// gnl_testcase(
	// 	"Newline (1)",
	// 	"tests/testfiles/" "testfile_nl1.txt",
	// 	0,
	// 	3,
	// 	(char *[]){
	// 		"a\n",
	// 		(char *)0,
	// 		(char *)0
	// 	}
	// );
	// gnl_testcase(
	// 	"Newline (2)",
	// 	"tests/testfiles/" "testfile_nl2.txt",
	// 	0,
	// 	6,
	// 	(char *[]){
	// 		"s\n",
	// 		"\n",
	// 		"\n",
	// 		"\n",
	// 		"\n",
	// 		(char *)0
	// 	}
	// );
	// gnl_testcase(
	// 	"Newline (3)",
	// 	"tests/testfiles/" "testfile_nl3.txt",
	// 	0,
	// 	5,
	// 	(char *[]){
	// 		"\"Focus!\" said the anime swordsman who trained"
	// 		" a thousand moons just for this very instant.\n",
	// 		"\n",
	// 		"\n",
	// 		(char *)0,
	// 		(char *)0
	// 	}
	// );
	// gnl_testcase(
	// 	"Newline (4)",
	// 	"tests/testfiles/" "testfile_nl4.txt",
	// 	0,
	// 	13,
	// 	(char *[]){
	// 		"A man,\n",
	// 		"A chair,\n",
	// 		"A table,\n",
	// 		"A computer.\n",
	// 		"The man is looking at the screen completely flabbergasted.\n",
	// 		"Error 501.\n",
	// 		"The work he has submitted is gone.\n",
	// 		"Can't go back to the form and try to recover it.\n",
	// 		"What a tragedy.\n",
	// 		"\"Those c*nts, what are they doing?\"\n",
	// 		"Life is so unfair.",
	// 		(char *)0,
	// 		(char *)0
	// 	}
	// );
	gnl_testcase(
		"Newline (5a)",
		"tests/testfiles/" "testfile_nl5.txt",
		0,
		6,
		(char *[]){
			"Lorem ipsum dolor sit amet, consectetur"
			" adipiscing elit, sed do eiusmod tempor\n",
			"incididunt ut labore et dolore magna aliqua."
			" Massa id neque aliquam vestibulum.\n",
			"Sit amet massa vitae tortor. In pellentesque"
			" massa placerat duis ultricies.\n",
			"Velit euismod in pellentesque massa."
			" Egestas congue quisque egestas diam in\n",
			"arcu cursus. Tortor id aliquet lectus proin"
			" nibh nisl condimentum id.\n",
			"\n"
		}
	);
	gnl_testcase(
		"Newline (5c)",
		"tests/testfiles/" "testfile_nl5.txt",
		1961,
		11,
		(char *[]){
			"\n",
			"Proin nibh nisl condimentum id venenatis"
			" a condimentum vitae. Nibh ipsum\n",
			"consequat nisl vel pretium. Morbi enim nunc"
			" faucibus a pellentesque sit amet\n",
			"porttitor eget. Nunc aliquet bibendum enim"
			" facilisis gravida neque. Adipiscing\n",
			"enim eu turpis egestas pretium aenean pharetra."
			" Mattis enim ut tellus elementum\n",
			"sagittis. Mauris ultrices eros in cursus turpis"
			" massa tincidunt dui. Aliquam\n",
			"ultrices sagittis orci a scelerisque purus."
			" Quam lacus suspendisse faucibus\n",
			"interdum posuere lorem ipsum dolor.\n",
			"\n",
			"\n",
			(char *)0
		}
	);
}