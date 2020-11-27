/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/27 08:49:22 by cphillip         ###   ########.fr       */
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
		master->input = ft_strnew(LINEBUF);
	}
}

void	init_moves(t_lol *moves)
{
	t_lol	*tmp;
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

void	init_caps2(t_bucket *head)
{
	t_bucket	*tmp;
	t_bucket	*links;

	tmp = head;
	while (tmp)
	{
		links = tmp->entry->links;
		while (links)
		{
			links->cap = 1;
			links = links->next;
		}
		tmp = tmp->next;
	}
}

void	init_caps(t_bucket **ht, t_master *master)
{
	t_bucket	*tmp;
	t_bucket	*links;
	size_t		i;

	i = 0;
	tmp = NULL;
	links = NULL;
	while (i < master->new_size)
	{
		if (ht[i])
		{
			tmp = ht[i];
			init_caps2(tmp);
		}
		i++;
	}
}

void	init_ant_ins(t_bfs *bfs, t_master *master, t_ants **ins)
{
	(*ins)->ants_s = master->nbr_ants;
	(*ins)->max_ant = (*ins)->ants_s;
	(*ins)->start = bfs->start;
	(*ins)->end = bfs->end;
	(*ins)->ant_id = 1;
}
