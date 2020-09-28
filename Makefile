# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2020/09/28 19:23:07 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc -Wall -Wextra -Werror

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)header/
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADER_FILE = lem_in.h
HEADER_DIR = ./includes/
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_FILES))
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER)

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_FILES = lem_in.c\
			capture_comment.c\
			insert_room.c\
			capture_ants.c\
			capture_flags.c\
			capture_link.c\
			inits.c\
			parse_input.c\
			load_help.c\
			validate_rooms.c\
			validate_coords.c\
			search_room.c\
			error_mgmt.c\
			free.c\
			realloc_ht.c\
			node_work.c\
			print_ht.c\

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJECTS)
	$(CC) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)

$(OBJ_DIR):
	@mkdir -p obj
	@echo "Object directory created"

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADERS)
	@-$(CC) -c $(INCLUDES) $< -o $@
	@echo "$@ file created"

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "libft.a created"

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
