/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 21:05:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	print_map(t_master *master) // Not needed
// {
// 	t_pmap *tmp;

// 	tmp = master->bfs->map;
// 	while (tmp)
// 	{
// 		ft_printf("%s/%s", tmp->fnd->name, tmp->via->name);
// 		if (tmp->next)
// 			write(1, ",", 1);
// 		tmp = tmp->next;
// 	}
// 	write(1, "\n", 1);
// }

void	augment_flow(t_bucket **ht, t_master *master)
{
	t_bucket	*ll;
	t_pmap		*tmp;
	t_pmap		*cur;

	ll = NULL;
	cur = master->bfs->map;
	tmp = master->bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	adj_flows(ht, cur->fnd, cur->via);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			adj_flows(ht, tmp->fnd, tmp->via);
			if (ft_strequ(tmp->via->name, master->start_room->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	while (ll)
		pop_from_ll(&ll);
}

int		mapping(t_master *master, t_bucket *head)
{
	unshift_to_map(&master->bfs->map, head->entry,\
	master->bfs->cur);
	if (!ft_strequ(master->end_room->name, head->entry->name))
		head->entry->visited = 1;
	if (ft_strequ(head->entry->name, master->end_room->name))
		return (1);
	return (0);
}

void	find_augment(t_bucket **ht, t_master *master)
{
	t_bucket	*links;

	links = master->bfs->cur->links;
	master->bfs->cur->visited = 1;
	while (links)
	{
		if (!links->entry->visited && links->cap - links->edge_flow > 0)
		{
			append_to_ll(&master->bfs->q, links->entry);
			if (mapping(master, links))
			{
				augment_flow(ht, master);
				clear_data(ht, master);
				return ;
			}
		}
		links = links->next;
	}
}

void	edmonds_karp(t_bucket **ht, t_master *master)
{
	int	set_id;

	set_id = 0;
	init_caps(ht);
	while (set_id < MAX_SETS)
	{
		clear_data(ht, master);
		append_to_ll(&master->bfs->q, master->start_room);
		while (master->bfs->q)
		{
			master->bfs->cur = master->bfs->q->entry;
			pop_from_ll(&master->bfs->q);
			find_augment(ht, master);
		}
		// build_paths(ht, master, set_id);
		build_paths(ht, master, set_id);
		set_id++;
	}
}
