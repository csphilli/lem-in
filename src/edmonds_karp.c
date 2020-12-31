/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/31 08:58:54 by cphillip         ###   ########.fr       */
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

void	print_map(t_master *master)
{
	t_pmap *tmp;

	tmp = master->bfs->map;
	while (tmp)
	{
		ft_printf("%s/%s", tmp->fnd->name, tmp->via->name);
		if (tmp->next)
			write(1, ",", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
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
	// ft_printf("----------------------- found flow: ");
	// print_ll(ll);
	// print_map(master);
	// print_ht(ht);
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

int		cap_chk(t_master *master)
{
	t_bucket 	*tmp;
	int			i;

	i = 0;
	tmp = master->start_room->links;
	while (tmp)
	{
		if (tmp->cap - tmp->edge_flow > 0)
			i = 1;
		tmp = tmp->next;
	}
	ft_printf("Cap Check: %d\n", i);
	return (i);
}

void	edmonds_karp(t_bucket **ht, t_master *master)
{
	int	set_id;

	set_id = 0;
	init_caps(ht);
	// reset_data(ht, 1);
	// ft_printf("starting capacities:\n");
	// print_ht(ht);
	
	while (set_id < MAX_SETS)
	// while (cap_chk(master))
	{
		cap_chk(master);
		// print_ht(ht);
		// ft_putnbr(set_id);
		clear_data(ht, master);
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
		// system("leaks lem-in");
		build_paths(ht, master, set_id);
		set_id++;
		// print_ht(ht);
			// create_path_set(master, set_id);
	}
	// ft_printf(" END OF EK\n");
	
		// system("leaks lem-in");
	// ft_error("exiting after EK\n");
		// print_ht(ht);
		
		// ft_error("exiting after 1 pass\n");
	// if (!master->bfs->s2e && !master->bfs->e2s)
	// 	master->flags.errors ? \
	// 	ft_error("ERROR: No solution. No link between start and end.") : \
	// 	ft_error("ERROR");
}

