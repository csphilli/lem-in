/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/19 22:38:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_master(t_master *master)
{
	if (master)
	{
		master->valid_input = false;
		master->s_toggle = false;
		master->e_toggle = false;
		master->start_room = NULL;
		master->end_room = NULL;
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
		master->size_factor = 2;
		master->old_size = 10;
		master->nbr_keys = 0;
		master->n_paths = 2;
	}
}


void	init_link_arr(t_entry **links, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		links[i] = NULL;
		i++;
	}
}

void	init_paths(int len, t_bucket **paths)
{
	while (--len >= 0)
		paths[len] = NULL;
}


