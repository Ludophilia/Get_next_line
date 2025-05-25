NAME="gnl"

CFLAGS="-Wall -Wextra -Werror -g3 -fsanitize=address"
SIZE=1

SRCS="get_next_line.c get_next_line_utils.c main.c"

cc $CFLAGS -DBUFFER_SIZE=$SIZE -o $NAME $SRCS
