/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 15:11:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	initialize_lemin(t_master *master, t_room *ht[])
{
	init_master(master);
	init_ht(ht);
}

void	init_master(t_master *master)
{
	if (master)
	{
		master->list_head = NULL;
		master->s_toggle = false;
		master->e_toggle = false;
		master->nbr_ants = 0;
		master->adv_errors = false;
		master->debugger = false;
		master->colors = false;
		master->input_flags = NULL;
		master->accepted_flags = "acdehfl";
		master->line_nbr = 0;		
		master->has_flags = 0;
		master->ants_added = false;
		master->comment = NULL;
		master->latest_room = NULL;
		master->room_captured = 0;
		master->link_captured = 0;
		master->room_count = 0;
		master->dummy = false;
		master->leaks = false;
	}
}

t_room	*init_room(t_room *room)
{
	room->name = NULL;
	room->start_or_end = NULL;
	room->x = -1;
	room->y = -1;
	room->comment = NULL;
	room->occupied = false;
	room->room_links = NULL;
	// room->next = NULL;

	return (room);
}

void	init_ht(t_room *ht[])
{
	int i;

	i = 0;
	while (i < HT_SIZE)
	{
		ht[i] = 0;
		i++;
	}
}
