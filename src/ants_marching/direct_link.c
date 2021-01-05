/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_link.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/05 09:55:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	do_one_move(t_master *master)
{
	int			ants_e;

	ants_e = 0;
	while (ants_e++ < master->nbr_ants)
	{
		if (ants_e == 1)
			master->ants->i = 0;
		else
			master->ants->i = 1;
		cat_move(master, ants_e, master->end_room->name);
	}
	if (master->moves->b_len < IO_BUF)
	{
		ft_strcat(master->moves->buf, "\0");
		buf_to_output(&master->moves);
	}
	master->ants->n_moves++;
}

int		direct_link(t_bucket **ht, t_master *master)
{
	t_entry		*start;
	t_bucket	*end_links;

	end_links = master->end_room->links;
	start = get_entry(ht, master->start_room->name);
	while (end_links)
	{
		if (ft_strequ(end_links->entry->name, start->name))
		{
			master->ants->i = 0;
			do_one_move(master);
			print_io(master->map, 1);
			print_io(master->moves, 0);
			write(1, "\n", 1);
			free(master->ants);
			master->direct = 1;
			return (1);
		}
		end_links = end_links->next;
	}
	return (0);
}
