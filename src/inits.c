/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 12:24:30 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_master(t_master *master)
{
	if (master)
	{
		master->room_head = NULL;
		master->e_toggle = 0;
		master->s_toggle = 0;
		master->nbr_ants = 0;
		master->comment = NULL;
	}
}

void	init_room(t_room *room)
{
	if (room)
	{
		room->name = NULL;
		room->start_or_end = NULL;
		room->x = 0;
		room->y = 0;
		room->L_toggle = 0;
		room->c1 = NULL;
		room->c2 = NULL;
		room->c1_loc = NULL;
		room->c2_loc = NULL;
		room->next = NULL;
	}
}
