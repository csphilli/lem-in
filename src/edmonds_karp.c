/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/27 21:01:41 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		shared_flow(t_bucket *links, t_entry *tgt)
{
	// ft_printf("tgt: %s | looking in: ", tgt->name);
	// print_ll(links);
	while (links)
	{
		if (ft_strequ(links->entry->name, tgt->name))
			return (1);
		links = links->next;
	}
	return (0);
}

int		node_flow_chk(t_master *master)
{
	t_bucket *tmp;

	tmp = master->bfs->cur->links;
	
	// ft_printf("NFC: %s->links: ", master->bfs->cur->name);
	// print_ll(tmp);
	while (tmp)
	{
		if (!tmp->entry->visited)
		{
			// ft_printf("examining: %s ", tmp->entry->name);
			// if (tmp->entry->flow_to)
			// 	ft_printf("| flow_to: %s\n", tmp->entry->flow_to->name);
			// else
			// 	write(1, "\n", 1);
			if (!tmp->entry->flow_to || (tmp->entry->flow_to && \
			!shared_flow(master->bfs->cur->links, tmp->entry->flow_to)))
			{
				if (!ft_strequ(master->end_room->name, tmp->entry->name))
					tmp->entry->visited = 1;
				return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

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
	// ft_printf("found flow: ");
	// print_ll(ll);
	// print_ht(ht);
	while (ll)
		pop_from_ll(&ll);
}

void	find_augment(t_bucket **ht, t_master *master)
{
	// t_entry		*cur;
	t_bucket	*tmp;
	
	// cur = get_entry(ht, master, master->bfs->cur->name);
	// tmp = cur->links;
	tmp = master->bfs->cur->links;
	// cur->visited = 1;
	master->bfs->cur->visited = 1;
	while (tmp)
	{
		// ft_printf("cur: %s\n", master->bfs->cur->name);
		if (tmp->cap - tmp->flow > 0 && !tmp->entry->visited)
		{
			// ft_printf("%s flow satisfied\n", tmp->entry->name);
			if (ft_strequ(tmp->entry->name, master->end_room->name))
			{
				// ft_printf("found end room\n");
				// unshift_to_map(&master->bfs->map, tmp->entry, cur);
				unshift_to_map(&master->bfs->map, tmp->entry, master->bfs->cur);
				augment_flow(ht, master);
				clear_data(ht, master);
				return ;
			}
			// else if (node_flow_chk(master))
			else
			{
				// ft_printf("adding %s\n", tmp->entry->name);
				append_to_ll(&master->bfs->q, tmp->entry);
				// unshift_to_map(&master->bfs->map, tmp->entry, cur);
				unshift_to_map(&master->bfs->map, tmp->entry, master->bfs->cur);
				// tmp->entry->visited = 1;
			}
		}
		tmp = tmp->next;
	}
}

// int		cap_chk(t_master *master)
// {
// 	t_bucket 	*tmp;
// 	int			i;

// 	i = 0;
// 	tmp = master->start_room->links;
// 	while (tmp)
// 	{
// 		if (tmp->cap - tmp->flow > 0)
// 			i = 1;
// 		tmp = tmp->next;
// 	}
// 	return (i);
// }

void	edmonds_karp(t_bucket **ht, t_master *master)
{
	int	set_id;

	set_id = 0;
	init_caps(ht);
	// reset_data(ht, 1);
	// ft_printf("starting capacities:\n");
	// print_ht(ht);
	// while (cap_chk(master->start_room))
	while (set_id < MAX_SETS)
	{
		// print_ht(ht);
		append_to_ll(&master->bfs->q, master->start_room);
		while (master->bfs->q)
		{
			// ft_printf("Q: ");
			// print_ll(master->bfs->q);
			master->bfs->cur = master->bfs->q->entry;
			pop_from_ll(&master->bfs->q);
			// build_paths2(ht, master);
			find_augment(ht, master);
		}
		build_paths(ht, master, set_id);
		set_id++;
			// create_path_set(master, set_id);
	}
	// ft_error("exiting after EK\n");
		// print_ht(ht);
		
		// system("leaks lem-in");
		// ft_error("exiting after 1 pass\n");
	// if (!master->bfs->s2e && !master->bfs->e2s)
	// 	master->flags.errors ? \
	// 	ft_error("ERROR: No solution. No link between start and end.") : \
	// 	ft_error("ERROR");
}

