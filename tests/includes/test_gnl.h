/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:04:39 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/10 11:40:53 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

void	test_line(int fd, char *expect);
void	gnl_testcase(char *name, char *path, off_t offset, int lines,
		char *expect[]);

void	happy_path_series(int do_it);
void	nothing_series(int do_it);
void	no_newline_series(int do_it);
void	newline_series(int do_it);