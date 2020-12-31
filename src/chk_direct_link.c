/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_direct_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/31 14:13:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		chk_direct_link(t_bucket **ht, t_master *master)
{
	t_entry		*start;
	t_bucket	*end_links;

	end_links = master->end_room->links;
	start = get_entry(ht, master, master->start_room->name);
	while (end_links)
	{
		if (ft_strequ(end_links->entry->name, start->name))
		{
			master->ants->i = 1;
			do_one_move(master);
			print_io(master->map, 1);
			ft_printf("L%d-%s", 1, master->end_room->name);
			print_io(master->moves, 0);
			write(1, "\n", 1);
			free(master->ants);
			return (1);
		}
		end_links = end_links->next;
	}
	return (0);
}
