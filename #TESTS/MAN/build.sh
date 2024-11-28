#! /bin/bash

NAME="get_next_line"

CC="cc"

CFLAGS="-Wall -Wextra -Werror -g3"

GNL_DIR="../.."

SRCS='main.c'
SRCS+=" $GNL_DIR/get_next_line.c"
SRCS+=" $GNL_DIR/get_next_line_utils.c"

if [ $# -eq 0 ]; then
	$CC $CFLAGS -I$GNL_DIR -o $NAME $SRCS
fi