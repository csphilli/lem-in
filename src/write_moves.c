/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/28 09:44:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
void	write_room_to_room(t_paths *paths, t_entry *curr, t_entry *next, int index, int len)
{
	if (!curr->occ)
	{
		ft_printf("L%d-%s", next->ant_id, curr->name);
		curr->ant_id = next->ant_id;
		next->ant_id = 0;
		curr->occ = 1;
		next->occ = 0;
	}
}

void	write_start_to_room(t_paths *paths, t_entry *curr, int index, int len)
{
	if (!curr->occ && paths->nbr_ants_s > 0)
	{
		ft_printf("L%d-%s", paths->ant_id, curr->name);
		curr->ant_id = paths->ant_id;
		curr->occ = 1;
		paths->ant_id++;
		paths->nbr_ants_s--;
	}
}

void	write_room_to_end(t_paths *paths, t_entry *curr, t_entry *next, int index, int len)
{
	ft_printf("L%d-%s", next->ant_id, curr->name);
	next->occ = 0;
	paths->nbr_ants_e++;	
}
*/