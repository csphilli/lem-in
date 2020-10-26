/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/26 09:49:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define E_BASIC "Error. For more info, use flag '-e'.\n"
# define E_MALLOC "Error. Failed to allocate memory.\n"
# define E_NO_ROOMS "Error. No rooms specified.\n"
# define E_NO_LINKS "Error. No links specified.\n"
# define E_NOPATH "Error. No solution. No path from start to end exists.\n"
# define E_L "Error. 'L' present at beginning of room name.\n"
# define E_COORD "Error. Invalid coordinate on line "
# define E_DUPL "Error. Duplicate room name found: "
# define E_FLAG "Error. Invalid flag specified.\n"
# define E_USAGE "Error. Invalid usage. Use '-h' for help.\n"
# define E_ANTS "Error. Invalid ant size specified.\n"
# define E_START "Error. Start already defined.\n"
# define E_END "Error. End already defined.\n"
# define E_NOFILE "Error. File not found.\n"
# define E_FAILED_SEARCH "Error inserting link. Room not found: "
# define E_NOSOLUTION "Error. No Solution. Start and/or End room undefined."
# include "../libft/header/libft.h"

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

typedef struct		s_bucket
{
	struct s_entry	*entry;
	struct s_bucket	*next;
}					t_bucket;

typedef struct		s_entry
{
	char			*name;
	char			*comment;
	struct s_entry	**link_arr;
	int				x;
	int				y;
	int				key;
	bool			visited;
	int				occ;
	int				n_ants;
}					t_entry;

typedef struct		s_dfs
{
	struct s_entry	**q;
}					t_dfs;

/*
**	**p = all PATHS found from initial DFS
**	**c = CHOSEN paths from the DFS.
*/

typedef struct		s_paths
{
	struct s_bucket	**p;
	struct s_bucket	**c;
	struct s_entry	*s_room;
	struct s_entry	*e_room;
	int				max_paths;
	int				shortest_index;	
	int				index;
	int				p_len;
	int				c_len;
	int				collision;
}					t_paths;

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

typedef struct		s_master
{
	char			*comment;
	bool			s_toggle;
	bool			e_toggle;
	char			*start_room;
	char			*end_room;
	bool			adv_errors;
	bool			colors;
	bool			valid_input;
	bool			ants_added;
	bool			debugger;
	bool			leaks;
	int				nbr_ants;
	int				has_flags;
	int				line_nbr;
	char			*input_flags;
	char			*accepted_flags;
	int				room_count;
	size_t			new_size;
	size_t			old_size;
	size_t			size_factor;
	float			load;
	int				nbr_keys;
}					t_master;

/*
**	ERROR HANDLING
*/

void				exit_error(void);
void				exit_malloc(void);
void				exit_usage(void);
void				exit_coord(int line_nbr);
void				exit_dup(char *room_name, size_t index);
void				exit_room_not_found(char *str);
void				check_path_exists(t_entry *start, t_entry *end, t_dfs *dfs);
void				exit_dup_coord(t_master *master);
void				exit_no_solution(void);
void				exit_no_path(void);

/*
**	INITIALIZATION
*/

void				init_master(t_master *master);
void				init_link_arr(t_entry **links, int len);
void				init_paths(int len, t_bucket **p);
void				init_entry(t_entry *entry);
void				init_paths_struct(t_paths *paths);

/*
**	FREEING
*/

void				free_entry(t_entry *entry);
void				free_bucket(t_bucket *bucket);
void				delete_old_path(t_bucket **paths);
void				pop_from_list(t_bucket *head);
void				delete_old_ht(t_bucket **old, size_t size);

/*
**	DATA CAPTURING
*/

void				capture_ants(t_master *master, char *line);
void				capture_flags(t_master *master, int ac, char **av);
void				capture_comment(t_master *master, char *str);
void				load_help(t_master *master);
void				validate_coords(t_master *master, char *n1, char *n2);
void				validate_rooms(t_bucket **ht, t_master *master);
void				duplicate_room_check(t_master *master, t_bucket **ht);
void				add_link_to_room(t_bucket **ht, t_master *master,\
					char *line);
t_entry				*copy_entry(t_entry *src);
void				parse_lines(t_master *master, char *line, t_bucket **ht);
t_entry				*get_entry(t_bucket **ht, t_master *master, char *name);
int					link_exists(t_entry **link_arr, t_entry *link);
void				insert_link(t_entry *entry, t_entry *link);
t_entry				**append_link(t_entry **link_arr, t_entry *entry);
t_bucket			*insert_node_to_path(t_bucket *head, t_entry *node);

/*
**	Hash Table Functions
*/

t_bucket			**grow_ht(t_bucket **ht, t_master *master);
t_bucket			**create_ht(t_master *master);
t_bucket			*create_bucket(void);
t_entry				*create_entry(void);
t_entry				*fill_entry_from_line(t_master *master, t_entry *dst,\
					char *line);
float				load(t_master *master);
void				insert_node(t_bucket **ht, t_entry *entry, int index);
void				assign_entry_to_ht(t_bucket **ht, t_master *master,\
					t_entry *entry);
int					gen_key(char *str);

/*
**	Routing Algorithm
*/

void				find_paths(t_master *master, t_bucket **ht);
void				choose_paths(t_master *master, t_paths *paths);
void				choose_wisely(t_paths *paths);
t_bucket			**grow_path_array(t_paths *paths);
void				ants_marching(t_master *master, t_paths *paths);

/*
**	RANDOM TOOLS
*/

void				print_paths(t_bucket **paths);
void				dead_end_scan(t_master *master, t_bucket **ht);
void				start_or_end(char *s, t_master *master, char *name);
int					bucket_arr_len(t_bucket **arr);
int					link_array_len(t_entry **arr);
void				print_ht(t_bucket **ht, size_t size);
t_bucket			*copy_from_array(t_bucket *head, t_bucket *src);
void				max_paths(t_paths *paths);
int					dup_coord(t_bucket **ht, t_master *master, t_entry *entry);

#endif
