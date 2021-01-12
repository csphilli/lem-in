/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:29:55 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/12 08:54:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		reset_visited(t_bucket **ht)
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
			tmp = tmp->next;
		}
		i++;
	}
}

void		adj_flows(t_bucket **ht, t_entry *fnd, t_entry *via)
{
	t_bucket	*forward;
	t_bucket	*residual;
	t_bucket	*head;

	forward = get_edge(fnd, via);
	residual = get_edge(via, fnd);
	head = get_head(ht, via->name);
	forward->edge_flow++;
	residual->edge_flow--;
}

void		clear_data(t_bucket **ht, t_master *master)
{
	while (master->bfs->map)
		pop_from_map(&master->bfs->map);
	reset_visited(ht);
	while (master->bfs->q)
		pop_from_ll(&master->bfs->q);
}

int			residual_capacity(t_bucket *head)
{
	return (head->cap - head->edge_flow);
}
