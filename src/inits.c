/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 14:14:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_master(t_master *master)
{
	if (master)
	{
		master->flags.s_toggle = false;
		master->flags.e_toggle = false;
		master->flags.print_hash_table = false;
		master->flags.print_paths = false;
		master->flags.vis_distro = false;
		master->flags.accepted_flags = "dhpte";
		master->line_nbr = 1;
		master->table_size = TABLE_SIZE;
		// master->load = 5.0;
		// master->size_factor = 2;
		// master->old_size = 21;
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

// void	init_caps(t_bucket **ht, t_master *master)
void	init_caps(t_bucket **ht)
{
	t_bucket	*tmp;
	t_bucket	*links;
	size_t		i;

	i = 0;
	tmp = NULL;
	links = NULL;
	while (i < TABLE_SIZE)
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
