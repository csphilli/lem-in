/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:59:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/23 20:42:19 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_min_moves(t_distro *lol)
{
	t_distro	*tmp;
	int		min;

	tmp = lol;
	min = 0;
	while (tmp)
	{
		if (tmp->total_moves >= min && tmp->nbr_ants > 0)
			min = tmp->total_moves;
		tmp = tmp->next;
	}
	return (min);
}

t_distro	*optimal_solution(t_master *master)
{
	int		min_moves1;
	int		min_moves2;

	min_moves1 = get_min_moves(master->bfs->s2e);
	min_moves2 = get_min_moves(master->bfs->e2s);
	if (min_moves1 <= min_moves2)
	{
		master->bfs->max_moves = min_moves1;
		return (master->bfs->s2e);
	}
	else
	{
		master->bfs->max_moves = min_moves2;
		return (master->bfs->e2s);
	}
}