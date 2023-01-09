/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:04:39 by jgermany          #+#    #+#             */
/*   Updated: 2023/01/09 13:13:06 by jgermany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>

void	test_line(int fd, char *expect);
void	gnl_testcase(char *name, char *path,  int lines, char *expect[]);

void	happy_path_series(int doit);
void	nothing_series(int doit);
void	no_newline_series(int doit);