/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:13:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define HT_SIZE 1000000
# define E_BASIC "Error. For more info, use flag '-e'.\n"
# define E_MALLOC "Error. Failed to allocate memory.\n"
# define E_NO_ROOMS "Error. No rooms specified.\n"
# define E_NO_LINKS "Error. No links specified.\n"
# define E_L "Error. 'L' present at beginning of room name.\n"
# define E_COORD "Error. Invalid coordinate on line "
# define E_DUPL "Error. Duplicate room name found.\n"
# define E_FLAG "Error. Invalid flag specified.\n"
# define E_USAGE "Error. Invalid usage. Use '-h' for help.\n"
# define E_ANTS "Error. Invalid ant size specified.\n"
# define E_START "Error. Start already defined.\n"
# define E_END "Error. End already defined.\n"
# define E_NOFILE "Error. File not found.\n"
# define E_FAILED_SEARCH "Error. Room not found.\n"


#include "../libft/header/libft.h"

/*
**	For Room:
**	name = room name
**	start_or_end captures the indicaiton of start or end room
**	captures any comment about the room
**	x and y are the room coordinates
**	L_toggle = 1 if there is an ant in the room, 0 if not.
**	c1/c2 = represents the name of the room connections
**	c1/c2_loc = represents the address of the connecting rooms
**	next is the pointer to the next room in list.
*/

typedef struct 	s_entry
{
	char			*name;
	char			*comment;
	int				x;
	int				y;
	int				key;
}				t_entry;

typedef struct 	s_bucket
{
	struct s_entry 	*entry;
	struct s_bucket	*next;
}				t_bucket;

/*
**	For Master:
**	New size is used when creating a new hash table.
**	old size is used when reallocting the new table. It's purpose is
**	to confine the extent parsing is done on the old hash table.
**	Load is the nbr_keys / size of hash table. This check is used to
**	maintain an even distribution of indecies and reduce chaining on those
**	indecies to a minimum.
**	room_head represents the start of the list
**	comment is a temporary pointer to comment text
**	s/e_toggle is used to capture the start or end indicator
**	nbr_ants is the number of starting ants
**	a_errors is advanced error messages
*/

typedef struct 	s_master
{
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
	size_t			new_size;
	size_t			old_size;
	float			load;
	int				nbr_keys;
}				t_master;

/*
**	ERROR HANDLING
*/

void	exit_error(void);
void	exit_malloc(void);

/*
**	INITIALIZATION
*/

// t_room 	*create_room(void); // not used
t_entry *create_and_fill_entry(t_master *master, char *line);
void	init_master(t_master *master);
// t_room	*init_room(t_room *room);
// void	init_ht(t_room *ht[]);
// void	init_ht(t_master *master);
// void	initialize_lemin(t_master *master, t_room *ht[]);
// t_room	*init_room(t_room *room, char **data, int key, int index, t_master *master);

/*
**	DATA CAPTURING
*/

// void	fill_room(t_room *room, t_master *master, char *line);
// void	parse_input(t_master *master, int fd, t_room **ht);
// void	capture_room(t_master *master, char *line, t_room **ht);
void	capture_ants(t_master *master, char *line);
void	capture_flags(t_master *master, int ac, char **av);
void	capture_comment(t_master *master, char *str);
// void	capture_link(t_room **ht, char *line, t_master *master);

// t_room	*create_room_node(t_master *master, char *line);
void		load_help(t_master *master);
void		validate_coords(t_master *master, char *n1, char *n2);
void		duplicate_room_check(t_master *master, t_bucket **ht);
void		test_room_search(t_bucket **ht, char *name);

void		copy_room(t_bucket *dest, t_bucket *src);
void		parse_lines(t_master *master, char *line, t_bucket **ht);

/*
**	Hash Table Functions
*/

void		insert_node(t_bucket **ht, t_entry *entry, int index);
void 		assign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *entry);
int			gen_key(char *str);
t_bucket 	**create_ht(t_master *master);
t_bucket	*create_bucket(void);
void		print_ht(t_bucket **ht, t_master *master);
// void	insert_room(t_room *ht[], char *name, t_master *master);
// void	print_ht(t_room *ht[]);
// int		probe(t_room *ht[], int index);
int		room_search(t_bucket *ht[], char *name);
t_bucket	**realloc_ht(t_bucket **src, t_master *master);
t_bucket	**grow_ht(t_bucket **ht, t_master *master);
float	load(t_master *master);
// void	insert_into_ht(t_room **ht, t_master *master, t_room *room);
void	print_ht(t_bucket **ht, t_master *master);

#endif
