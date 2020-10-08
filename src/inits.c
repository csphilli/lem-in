/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/08 20:25:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_link_arr(char **arr, int len)
{
	int	i;

	i = 0;
	// ft_printf("Init. Len: %d\n", len);
	if (arr)
	{
		while (i < len)
		{
			arr[i++] = NULL;
			// ft_printf("arr[%d]: %s", i, arr[i]);
			// i++;
		}
	}
}

void	init_master(t_master *master)
{
	if (master)
	{
		master->valid_input = false;
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
