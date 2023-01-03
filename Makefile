# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2023/01/03 21:26:40 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= a.out

CC 			= cc
CCFL 		= -Wall -Wextra -Werror

INCDIR 		= .

BFSZ		= ${BSIZE}

CM 			= get_next_line.c
OBM 		= $(CM:.c=.o)

UNAME 		= $(shell uname -s)
ifeq 		($(UNAME), Linux)
	VG 		= valgrind
	VGFL 	= --leak-check=full --show-leak-kinds=all --track-origins=yes 
endif

all: 		$(NAME)
			@./$<

$(NAME): 	$(OBM)
			$(CC) $(CCFL) $^ -D BUFFER_SIZE=$(BFSZ) -o $@

%.o: 		%.c
			@$(CC) $(CCFL) -I$(INCDIR) -c $< -o $@
test_%: 	all
			$(CC) $(CCFL) -I$(INCDIR) tests/$@.c -l$(LIB) -L$(LIBDIR)
			./a.out
m_test_%:	test_%
			$(VG) $(VGFL) ./a.out

re: 		fclean all
fclean: 	clean
			rm -f $(NAME)
clean:
			rm -f $(OBM)

.PHONY: 	all re fclean clean
