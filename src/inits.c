/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:15:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// void	initialize_lemin(t_master *master, t_room *ht[])
// {
// 	init_master(master);
// 	init_ht(ht);
// }

void	init_master(t_master *master)
{
	if (master)
	{
		master->s_toggle = false;
		master->e_toggle = false;
		master->nbr_ants = 0;
		master->adv_errors = false;
		master->debugger = false;
		master->colors = false;
		master->input_flags = NULL;
		master->accepted_flags = "acdehfl";
		master->line_nbr = 1;		
		master->has_flags = 0;
		master->ants_added = false;
		master->comment = NULL;
		master->room_count = 0;
		master->leaks = false;
		master->new_size = 10;
		master->load = 5.0;
		master->old_size = 10;
		master->nbr_keys = 0;
	}
}

// t_room	*init_room(t_room *room, char **data, int key, int index, t_master *master)
// {
// 	room->index = index;
// 	room->key = key;
// 	room->name = ft_strdup(data[0]);
// 	room->start_or_end = NULL;
// 	room->x = ft_atoi(data[1]);
// 	room->y = ft_atoi(data[2]);
// 	if (master->comment != NULL)
// 	{
// 		room->comment = ft_strdup(master->comment);
// 		ft_strdel(&master->comment);
// 	}
// 	room->occupied = false;
// 	room->links = NULL;
// 	room->on_line = 0;
// 	room->next = NULL;
// 	return (room);
// }

// void	copy_room(t_room *dest, t_room *src)
// {
// 	dest->index = src->index;
// 	dest->key = src->key;
// 	dest->name = ft_strdup(src->name);
// 	dest->start_or_end = ft_strdup(src->start_or_end);
// 	dest->x = src->x;
// 	dest->y = src->y;
// 	if (src->comment != NULL)
// 		dest->comment = ft_strdup(src->comment);
// 	dest->occupied = src->occupied;
// 	dest->links = NULL; // need to fix later
// 	dest->on_line = src->on_line;
// 	dest->next = NULL;
// }
