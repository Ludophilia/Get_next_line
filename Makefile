# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2023/01/06 13:44:15 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test_gnl
CC 			= cc
CCFL 		= -Wall -Wextra -Werror

INCDIR 		= .

BFSZ		= ${BSIZE}

CM 			= get_next_line.c get_next_line_utils.c
OBM 		= $(CM:.c=.o)

UNAME 		= $(shell uname -s)
ifeq 		($(UNAME), Linux)
	VG 		= valgrind
	VGFL 	= --leak-check=full --show-leak-kinds=all --track-origins=yes 
endif

all: 		$(NAME)

test_%:
			$(CC) $(CCFL) -I$(INCDIR) -D BUFFER_SIZE=$(BFSZ) \
			tests/$@.c $(CM) -o tests/$@.out
			./tests/$@.out
			
m_test_%:	test_%
			$(VG) $(VGFL) ./$<.out

re: 		fclean all
fclean: 	clean
			rm -f $(NAME)
clean:
			rm -f $(OBM)

.PHONY: 	all re fclean clean
