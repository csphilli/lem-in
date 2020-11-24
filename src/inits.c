/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/23 09:06:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_master(t_master *master)
{
	if (master)
	{
		master->s_toggle = false;
		master->e_toggle = false;
		master->print_hash_table = false;
		master->print_paths = false;
		master->vis_distro = false;
		master->accepted_flags = "dhptl";
		master->line_nbr = 1;
		master->new_size = 10;
		master->load = 5.0;
		master->size_factor = 2;
		master->old_size = 10;
	}
}



// void	init_paths(int len, t_bucket **paths)
// {
// 	while (--len >= 0)
// 		paths[len] = NULL;
// }

// void	init_entry(t_entry *entry) // uneeded after changing to ft_memalloc
// {
// 	if (entry)
// 	{
// 		entry->visited = false;
// 		entry->name = NULL;
// 		entry->comment = NULL;
// 		entry->link_arr = NULL;
// 		entry->x = '\0';
// 		entry->y = '\0';
// 		entry->key = '\0';
// 		entry->occ = 0;
// 		entry->ant_id = 0;
// 		entry->no = false;
// 	}
// }

// void	init_paths_struct(t_paths *paths)
// {
// 	if (paths)
// 	{
// 		paths->p = NULL;
// 		paths->c = NULL;
// 		paths->s_room = NULL;
// 		paths->e_room = NULL;
// 		paths->index = 0;
// 		paths->max_paths = 0;
// 		paths->p_len = 2000000;
// 		paths->c_len = 2;
// 		paths->s_index = '\0';
// 		paths->collision = 0;
// 		paths->nbr_moves = 0;
// 		paths->nbr_ants_s = 0;
// 		paths->nbr_ants_e = 0;
// 		paths->max_id = 0;
// 		paths->ant_id = 1;
// 	}
// }

void		init_moves(t_lol *moves)
{
	t_lol *tmp;
	int		i;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			tmp = tmp->next;
			i++;
		}
	}
}

