#! /bin/bash

NAME="get_next_line"

CC="cc"

CFLAGS="-Wall -Wextra -Werror -g3"

SRCS='main.c'
SRCS+=' get_next_line.c'
SRCS+=' get_next_line_utils.c'

if [ $# -eq 0 ]; then
	$CC $CFLAGS -o $NAME $SRCS
fi