/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_path_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 13:34:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	reset_visited(t_bucket **ht, t_master *master)
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
			tmp = tmp->next;
		}
		i++;
	}
}

void	adj_cap(t_entry *fnd, t_entry *via, int cap)
{
	t_bucket *edge;

	edge = get_edge(fnd, via);
	edge->cap = cap;
	via->used = 1;
}

t_bucket 	*get_edge(t_entry *fnd, t_entry *via)
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

void	clear_data(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	while (bfs->map)
		pop_from_map(&bfs->map);
	reset_visited(ht, master);
	while (bfs->q)
		pop_from_ll(&bfs->q);
}
