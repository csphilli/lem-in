/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 13:00:25 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 16:01:02 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_paths(t_master *master)
{
	t_distro	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_printf(UCYN"\nSOLUTION SETS\n"RESET);
	ft_printf(BGRN"GREEN"RESET" = best\n");
	ft_printf("note: paths are in reverse order\n\n");
	while (i < MAX_SETS)
	{
		if (i == master->best_set)
			ft_printf(BGRN);
		ft_printf("SET [%d]\n", i);
		tmp = master->paths[i];
		j = 0;
		while (tmp)
		{
			ft_printf(" [%d]: ", j++);
			print_ll(tmp->list);
			tmp = tmp->next;
		}
		ft_printf(RESET);
		i++;
	}
}

void	clear_moves(t_master *master)
{
	t_distro	*tmp;

	tmp = master->paths[master->best_set];
	while (tmp)
	{
		tmp->nbr_ants = 0;
		tmp->total_moves = 0;
		tmp->done = 0;
		tmp = tmp->next;
	}
}

void	print_cascade(t_master *master)
{
	t_distro	*tmp;
	int			max_index;
	int			ants;

	max_index = 0;
	ants = master->nbr_ants;
	tmp = master->paths[master->best_set];
	clear_moves(master);
	while (ants > 0)
	{
		system("clear");
		tmp->nbr_ants++;
		ants--;
		tmp->total_moves = tmp->nbr_ants + tmp->cap - 1;
		if (tmp->nbr_ants == tmp->unlock && !tmp->done)
		{
			max_index++;
			tmp->done = 1;
		}
		tmp = (tmp->index == max_index ? \
			master->paths[master->best_set] : tmp->next);
		print_distro(&master->paths[master->best_set]);
		usleep(100000);
	}
}
