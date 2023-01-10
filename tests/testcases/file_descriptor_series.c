/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descriptor_series.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:40:06 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/10 18:06:08 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_gnl.h"

void	file_descriptor_series(int do_it)
{
	if (!do_it)
		return ;
	gnl_testcase(
		"File descriptor (1)",
		"tests/testfiles/" "???.txt",
		0,
		3,
		(char *[]){
			(char *)0,
			(char *)0,
			(char *)0
		}
	);
	// gnl_testcase(
	// 	"File descriptor (2)",
	// 	"tests/testfiles/" "forbidden_file.txt",
	// 	0,
	// 	3,
	// 	(char *[]){
	// 		(char *)0,
	// 		(char *)0,
	// 		(char *)0
	// 	}
	// );
	printf("\t\tFor the next test, type: 'Simple test' in the prompt and press"
	" enter. It's case sensitive, so be careful !!\n");
	gnl_testcase(
		"File descriptor (3)",
		(char *)0,
		0,
		1,
		(char *[]){
			"Simple test\n"
		}
	);
}
