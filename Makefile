# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/25 09:12:39 by cphillip          #+#    #+#              #
#    Updated: 2020/11/24 15:14:30 by cphillip         ###   ########.fr        #
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
			tools.c\
			inits.c\
			inits2.c\
			freeing.c\
			ll_work.c\
			ll_work2.c\
			lol_work.c\
			map_work.c\
			printing.c\
			load_help.c\
			node_work.c\
			printing2.c\
			printing3.c\
			link_work.c\
			error_mgmt.c\
			parse_lines.c\
			edmonds_karp.c\
			capture_room.c\
			capture_ants.c\
			ht_functions.c\
			ht_functions2.c\
			ants_marching.c\
			capture_links.c\
			capture_flags.c\
			validate_input.c\
			validate_rooms.c\
			chk_direct_link.c\
			capture_comment.c\
			optimal_solution.c\
			calc_distribution.c\
			build_distro_array.c\
			edmonds_karp_tools.c\

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJECTS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJECTS)
	$(CC) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)
	@echo "Done!"

$(OBJ_DIR):
	@mkdir -p obj
	@echo "Compiling library..."

$(OBJ_DIR)%.o:$(SRC_DIR)%.c $(HEADERS)
	@-$(CC) -c $(INCLUDES) $< -o $@	

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "Compiling $(NAME) files..."
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
