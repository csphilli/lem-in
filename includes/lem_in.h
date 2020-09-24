/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 10:29:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define HT_SIZE 1000000


#include "../libft/header/libft.h"

/*
**	name = room name
**	start_or_end captures the indicaiton of start or end room
**	captures any comment about the room
**	x and y are the room coordinates
**	L_toggle = 1 if there is an ant in the room, 0 if not.
**	c1/c2 = represents the name of the room connections
**	c1/c2_loc = represents the address of the connecting rooms
**	next is the pointer to the next room in list.
*/

typedef struct 	s_room
{
	int				index;
	char			*name;
	char			*start_or_end;
	int				x; // dont think i need these unless doing graphical work
	int				y;// dont think i need these unless doing graphical work
	bool			occupied;
	char			*room_links; // Look into how this will be created
	char			*comment;
	// struct s_room	*next;
}				t_room;

/*
**	room_head represents the start of the list
**	comment is a temporary pointer to comment text
**	s/e_toggle is used to capture the start or end indicator
**	nbr_ants is the number of starting ants
**	a_errors is advanced error messages
*/

typedef struct 	s_master
{
	t_room 			*list_head;
	t_room			*latest_room;
	char			*comment;	
	bool			s_toggle;
	bool			e_toggle;
	bool			adv_errors;
	bool			colors;
	bool			ants_added;
	bool			debugger;
	bool			leaks;
	int 			nbr_ants;
	int				has_flags;
	int				line_nbr;
	char			*input_flags;
	char			*accepted_flags;
	int				room_count;	
	int				room_captured;
	int				link_captured;
	bool			dummy; // remove before submission
}				t_master;

/*
**	INITIALIZATION
*/

void	init_master(t_master *master);
t_room	*init_room(t_room *room);
void	init_ht(t_room *ht[]);

/*
**	DATA CAPTURING
*/

// void	parse_line(t_master *master, char **av, int fd);
// void	parse_line(t_master *master, char *line);
// void	parsing(t_master *master, int fd);
void	parse_input(t_master *master, int fd, t_room *ht[]);
// t_room	*capture_room(t_master *master, char *line);
void	capture_room(t_master *master, char *line, t_room *ht[]);
void	capture_ants(t_master *master, char *line);
void	capture_flags(t_master *master, int ac, char **av);
void	capture_comment(t_master *master, char *str);
void	capture_link(t_master *master, char *line);
void	exit_error(t_master *master, char *error_code);
t_room	*create_room_node(t_master *master, char *line);

void	load_help(t_master *master);
void	print_list(t_master *master);
void	duplicate_check(t_master *master, char *s1, char *s2);

/*
**	Hash Table Functions
*/

void	insert_room(t_room *ht[], char *name, t_master *master);
int		gen_key(char *str);
void	print_ht(t_room *ht[]);

#endif