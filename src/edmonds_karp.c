/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:38:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/25 22:25:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// void	map_to_paths(t_master *master, int i)
// {
// 	t_bucket	*ll;
// 	t_pmap		*tmp;
// 	t_pmap		*cur;
// 	t_entry		*goal;

// 	ll = NULL;
// 	cur = master->bfs->map;
// 	tmp = master->bfs->map->next;
// 	goal = (i == 1 ? master->start_room : master->end_room);
// 	append_to_ll(&ll, cur->fnd);
// 	append_to_ll(&ll, cur->via);
// 	adj_cap(cur->fnd, cur->via, 0);
// 	while (tmp)
// 	{
// 		if (ft_strequ(tmp->fnd->name, cur->via->name))
// 		{
// 			append_to_ll(&ll, tmp->via);
// 			adj_cap(tmp->fnd, tmp->via, 0);
// 			if (ft_strequ(tmp->via->name, goal->name))
// 				break ;
// 			cur->via = tmp->via;
// 		}
// 		tmp = tmp->next;
// 	}
// 	i == 1 ? insert_to_lol(&master->bfs->s2e, ll) : insert_to_lol(&master->bfs->e2s, ll);
// }

// int		flow_chk(t_entry *start)
// {
// 	t_bucket *tmp;

// 	tmp = start->links;
// 	while (tmp)
// 	{
// 		if (tmp->flow == 1)
// 			return (1)
// 	}

// }


// void	create_path_set(t_bucket **ht, t_master *master, int set_id)
// {
	
// }

void	augment_flow(t_bucket **ht, t_master *master, int set_id)
{
	t_bucket	*ll;
	t_pmap		*tmp;
	t_pmap		*cur;

	ll = NULL;
	cur = master->bfs->map;
	tmp = master->bfs->map->next;
	append_to_ll(&ll, cur->fnd);
	append_to_ll(&ll, cur->via);
	// adj_flows(cur->fnd, cur->via);
	adj_flows(ht, cur->fnd, cur->via);
	while (tmp)
	{
		if (ft_strequ(tmp->fnd->name, cur->via->name))
		{
			append_to_ll(&ll, tmp->via);
			// adj_flows(tmp->fnd, tmp->via);
			adj_flows(ht, tmp->fnd, tmp->via);
			if (ft_strequ(tmp->via->name, master->start_room->name))
				break ;
			cur->via = tmp->via;
		}
		tmp = tmp->next;
	}
	// create_path_set(ht, master, set_id);

	ft_printf("current path. Set id: %d\n", set_id);
	print_ll(ll);
	print_ht(ht);
	while (ll)
		pop_from_ll(&ll);
}

// void	node_flow_chk(t_master *master, t_entry *node, t_entry *cur)
// {
// 	t_bucket	*links;
// 	// cur is 4:
// 	// links is : 1, 2
// 	links = cur->links;
// 	if (node->node_flow)
// 	{
// 		while (links)
// 		{
// 			if (!links->next)
// 			{
// 				append_to_ll(&master->bfs->q, )
// 			}
// 		}
// 	}
// }


void	find_augment(t_bucket **ht, t_master *master, int set_id)
{
	t_entry		*cur;
	t_bucket	*tmp;
	
	cur = get_entry(ht, master, master->bfs->cur->name);
	tmp = cur->links;
	cur->visited = 1;
	while (tmp)
	{
		if (tmp->cap - tmp->flow > 0)
		{
			if (ft_strequ(tmp->entry->name, master->end_room->name))
			{
				unshift_to_map(&master->bfs->map, tmp->entry, cur);
				augment_flow(ht, master, set_id);
				clear_data(ht, master);
				return ;
			}
			else if (!tmp->entry->visited)
			{
				// node_flow_chk(master, tmp->entry, cur);
				append_to_ll(&master->bfs->q, tmp->entry);
				unshift_to_map(&master->bfs->map, tmp->entry, cur);
				tmp->entry->visited = 1;
			}

		}
		tmp = tmp->next;
	}
}

// void	build_paths2(t_bucket **ht, t_master *master, int i)
// {
// 	t_entry		*cur;
// 	t_bucket	*tmp;
// 	t_entry		*entry;

// 	entry = (i == 1 ? master->end_room : master->start_room);
// 	cur = get_entry(ht, master, master->bfs->cur->name);
// 	tmp = cur->links;
// 	cur->visited = 1;
// 	while (tmp)
// 	{
// 		if (tmp->cap && (ft_strequ(tmp->entry->name, entry->name)))
// 		{
// 			unshift_to_map(&master->bfs->map, tmp->entry, cur);
// 			map_to_paths(master, i);
// 			clear_data(ht, master, 0);
// 			return ;
// 		}
// 		else if (tmp->cap && !tmp->entry->visited && !tmp->entry->used)
// 		{
// 			append_to_ll(&master->bfs->q, tmp->entry);
// 			unshift_to_map(&master->bfs->map, tmp->entry, cur);
// 		}
// 		tmp = tmp->next;
// 	}
// }


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
	// int		len;
	// t_entry	*entry;
	int	set_id;

	// entry = (i == 1 ? master->start_room : master->end_room);
	// len = list_length(entry->links);
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
			find_augment(ht, master, set_id);
		}
	}
		// print_ht(ht);
		
		system("leaks lem-in");
		ft_error("exiting after 1 pass\n");
	// if (!master->bfs->s2e && !master->bfs->e2s)
	// 	master->flags.errors ? \
	// 	ft_error("ERROR: No solution. No link between start and end.") : \
	// 	ft_error("ERROR");
}

// void	edmonds_karp2(t_bucket **ht, t_master *master, int i)
// {
// 	int		len;
// 	t_entry	*entry;

// 	entry = (i == 1 ? master->start_room : master->end_room);
// 	// len = list_length(entry->links);
// 	init_caps(ht);
// 	reset_data(ht, 1);
// 	while (len--)
// 	{
// 		append_to_ll(&master->bfs->q, entry);
// 		while (master->bfs->q)
// 		{
// 			master->bfs->cur = master->bfs->q->entry;
// 			pop_from_ll(&master->bfs->q);
// 			build_paths2(ht, master, i);
// 		}
// 	}
// 	if (!master->bfs->s2e && !master->bfs->e2s)
// 		master->flags.errors ? \
// 		ft_error("ERROR: No solution. No link between start and end.") : \
// 		ft_error("ERROR");
// }


// void	edmonds_karp(t_bucket **ht, t_master *master)
// {
// 	edmonds_karp2(ht, master, 0);
// 	reverse_paths(&master->bfs->e2s);
// 	edmonds_karp2(ht, master, 1);
// }

// void	edmonds_karp(t_bucket **ht, t_master *master)
// {
// 	edmonds_karp2(ht, master);
	
// 	// reverse_paths(&master->bfs->e2s);
// 	// edmonds_karp2(ht, master, 1);
// }
