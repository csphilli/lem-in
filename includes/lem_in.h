/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/03 20:46:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define IO_BUF 1025
# define TABLE_SIZE 20023
# define MAX_SETS 30
# include "libft.h"
# include "ft_printf.h"
# include <time.h>
# include <stdbool.h>

typedef struct		s_flags
{
	bool			s_toggle;
	bool			e_toggle;
	bool			print_paths;
	bool			print_hash_table;
	bool			print_input;
	bool			print_time;
	bool			leak_check;
	bool			vis_distro;
	bool			ants_added;
	bool			errors;
	char			*input_flags;
	char			*accepted_flags;
	int				flag_count;
	int				has_flags;
}					t_flags;

typedef struct		s_io
{
	char			*buf;
	int				b_len;
	char			*output;
	int				o_len;
	struct s_io		*next;
}					t_io;

typedef struct		s_bucket
{
	char			*input;
	struct s_entry	*entry;
	int				cap;
	int				edge_flow;
	struct s_bucket	*next;
}					t_bucket;

typedef struct		s_entry
{
	char			*name;
	char			*comment;
	t_bucket		*links;
	int				x;
	int				y;
	int				visited;
	int				used;
	int				occ;
	int				ant_id;
	int				node_flow;
}					t_entry;

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
}					t_ants;

typedef struct		s_distro
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
	struct s_distro	*next;
}					t_distro;

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
	t_distro		*paths;
	int				*s_distro;
	int				*moves;
	t_bucket		*edge;
	t_entry			*cur;
	t_entry			*start;
	t_entry			*end;
	int				max_index;
	int				max_moves;
}					t_bfs;

typedef struct		s_master
{
	t_flags			flags;
	t_ants			*ants;
	t_bfs			*bfs;
	t_distro		**paths;
	char			*comment;
	t_entry			*start_room;
	t_entry			*end_room;
	int				direct;
	int				a_room;
	int				solution;
	int				best_set;
	int				nbr_ants;
	int				phase;
	int				link;
	char			*input;
	t_io			*map;
	t_io			*moves;
}					t_master;

/*
**	INITIALIZATIONS
*/

void				init_master(t_master *master);
void				init_bfs(t_bfs *bfs, t_master *master);
t_io				*create_io(void);
void				ft_init_int_arr(int *src, int len);
void				init_moves(t_distro *moves);
void				init_caps(t_bucket **ht);
void				init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins);
t_master			*create_structs(void);
void				init_instrux(t_ants *instrux);

/*
**	DATA CAPTURING
*/

int					capture_ants(t_master *master, char *line);
void				capture_flags(t_master *master, int ac, char **av);
void				capture_comment(t_master *master, char *str);
void				capture_links(t_bucket **ht, t_master *master, char *line);
void				parse_lines(t_master *master, char *line, t_bucket **ht);
void				store_input(t_master *master, char *line, int p);
int					capture_room(t_bucket **ht, t_master *master, char *line);
void				buf_to_output(t_io **main);
void				parse_phase(t_bucket **ht, t_master *master, char *line);
void				valid_room_name(char *name);
void				room_name_parse(t_master *master, char *line);

/*
**	Hash Table Functions
*/

void				insert_node(t_bucket **ht, t_entry *entry, int index);
void				assign_entry_to_ht(t_bucket **ht, t_master *master,\
					t_entry *entry);
int					hash(char *str);
t_bucket			*get_head(t_bucket **ht, char *name);
t_bucket			*get_edge(t_entry *fnd, t_entry *via);
t_entry				*get_entry(t_bucket **ht, char *name);

/*
**	ANTS MARCHING ALGO
*/

void				calc_distro(t_master *master);
void				ants_marching(t_master *master);
void				pop_from_distro(t_distro **list);
void				append_to_distro(t_distro **distro, t_bucket *ll);
int					distro_length(t_distro *distro);
int					most_ants(int *arr);
void				cat_move(t_master *master, int ant_id, char *name);

/*
**	RANDOM TOOLS
*/

int					validate_input(t_master *master);
void				start_or_end(t_master *master, t_entry *entry);
int					bucket_arr_len(t_bucket **arr);
int					link_array_len(t_entry **arr);
int					list_length(t_bucket *head);
int					*ft_intcat(int *src, int to_add);
int					ft_int_arr_len(int *n);
void				load_help(void);
int					solvable(t_master *master);
int					split_len(char **src);

/*
**	PRINTING
*/

void				print_io(t_io *tgt, int i);
void				print_ll(t_bucket *ll);
void				print_ht(t_bucket **ht);
void				print_distro(t_distro **list);
void				print_paths(t_master *master);
void				print_cascade(t_master *master);

/*
**	LINK WORK
*/

void				insert_to_ll(t_bucket **src, t_entry *entry);
void				pop_from_ll(t_bucket **ll);
void				append_to_ll(t_bucket **src, t_entry *entry);

/*
**	MAP WORK
*/

void				unshift_to_map(t_pmap **map, t_entry *found, t_entry *via);
void				pop_from_map(t_pmap **map);

/*
** 	EDMONDS KARP AND BUILDING PATHS
*/

void				build_distro_array(t_master *master);
void				find_paths(t_master *master, t_bucket **ht);
void				edmonds_karp(t_bucket **ht, t_master *master);
void				adj_flows(t_bucket **ht, t_entry *fnd, t_entry *via);
void				clear_data(t_bucket **ht, t_master *master);
int					direct_link(t_bucket **ht, t_master *master);
void				build_paths(t_bucket **ht, t_master *master, int set_id);

#endif
