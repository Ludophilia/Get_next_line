/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   happy_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:08:35 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/11 12:53:58 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/test_gnl.h"

void	happy_path_series(int do_it)
{
	if (!do_it)
		return ;
	gnl_testcase(
		"Happy Path (1)",
		"testfiles/" "testfile_hp1.txt",
		0,
		4,
		(char *[]){
			"Hello everyone,\n",
			"Glad to see you all again in such good shape :)",
			(char *)0,
			(char *)0
		}
	);
}
