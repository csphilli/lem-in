/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/02 21:34:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define LINEBUF 1000
// # define E_NO_ROOMS "ERROR: No rooms specified.\n"
// # define E_NO_LINKS "ERROR: No links specified.\n"
// # define E_L "ERROR: 'L' present at beginning of room name.\n"
// # define E_COORD "ERROR: Coordinate must be digiton line "
// # define E_DUPL "ERROR: Duplicate room name found: "
// # define E_FLAG "ERROR: Invalid flag specified.\n"
// # define E_FAILED_SEARCH "ERROR: Couldn't insert link. Room not found: "
// # define E_NOSOLUTION "ERROR: No Solution. Start and/or End room undefined."
# include "../libft/libft/includes/libft.h"
# include <time.h>

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

typedef struct		s_output
{
	char			*line;
	int				len;
	struct s_output	*next;
}					t_output;

typedef struct		s_bucket
{
	char			*input;
	struct s_entry	*entry;
	unsigned int	cap;
	struct s_bucket	*next;
}					t_bucket;

typedef struct		s_entry
{
	char			*name;
	char			*comment;
	t_bucket		*links;
	int				x;
	int				y;
	int				key;
	int				visited;
	int				used;
	int				occ;
	int				ant_id;
}					t_entry;

typedef struct		s_lol
{
	int				total_moves;
	int				len;
	int				ants_left;
	int				nbr_ants;
	int				unlock;
	int				done;
	int				cap;
	int				index;
	t_bucket		*list;
	struct s_lol	*next;
}					t_lol;

typedef struct		s_pmap
{
	t_entry			*fnd;
	t_entry			*via;
	struct s_pmap	*next;
}					t_pmap;

typedef struct		s_bfs
{
	t_bucket		*q;
	t_pmap			*map;
	t_lol			*paths;
	t_lol			*s2e;
	t_lol			*e2s;
	int				*s_distro;
	int				*moves;
	t_bucket		*edge;
	t_entry			*cur;
	t_entry			*start;
	t_entry			*end;
	int				max_index;
	int				max_moves;
}					t_bfs;

typedef struct		s_ants
{
	t_entry			*start;
	t_entry			*end;
	int				ants_s;
	int				ants_e;
	int				max_ant;
	int				n_moves;
	int				ant_id;
	int				i;
	char			*input;
	t_output		*output;
	int				l;
}					t_ants;

/*
**	**p = all PATHS found from initial DFS
**	**c = CHOSEN paths from the DFS.
*/

typedef struct		s_master
{
	char			*comment;
	bool			s_toggle;
	bool			e_toggle;
	t_entry			*start_room;
	t_entry			*end_room;
	bool			print_paths;
	bool			print_hash_table;
	bool			vis_distro;
	bool			ants_added;
	bool			errors;
	int				nbr_ants;
	int				has_flags;
	int				line_nbr;
	char			*input_flags;
	char			*accepted_flags;
	int				flag_count;
	int				room_count;
	size_t			new_size;
	size_t			old_size;
	size_t			size_factor;
	float			load;
	int				nbr_keys;
	int				link;
	char			*input;
	int				l;
	t_output		*output;

}					t_master;

/*
**	ERROR HANDLING
*/

void				exit_coord(t_master *master);
void				exit_dup(t_master *master, char *room_name);
void				exit_room_not_found(t_master *master, char *str);
void				exit_dup_coord(t_master *master);

/*
**	INITIALIZATION
*/

void				init_master(t_master *master);
void				init_bfs(t_bfs *bfs, t_master *master);
void				init_instrux(t_ants *instrux);
void				ft_init_int_arr(int *src, int len);
void				init_moves(t_lol *moves);
void				init_caps(t_bucket **ht, t_master *master);
void				init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins);

/*
**	FREEING
*/

void				free_node(t_bucket *node);
void				free_entry(t_entry *entry);
void				free_bucket(t_bucket *bucket);
void				free_intarray(int *src, int len);
void				delete_old_ht(t_bucket **old, size_t size);

/*
**	DATA CAPTURING
*/

