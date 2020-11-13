# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2020/11/13 14:45:41 by cphillip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc -Wall -Wextra

LIBFT_DIR = ./libft/
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_HEADER = $(LIBFT_DIR)header/
LIBRARIES = -lft -L$(LIBFT_DIR)

HEADER_FILE = lem_in.h
HEADER_DIR = ./includes/
HEADERS = $(addprefix $(HEADER_DIR), $(HEADER_FILE))
INCLUDES = -I$(HEADER_DIR) -I$(LIBFT_HEADER)

SRC_DIR = ./src/
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
SRC_FILES = lem_in.c\
			capture_comment.c\
			capture_room.c\
			capture_ants.c\
			capture_flags.c\
			capture_links.c\
			inits.c\
			inits2.c\
			parse_lines.c\
			load_help.c\
			validate_coords.c\
			validate_rooms.c\
			error_mgmt.c\
			error_mgmt2.c\
			realloc_ht.c\
			node_work.c\
			node_work2.c\
			creating.c\
			printing.c\
			printing2.c\
			link_work.c\
			tools.c\
			freeing.c\
			freeing2.c\
			find_paths.c\
			choose_paths.c\
			calc_distribution.c\
			ants_marching.c\
			write_moves.c\
			sort_paths.c\
			ft_intcat.c\
			bfs.c\
			build_paths.c\
			ll_lol.c\
			ll_lol2.c\

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
