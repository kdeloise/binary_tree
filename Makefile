# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdeloise <kdeloise@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:57:22 by kdeloise          #+#    #+#              #
#    Updated: 2019/10/26 02:47:27 by kdeloise         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	flag_l.c flag_r.c ft_err.c ft_files.c \
		ft_fillfl.c ft_fillstr.c ft_lenlst.c ft_listsort.c ft_ls.c ft_name.c \
		ft_r.c ft_strjoinp.c ft_time.c ft_tout.c ft_toutr.c ft_trfree.c ft_tu.c

OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = ft_ls

SRC_PATH = ./
LIB_PATH = libft/
OBJ_PATH = obj/

SRC_LIB = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -I,$(LIB_PATH)*.h)

CC = gcc
CFLAGS = -I ft_ls.h #-Wall -Wextra -Werror
LDFLAGS = -Llibft libft/libftprintf.a
#LDLIBS = -lft

all:$(NAME)

$(NAME):$(OBJ)
	@make -C libft/
	@$(CC) $(LDFLAGS) $^ -o $@
	@echo "\033[32mCompilation done !\033[0m"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(LIB) -o $@ -c $<

clean:
	@make -C libft/ fclean
	@rm -rfv $(OBJ)
	@rm -rfv $(OBJ_PATH)
	@echo "\033[32mObjects cleaned !\033[0m"

fclean: clean
	@rm -rfv $(NAME)
	@echo "\033[32mExecutable cleaned !\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
