#! /bin/bash

NAME="get_next_line_bonus"

CC="cc"

CFLAGS="-Wall -Wextra -Werror -g3"

GNL_DIR="../.."

SRCS='main.c'
SRCS+=" $GNL_DIR/get_next_line_bonus.c"
SRCS+=" $GNL_DIR/get_next_line_utils_bonus.c"

if [ $# -eq 0 ]; then
	$CC $CFLAGS -I$GNL_DIR -o $NAME $SRCS
fi
