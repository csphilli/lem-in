/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/02 19:23:47 by cphillip         ###   ########.fr       */
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
		// master->adv_errors = 0;
		master->input_flags = NULL;
		master->accepted_flags = "aechp";
		master->has_flags = 0;
		master->ants_captured = 0;
		master->comment = NULL;
		master->latest_room = NULL;
		master->room_captured = 0;
		master->link_captured = 0;
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
