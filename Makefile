# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2023/01/08 18:28:41 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= test_gnl

CC 			= cc
CCFL 		= -Wall -Wextra -Werror
MCRFL		= -D BUFFER_SIZE=$(BFSZ)
INCFL		= -I$(INCDIR)

BFSZ		= ${SIZE}
INCDIR 		= .
TESDIR		= tests

CM 			= get_next_line.c get_next_line_utils.c
OBM 		= $(CM:.c=.o)

UNAME 		= $(shell uname -s)
ifeq 		($(UNAME), Linux)
	VG 		= valgrind
	VGFL 	= --leak-check=full --show-leak-kinds=all --track-origins=yes 
endif

all: 		$(NAME)

test_%:
			$(CC) $(CCFL) $(INCFL) $(MCRFL) $(TESDIR)/$@.c $(CM) \
				-o $(TESDIR)/$@.out
			./$(TESDIR)/$@.out
			
mtest_%:	test_%
			$(VG) $(VGFL) ./$(TESDIR)/$<.out

re: 		fclean all
fclean: 	clean
			rm -f $(NAME)
clean:
			rm -f $(OBM)
			rm -f $(wildcard tests/*.out)
			
.PHONY: 	all re fclean clean
