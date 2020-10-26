/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 09:35:31 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/26 09:52:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		list_len(t_bucket *head)
{
	t_bucket	*tmp;
	int			len;

	tmp = head;
	len = 1;
	while (tmp->next)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	get_shortest_path(t_paths *paths)
{
	int			pos;
	int			min;
	int			i;
	int			len;

	pos = 0;
	min = 100000;
	i = 0;
	len = 1;
	while (i < bucket_arr_len(paths->c))
	{
		len = list_len(paths->c[i]);
		if (len <= min)
		{
			min = len;
			pos = i;
		}
		i++;
	}
	paths->shortest_index = pos;
}

// void	move_occupied(t_bucket **paths)
// {
// 	t_bucket	*tmp;
// 	int			len;
// 	int			index;

// 	tmp = NULL;
// 	len = bucket_arr_len(paths);
// 	index = 0;

// }

void	ants_marching(t_master *master, t_paths *paths)
{
	int	i;

	i = 0;
	
	get_shortest_path(paths);
	ft_printf("sp: %d\n", paths->shortest_index);
	ft_printf("random master: %s\n", master->start_room);
	ft_printf("nbr of ants at start: %d\n", paths->s_room->n_ants);
	// print_paths(paths->c);
	// while (master->nbr_ants > 1)
	// {
	// 	move_occupied(paths->c);
	// }
	// while (1)
	// {
		
	// }
}