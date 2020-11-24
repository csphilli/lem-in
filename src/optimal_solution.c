/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:59:55 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/23 14:33:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		get_min_moves(t_lol *lol)
{
	t_lol 	*tmp;
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

t_lol	*optimal_solution(t_bfs *bfs)
{
	int		min_moves1;
	int		min_moves2;
	
	min_moves1 = get_min_moves(bfs->s2e_paths);
	min_moves2 = get_min_moves(bfs->e2s_paths);
	// ft_printf("starting for s2e: %s\n", bfs->s2e_paths->list->entry->name);
	// ft_printf("starting for e2s: %s\n", bfs->e2s_paths->list->entry->name);
	if (min_moves1 <= min_moves2)
	{
		bfs->max_moves = min_moves1;
		return (bfs->s2e_paths);
	}
	else
	{
		bfs->max_moves = min_moves2;
		return (bfs->e2s_paths);
	}
}