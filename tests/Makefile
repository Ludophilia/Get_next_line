# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2023/01/15 16:52:35 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME						= test_gnl.out
NAME_B						= test_gnl_bonus.out

ROOT						= ..
TSDIR						= $(ROOT)/tests
CASDIR						= $(TSDIR)/testcases

CC							= cc
CCFL						= -Wall -Wextra -Werror
MCRFL						= -D BUFFER_SIZE=${SIZE}
GIFL						= -I$(ROOT)
TIFL						= -I$(TSDIR)/includes

GNLSC						= $(ROOT)/get_next_line.c \
								$(ROOT)/get_next_line_utils.c
GNLSC_B						= $(ROOT)/get_next_line_bonus.c \
								$(ROOT)/get_next_line_utils_bonus.c
TSSC						= $(TSDIR)/test_gnl.c \
								$(CASDIR)/happy_path.c \
								$(CASDIR)/no_newline_series.c \
								$(CASDIR)/newline_series.c \
								$(CASDIR)/file_descriptor_series.c \
								$(CASDIR)/nothing_series.c
GNLOB						= $(GNLSC:.c=.o)
GNLOB_B						= $(GNLSC_B:.c=.o)

TSOB						= $(TSSC:.c=.o)

UNAME						= $(shell uname)
ifeq						($(UNAME), Linux)
VG							= valgrind
VGFL						= --leak-check=full --show-leak-kinds=all \
								--track-origins=yes
endif

all:						$(NAME)
							@./$<
bonus:						$(NAME_B)
							@./$<

memtest:					$(NAME)
							@$(VG) $(VGFL) ./$<
memtestb:					$(NAME_B)
							@$(VG) $(VGFL) ./$<

$(NAME):					$(GNLOB) $(TSOB)
							$(CC) $(CCFL) $(GIFL) $(TIFL) $^ -o $@
$(NAME_B):					$(GNLOB_B) $(TSOB)
							$(CC) $(CCFL) $(GIFL) $(TIFL) $^ -o $@

get%.o:						get%.c
							$(CC) $(CCFL) $(MCRFL) $(GIFL) -c $< -o $@
$(TSDIR)/%.o:				$(TSDIR)/%.c
							$(CC) $(CCFL) $(MCRFL) $(GIFL) $(TIFL) -c $< -o $@

re:							fclean all
fclean:						clean
							@rm -f $(NAME)
							@rm -f $(NAME_B)
clean:
							@rm -f $(GNLOB)
							@rm -f $(GNLOB_B)
							@rm -f $(TSOB)
			
.PHONY:						all re fclean clean
