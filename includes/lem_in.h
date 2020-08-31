/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 13:20:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H


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
	char			*name;
	char			*start_or_end;
	int				x;
	int				y;
	int				L_toggle;
	char			*c1;
	int				*c1_loc; // maybe not needed here. In hash table preferably
	char			*c2;
	int				*c2_loc; // maybe not needed here. In hash table preferably
	struct s_room	*next;
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
	t_room 			*room_head;
	char			*comment;
	int 			s_toggle;
	int				e_toggle;
	int 			nbr_ants;
	int				a_errors;
	int				ants_captured;
}				t_master;

/*
**	INITIALIZATION
*/

void	init_master(t_master *master);
void	init_room(t_room *room);

/*
**	DATA CAPTURING
*/

// void	parse_line(t_master *master, char **av, int fd);
// void	parse_line(t_master *master, char *line);
void	parsing(t_master *master, int fd);
t_room	*capture_room(t_master *master, char *line);
void	capture_ants(t_master *master, char *line);
void	capture_flags(t_master *master, char *av);
void	capture_comment(t_master *master, char *str);

#endif