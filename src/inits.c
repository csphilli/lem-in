/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 15:05:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_master(t_master *master)
{
	if (master)
	{
		master->room_head = NULL;
		master->s_toggle = false;
		master->e_toggle = false;
		master->nbr_ants = 0;
		master->adv_errors = false;
		master->debugger = false;
		master->colors = false;
		master->input_flags = NULL;
		master->accepted_flags = "acdehf";
		master->line_nbr = 1;		
		master->has_flags = 0;
		master->ants_added = false;
		master->comment = NULL;
		master->latest_room = NULL;
		master->room_captured = 0;
		master->link_captured = 0;
		master->dummy = false;
	}
}

void	init_room(t_room *room)
{
	if (room)
	{
		room->name = NULL;
		room->start_or_end = NULL;
		room->comment = NULL;
		// room->x = 0;
		// room->y = 0;
		room->occupied = false;
		room->room_links = NULL;
		room->next = NULL;
	}
}
