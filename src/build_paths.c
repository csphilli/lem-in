/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:06:11 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 21:06:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		flow_chk(t_master *master)
{
	t_bucket	*tmp;
	int			flow_count;

	flow_count = 0;
	tmp = master->start_room->links;
	while (tmp)
	{
		if (tmp->edge_flow == 1)
			flow_count++;
		tmp = tmp->next;
	}
	return (flow_count);
}

void	print_path_sets(t_master *master)
{
	int			i;
	int			j;
	t_distro	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (i < MAX_SETS)
	{
		if (master->paths[i] != NULL)
		{
			ft_printf("[SET %d]\n", i);
			tmp = master->paths[i];
			j = 0;
			while (tmp)
			{
				ft_printf("[%d]: ", j);
				print_ll(tmp->list);
				tmp = tmp->next;
				j++;
			}
		}
		i++;
	}
}

void	set_used(t_master *master, int set_id, int toggle)
{
	t_distro	*head;
	t_bucket	*tmp;

	head = master->paths[set_id];
	while (head)
	{
		tmp = head->list;
		while (tmp)
		{
			tmp->entry->used = toggle;
			tmp = tmp->next;
		}
		head = head->next;
	}
}

void	assemble_path(t_master *master, int set_id)
{
	t_bucket	*ll;
	t_pmap		*tmp;
	t_pmap		*cur;

	ll = NULL;
	cur = master->bfs->map;
	tmp = master->bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	cur->via->used = 1;
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			if (!ft_strequ(tmp->via->name, master->start_room->name))
				tmp->via->used = 1;
			if (ft_strequ(tmp->via->name, master->start_room->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	append_to_distro(&master->paths[set_id], ll);
	master->solution = 1;
}

void	build_paths_2(t_bucket **ht, t_master *master, t_bucket *links, int set_id)
{
	while (links)
	{
		if (!links->entry->visited && !links->entry->used && links->cap - links->edge_flow == 0)
		{
			if (ft_strequ(links->entry->name, master->end_room->name))
			{
				unshift_to_map(&master->bfs->map, links->entry, master->bfs->cur);
				assemble_path(master, set_id);
				clear_data(ht, master);
				return ;
			}
			else
			{
				append_to_ll(&master->bfs->q, links->entry);
				unshift_to_map(&master->bfs->map, links->entry, master->bfs->cur);
				links->entry->visited = 1;
			}
		}
		links = links->next;
	}
}

void	build_paths(t_bucket **ht, t_master *master, int set_id)
{
	t_bucket	*tmp;
	int			i;

	i = 0;
	while (i < MAX_SETS)
	{
		append_to_ll(&master->bfs->q, master->start_room);
		while (master->bfs->q)
		{
			master->bfs->cur = master->bfs->q->entry;
			pop_from_ll(&master->bfs->q);
			master->bfs->cur->visited = 1;
			tmp = master->bfs->cur->links;
			build_paths_2(ht, master, tmp, set_id);
		}
		i++;
	}
	set_used(master, set_id, 0);
}