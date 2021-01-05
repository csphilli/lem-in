/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/05 22:41:48 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

int		ek_bfs(t_bucket **ht, t_master *master)
{
	t_bucket	*links;

	append_to_ll(&master->bfs->q, master->start_room);
	while (master->bfs->q)
	{
		master->bfs->cur = master->bfs->q->entry;
		pop_from_ll(&master->bfs->q);
		links = master->bfs->cur->links;
		while (links)
		{
			if (!links->entry->visited && residual_capacity(links))
			{
				append_to_ll(&master->bfs->q, links->entry);
				if (mapping(master, links))
				{
					augment_flow(ht, master);
					clear_data(ht, master);
					return (1);
				}
			}
			links = links->next;
		}
	}
	return (0);
}

void	edmonds_karp(t_bucket **ht, t_master *master)
{
	int	set_id;
	int	ret;

	ret = 1;
	set_id = 0;
	init_caps(ht);
	while (ret && set_id < MAX_SETS)
	{
		clear_data(ht, master);
		ret = ek_bfs(ht, master);
		if (ret)
		{
			build_paths(ht, master, set_id);
			set_id++;
		}
	}
}
