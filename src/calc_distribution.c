/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distribution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:03:49 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/27 18:18:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	calc_total_moves(t_master *master, t_distro *paths, int set_id)
{
	// ft_printf("best set: %d\n", master->best_set);
	t_distro 	*tmp;
	int			max;
	static int	min;

	max = 0;
	tmp = paths;
	while (tmp)
	{
		tmp->total_moves = tmp->nbr_ants + tmp->cap - 1;
		// ft_printf("tmp->total moves; %d\n", tmp->total_moves);
		if (tmp->total_moves > max)
			max = tmp->total_moves;
		tmp->ants_left = tmp->nbr_ants;
		tmp = tmp->next;
	}
	// print_distro(&master->paths);
	// ft_printf("set_id: %d | min: %d | max: %d\n", set_id, min, max);
	if (max > 0)
	{
		if (min == 0)
			min = max;
		else if (max < min)
		{
			min = max;
			master->best_set = set_id;
		}
	}
}

void	chk_unlock(t_master **master, t_distro **tmp)
{
	if ((*tmp)->nbr_ants == (*tmp)->unlock && !(*tmp)->done)
	{
		(*master)->bfs->max_index++;
		(*tmp)->done = 1;
	}
}

void	cascade(t_master *master, t_distro *paths, int set_id)
{
	t_distro	*tmp;
	int		ant_count;

	tmp = paths;
	ant_count = master->nbr_ants;
	while (tmp && ant_count > 0)
	{
		while (tmp->index <= master->bfs->max_index && ant_count > 0)
		{
			tmp->nbr_ants++;
			ant_count--;
			chk_unlock(&master, &tmp);
			if (master->flags.vis_distro)
			{
				system("clear");
				print_distro(&paths);
				calc_total_moves(master, paths, set_id);
				usleep(100000);
			}
			tmp = (tmp->index == master->bfs->max_index ? paths : tmp->next);
		}
		tmp = paths;
	}
}

void	unlocks(t_master *master, t_distro *paths)
{
	t_distro	*tmp;

	tmp = paths;
	master->bfs->max_index = 0;
	while (tmp)
	{
		if (tmp->next)
			tmp->unlock = tmp->next->len - tmp->len + 1;
		else
			tmp->unlock = 2147483647;
		tmp = tmp->next;
	}
}

void	calc_distro(t_master *master)
{
	t_distro	*moves;
	int			*arr;
	int			i;

	arr = NULL;
	i = 0;
	moves = NULL;
	while (i < MAX_SETS)
	{
		// ft_printf("set: %d\n", i);
		moves = master->paths[i];
		init_moves(moves);
		unlocks(master, moves);
		cascade(master, moves, i);
		calc_total_moves(master, moves, i);
		// print_distro(&master->paths[i]);
		i++;
		// ft_printf("\nchecking new set\n");
	}
	// ft_printf("best set id: %d\n", master->best_set);
}

// void	calc_distro(t_master *master)
// {
// 	t_distro	*moves;
// 	int		*arr;
// 	int		i;

// 	arr = NULL;
// 	i = 0;
// 	moves = NULL;
// 	while (i < 2)
// 	{
// 		moves = (i == 1 ? master->bfs->s2e : master->bfs->e2s);
// 		init_moves(moves);
// 		unlocks(master, moves);
// 		cascade(master, moves);
// 		calc_total_moves(moves);
// 		i++;
// 	}
// }

