# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2021/01/01 21:47:17 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra

LIBFT = ./libft/
LINK_LIBFT = -L $(LIBFT) -lft -I$(LIBFT)/includes

FT_PRINTF = ./ft_printf/
LINK_FT_PRINTF = -L $(FT_PRINTF) -lft_printf -I$(FT_PRINTF)/includes

SRC = 	*.c
SRC_DIR = ./src/
DATA_DIR = ./src/data/
EK_DIR = ./src/edmonds_karp/
AM_DIR = ./src/ants_marching/
IO_DIR = ./src/io/


SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))\
			$(addprefix $(DATA_DIR), $(SRC))\
			$(addprefix $(EK_DIR), $(SRC))\
			$(addprefix $(AM_DIR), $(SRC))\
			$(addprefix $(IO_DIR), $(SRC))\


OBJ_FILES = $(SRC:.c=.o)

INC = ./includes

all: $(NAME)

$(NAME): $(SRC_FILES) $(INC)/lem_in.h
	@if git submodule status | egrep -q '^[-]' ; then \
		echo "INFO: Initializing git submodules"; \
		git submodule update --init --recursive; \
	fi
	@echo "Compiling $(NAME)..."
	@make -C $(LIBFT)
	@make -C $(FT_PRINTF)
	@gcc $(FLAGS) -o $(NAME) $(SRC_FILES) -I$(INC) \
	$(LINK_LIBFT) $(LINK_FT_PRINTF)	

clean:
	@rm -rf obj/
	@rm -rf $(LIBFT)/obj

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a
	@rm -rf $(FT_PRINTF)/libft_printf.a
	@rm -rf test

re: fclean all

.PHONY: all clean fclean re
