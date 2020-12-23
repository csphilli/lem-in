/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:52:10 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/23 21:39:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define IO_BUF 1025
# define TABLE_SIZE 20023
// # include "../libft/libft/includes/libft.h"
# include "libft.h"
# include "ft_printf.h"
# include <time.h>

typedef struct		s_flags
{
	bool			s_toggle;
	bool			e_toggle;
	bool			print_paths;
	bool			print_hash_table;
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
	unsigned int	cap;
	unsigned int	flow;
	// struct s_bucket	*res;
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
	t_distro			*paths;
	t_distro			*s2e;
	t_distro			*e2s;
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
}					t_ants;

typedef struct		s_master
{
	t_flags			flags;
	t_ants			*ants;
	t_bfs			*bfs;
	char			*comment;
	t_entry			*start_room;
	t_entry			*end_room;
	int				nbr_ants;	
	int				line_nbr;
	int				link;
	char			*input;
	t_io			*map;
	t_io			*moves;

}					t_master;

/*
**	ERROR HANDLING
*/

void				exit_coord(t_master *master);
void				exit_dup(t_master *master, char *room_name);
void				exit_room_not_found(t_master *master, char *str);
void				exit_dup_coord(t_master *master);
void				ft_error(char *error_msg);

/*
**	INITIALIZATION
*/

void				init_master(t_master *master);
void				init_bfs(t_bfs *bfs, t_master *master);
void				init_instrux(t_ants *instrux);
void				ft_init_int_arr(int *src, int len);
void				init_moves(t_distro *moves);
void				init_caps(t_bucket **ht);
void				init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins);
t_master			*create_structs(void);

/*
**	FREEING
*/

void				free_node(t_bucket *node);
void				free_entry(t_entry *entry);
void				free_bucket(t_bucket *bucket);
void				free_intarray(int *src, int len);

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
void				store_input(t_master *master, char *line, int p);
void				cat_move(t_master *master, int ant_id, char *name);

/*
**	Hash Table Functions
*/


void				capture_room(t_bucket **ht, t_master *master, char *line);
void				insert_node(t_master *master, t_bucket **ht,\
					t_entry *entry, int index);
void				assign_entry_to_ht(t_bucket **ht, t_master *master,\
					t_entry *entry);
int					hash(char *str);
t_bucket			*get_head(t_bucket **ht, char *name);

/*
**	Routing Algorithm
*/

void				find_paths(t_master *master, t_bucket **ht);
void				calc_distro(t_master *master);
void				ants_marching(t_master *master);

/*
**	RANDOM TOOLS
*/

int					validate_input(t_master *master);
void				start_or_end(t_master *master, t_entry *entry);
int					bucket_arr_len(t_bucket **arr);
int					link_array_len(t_entry **arr);
t_bucket			*copy_from_array(t_bucket *head, t_bucket *src);
int					dup_coord(t_bucket **ht,t_entry *entry);
int					list_length(t_bucket *head);
int					*ft_intcat(int *src, int to_add);
int					ft_int_arr_len(int *n);
int					most_ants(int *arr);
int					dupe(t_bucket *head, t_entry *entry);

/*
**	PRINTING
*/

void				print_io(t_io *tgt, int i);
void				print_ll(t_bucket *ll);
void				print_ht(t_bucket **ht);
void				print_int_arr(int *ants);
void				print_distro(t_distro **list);
void				do_one_move(t_master *master);

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

void				unshift_distro(t_distro **lol, t_bucket *ll);
void				insert_to_lol(t_distro **lol, t_bucket *ll);
void				pop_from_lol(t_distro **list);
void				append_to_lol(t_distro **lol, t_bucket *ll);
int					lol_length(t_distro *lol);
void				print_distro(t_distro **list);

/*
**	MAP WORK
*/

void				unshift_to_map(t_pmap **map, t_entry *found, t_entry *via);
void				pop_from_map(t_pmap **map);

/*
** 	EDMONDS KARP AND TOOLS
*/

void				reverse_paths(t_distro **lol);
t_distro				*optimal_solution(t_master *master);
void				build_distro_array(t_master *master);
void				reset_data(t_bucket **ht, int x);
void				edmonds_karp(t_bucket **ht, t_master *master);
// void				adj_cap(t_entry *fnd, t_entry *via, int cap);
void				adj_flows(t_entry *fnd, t_entry *via);
t_bucket			*get_edge(t_entry *fnd, t_entry *via);
void				clear_data(t_bucket **ht, t_master *master, int i);
void				sort_paths(t_distro *paths);
int					chk_direct_link(t_bucket **ht, t_master *master);

t_io				*create_io(void);
void				buf_to_output(t_io **main);

#endif
