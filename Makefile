# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2020/11/25 14:56:08 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = -Wall -Wextra

LIB = ./libft/libft.a
LIB_FOLDER = ./libft/
OBJ_DIR = ./obj

SRCS = ./srcs/
LEM_FUNCTIONS = *.c
FUNC = $(LEM_FUNCTIONS)
C_FILES = $(addprefix $(SRCS), $(LEM_FUNCTIONS))

FT_PRINTF_INC = -I ./libft/ft_printf/includes/
LIBFT_INC = -I ./libft/libft/includes/
INCLUDES = $(FT_PRINTF_INC) $(LIBFT_INC) -I ./includes/
OBJ_FILES = *.o

all: library $(NAME)

library:
	@echo "Compiling Library..."
	@make -C $(LIB_FOLDER)

$(NAME): all $(C_FILES)
	@mkdir -p $(OBJ_DIR)
	@echo "Compiling $(NAME) files..."
	gcc $(FLAGS) $(INCLUDES) -c $(C_FILES)
	gcc $(FLAGS) -o $(NAME) $(INCLUDES) $(OBJ_FILES) $(LIB)
	@mv $(OBJ_FILES) $(OBJ_DIR)

clean:
	@echo "Deleting object files"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIB_FOLDER)

fclean: clean
	@echo "Deleting $(NAME)"
	@rm -rf $(NAME)
	@echo "Deleting libft.a"
	@make fclean -C $(LIB_FOLDER)

re:	fclean all

.PHONY: library all fclean re