void				capture_ants(t_master *master, char *line);
void				capture_flags(t_master *master, int ac, char **av);
void				capture_comment(t_master *master, char *str);
void				load_help(void);
void				validate_coords(t_master *master, char *n1, char *n2);
void				validate_rooms(t_bucket **ht, t_master *master);
void				duplicate_room_check(t_master *master, t_bucket **ht);
void				capture_links(t_bucket **ht, t_master *master, char *line);
void				parse_lines(t_master *master, char *line, t_bucket **ht);
t_entry				*get_entry(t_bucket **ht, t_master *master, char *name);
void				append_to_output(t_master *master, t_output **output);
void				store_input(t_master *master, char *line, int p);
void				cat_move(t_ants *ins, int ant_id, char *name);
void				append_move(t_ants *ins, t_output **output);

/*
**	Hash Table Functions
*/

t_bucket			**grow_ht(t_bucket **ht, t_master *master);
t_bucket			**create_ht(t_master *master);
void				capture_room(t_bucket **ht, t_master *master, char *line);
float				load(t_master *master);
void				insert_node(t_master *master, t_bucket **ht, t_entry *entry, int index);
void				assign_entry_to_ht(t_bucket **ht, t_master *master,\
					t_entry *entry);
int					gen_key(char *str);
t_bucket			*get_head(t_bucket **ht, t_master *master, char *name);

/*
**	Routing Algorithm
*/

void				find_paths(t_master *master, t_bucket **ht);
void				calc_distro(t_master *master, t_bfs *bfs);
void				ants_marching(t_bfs *bfs, t_master *master);
void				write_r2r(t_ants *ins, t_entry *entry1, t_entry *entry2);
void				write_r2e(t_ants *ins, t_entry *entry1, t_entry *entry2);
void				write_s2r(t_ants *ins, t_entry *entry1);

/*
**	RANDOM TOOLS
*/

int					dupe(t_bucket **head, t_entry *entry);
int					validate_input(t_master *master);
void				start_or_end(t_master *master, t_entry *entry);
int					bucket_arr_len(t_bucket **arr);
int					link_array_len(t_entry **arr);
t_bucket			*copy_from_array(t_bucket *head, t_bucket *src);
int					dup_coord(t_bucket **ht, t_master *master,\
					t_entry *entry);
int					list_length(t_bucket *head);
int					*ft_intcat(int *src, int to_add);
int					ft_int_arr_len(int *n);
int					most_ants(int *arr);

/*
**	PRINTING
*/

void				print_ht(t_bucket **ht, size_t size);
void				print_int_arr(int *ants);
void				print_distro(t_lol **list);
void				print_output(t_output *output);
void				print_moves(t_output *output);

/*
**	LINK WORK
*/

void				unshift_ll(t_bucket **ll, t_entry *entry);
void				insert_to_ll(t_bucket **src, t_entry *entry);
void				pop_from_ll(t_bucket **ll);
void				append_to_ll(t_bucket **src, t_entry *entry);
void				copy_ll(t_bucket **dst, t_bucket *src);
void				reverse_ll(t_bucket **new, t_bucket *list);

/*
**	LIST OF LIST WORK
*/

void				unshift_lol(t_lol **lol, t_bucket *ll);
void				insert_to_lol(t_lol **lol, t_bucket *ll);
void				pop_from_lol(t_lol **list);
void				append_to_lol(t_lol **lol, t_bucket *ll);
int					lol_length(t_lol *lol);
void				print_lol(t_lol **list);

/*
**	MAP WORK
*/

void				unshift_to_map(t_pmap **map, t_entry *found, t_entry *via);
void				pop_from_map(t_pmap **map);

/*
** 	EDMONDS KARP AND TOOLS
*/

void				reverse_paths(t_lol **lol);
t_lol				*optimal_solution(t_bfs *bfs);
void				build_distro_array(t_bfs *bfs);
void				reset_data(t_bucket **ht, t_master *master, int x);
void				edmonds_karp(t_bucket **ht, t_master *master, t_bfs **bfs);
void				adj_cap(t_entry *fnd, t_entry *via, int cap);
t_bucket			*get_edge(t_entry *fnd, t_entry *via);
void				clear_data(t_bucket **ht, t_master *master, \
					t_bfs *bfs, int i);
void				sort_paths(t_lol *paths);
int					chk_direct_link(t_bucket **ht, t_master *master, \
					t_bfs *bfs, int i);

#endif
