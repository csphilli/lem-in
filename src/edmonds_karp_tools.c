/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/23 23:25:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reset_data(t_bucket **ht)
{
	t_bucket	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	while (i < TABLE_SIZE)
	{
		if (ht[i])
			tmp = ht[i];
		while (tmp)
		{
			tmp->entry->visited = 0;
			// if (x == 1)
			tmp->entry->used = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

// void		adj_flows(t_entry *fnd, t_entry *via)
// {
// 	t_bucket *edge;

// 	edge = get_edge(fnd, via);
// 	edge->cap = cap;
// 	via->used = 1;
// 	edge = get_edge(via, fnd);
// 	edge->cap = cap;
// 	fnd->used = 1;
// }

void		adj_flows(t_entry *fnd, t_entry *via)
{
	t_bucket *edge;

	edge = get_edge(fnd, via);
	edge->flow += 1;
	// via->used = 1;
	edge = get_edge(via, fnd);
	edge->flow -= 1;
	// fnd->used = 1;
}


t_bucket	*get_edge(t_entry *fnd, t_entry *via)
{
	t_bucket	*links;

	links = NULL;
	links = via->links;
	while (links)
	{
		if (ft_strequ(links->entry->name, fnd->name))
			return (links);
		links = links->next;
	}
	return (NULL);
}

void		clear_data(t_bucket **ht, t_master *master)
{
	while (master->bfs->map)
		pop_from_map(&master->bfs->map);
	reset_data(ht);
	while (master->bfs->q)
		pop_from_ll(&master->bfs->q);
}

void		reverse_paths(t_distro **lol)
{
	t_distro		*tmp;
	t_bucket	*newll;
	t_distro		*newlol;

	tmp = *lol;
	newll = NULL;
	newlol = NULL;
	while (tmp->list)
	{
		while (tmp->list)
		{
			unshift_ll(&newll, tmp->list->entry);
			pop_from_ll(&tmp->list);
		}
		append_to_lol(&newlol, newll);
		newll = NULL;
		pop_from_lol(&tmp);
	}
	*lol = newlol;
}
