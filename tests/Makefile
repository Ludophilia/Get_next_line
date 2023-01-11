# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2023/01/11 13:05:57 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= test_gnl.out

CC							= cc
CCFL						= -Wall -Wextra -Werror
MCRFL						= -D BUFFER_SIZE=${SIZE}
GIFL						= -I$(ROOT)
TIFL						= -I$(TSDIR)/includes

ROOT						= ..
TSDIR						= $(ROOT)/tests
CASDIR						= $(TSDIR)/testcases

GNLSC						= $(ROOT)/get_next_line.c \
								$(ROOT)/get_next_line_utils.c
TSSC						= $(TSDIR)/test_gnl.c \
								$(CASDIR)/happy_path.c \
								$(CASDIR)/no_newline_series.c \
								$(CASDIR)/newline_series.c \
								$(CASDIR)/file_descriptor_series.c \
								$(CASDIR)/nothing_series.c
GNLOB						= $(GNLSC:.c=.o)
TSOB						= $(TSSC:.c=.o)

UNAME						= $(shell uname)
ifeq						($(UNAME), Linux)
VG							= valgrind
VGFL						= --leak-check=full --show-leak-kinds=all \
								--track-origins=yes
endif

all:						$(NAME)
							@./$<

memtest:					$(NAME)
							@$(VG) $(VGFL) ./$<
		
$(NAME):					$(GNLOB) $(TSOB)
							$(CC) $(CCFL) $(GIFL) $(TIFL) $^ -o $@

get%.o:						get%.c
							$(CC) $(CCFL) $(MCRFL) $(GIFL) -c $< -o $@

$(TSDIR)/%.o:				$(TSDIR)/%.c
							$(CC) $(CCFL) $(MCRFL) $(GIFL) $(TIFL) -c $< -o $@

re:							fclean all
fclean:						clean
							@rm -f $(NAME)
clean:
							@rm -f $(GNLOB)
							@rm -f $(TSOB)
			
.PHONY:						all re fclean clean
