/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 15:13:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reset_data(t_bucket **ht, t_master *master, int x)
{
	t_bucket	*tmp;
	size_t		i;

	i = 0;
	tmp = NULL;
	while (i < master->new_size)
	{
		if (ht[i])
			tmp = ht[i];
		while (tmp)
		{
			tmp->entry->visited = 0;
			if (x == 1)
				tmp->entry->used = 0;
			tmp = tmp->next;
		}
		i++;
	}
}

void		adj_cap(t_entry *fnd, t_entry *via, int cap)
{
	t_bucket *edge;

	edge = get_edge(fnd, via);
	edge->cap = cap;
	via->used = 1;
	edge = get_edge(via, fnd);
	edge->cap = cap;
	fnd->used = 1;
}

t_bucket	*get_edge(t_entry *fnd, t_entry *via)
{
	t_bucket 	*links;

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

void		clear_data(t_bucket **ht, t_master *master, t_bfs *bfs, int i)
{
	while (bfs->map)
		pop_from_map(&bfs->map);
	reset_data(ht, master, i);
	while (bfs->q)
		pop_from_ll(&bfs->q);
}

void		reverse_paths(t_lol **lol)
{
	t_lol 		*tmp;
	t_bucket	*newll;
	t_lol		*newlol;

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
