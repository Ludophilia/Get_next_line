/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nothing_series.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:10:33 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/10 11:39:18 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_gnl.h"

void	nothing_series(int do_it)
{
	if (!do_it)
		return ;
	gnl_testcase(
		"Nothing (1)",
		"tests/testfiles/" "testfile_n1.txt",
		0,
		2,
		(char *[]){
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"Nothing (2)",
		"tests/testfiles/" "testfile_n2.txt",
		0,
		3,
		(char *[]){
			"\n",
			(char *)0,
			(char *)0
		}
	);
	gnl_testcase(
		"Nothing (3)",
		"tests/testfiles/" "testfile_n3.txt",
		0,
		6,
		(char *[]){
			"\n",
			"\n",
			"\n",
			(char *)0,
			(char *)0,
			(char *)0
		}
	);
}
