/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/27 00:56:08 by cphillip         ###   ########.fr       */
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
	print_ll(ll);
	print_ht(ht);
	while (ll)
		pop_from_ll(&ll);
}

void	find_augment(t_bucket **ht, t_master *master)
{
	t_entry		*cur;
	t_bucket	*tmp;
	
	cur = get_entry(ht, master, master->bfs->cur->name);
	tmp = cur->links;
	cur->visited = 1;
	while (tmp)
	{
		if (tmp->cap - tmp->flow > 0 && !tmp->entry->visited)
		{
			if (ft_strequ(tmp->entry->name, master->end_room->name))
			{
				unshift_to_map(&master->bfs->map, tmp->entry, cur);
				augment_flow(ht, master);
				clear_data(ht, master);
				return ;
			}
			else
			{
				append_to_ll(&master->bfs->q, tmp->entry);
				unshift_to_map(&master->bfs->map, tmp->entry, cur);
				tmp->entry->visited = 1;
			}
		}
		tmp = tmp->next;
	}
}

int		cap_chk(t_entry *start)
{
	t_bucket *tmp;

	tmp = start->links;
	while (tmp)
	{
		if (tmp->cap - tmp->flow > 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	edmonds_karp(t_bucket **ht, t_master *master)
{
	int	set_id;

	set_id = 0;
	init_caps(ht);
	// reset_data(ht, 1);
	ft_printf("starting capacities:\n");
	print_ht(ht);
	while (cap_chk(master->start_room))
	{
		append_to_ll(&master->bfs->q, master->start_room);
		while (master->bfs->q)
		{
			ft_printf("Q: ");
			print_ll(master->bfs->q);
			master->bfs->cur = master->bfs->q->entry;
			pop_from_ll(&master->bfs->q);
			// build_paths2(ht, master);
			find_augment(ht, master);
		}
		build_paths(ht, master, set_id);
			// create_path_set(master, set_id);
	}
		// print_ht(ht);
		
		// system("leaks lem-in");
		ft_error("exiting after 1 pass\n");
	// if (!master->bfs->s2e && !master->bfs->e2s)
	// 	master->flags.errors ? \
	// 	ft_error("ERROR: No solution. No link between start and end.") : \
	// 	ft_error("ERROR");
}

