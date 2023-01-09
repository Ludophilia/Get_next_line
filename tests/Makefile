# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:35:46 by jgermany          #+#    #+#              #
#    Updated: 2023/01/09 13:58:18 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# What should be done ??

# I type make on repo root (but why root) and tests should be 
# done if tests is the target

# top level makefile manage get next line creation and the tests, but not the
# details of how to build those tests

# This makefile builds whats needed for the tests to run correctly

# So what to do ??

# create a rule make all who builds test_gnl.o, an object that is built from 
# evey other source file relevant to testing

NAME		= test_gnl.o

CC 			= cc
CCFL 		= -Wall -Wextra -Werror
INCFL		= -I$(INCDIR)
MCRFL		= -D BUFFER_SIZE=$(BFSZ)

BFSZ		= ${SIZE}
INCDIR 		= .

TSSRC		= test_gnl.c testcases/happy_path.c testcases/no_newline_series.c \
			testcases/nothing_series.c
TSOBJ		= $(TSSRC:.c=.o)

all:		$(NAME)

$(NAME):	$(TSOBJ)
			echo "What you gonna do??"
