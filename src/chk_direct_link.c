/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_direct_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 10:56:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// int		chk_direct_link(t_bucket **ht, t_master *master, t_bfs *bfs)
int		chk_direct_link(t_bucket **ht, t_master *master)
{
	t_entry		*start;
	t_bucket	*end_links;
	// t_ants		*ins;

	// ins = NULL;
	end_links = master->end_room->links;
	// print_ll(end_links);
	start = get_entry(ht, master, master->start_room->name);
	// printf("here\n");
	while (end_links)
	{
		if (ft_strequ(end_links->entry->name, start->name))
		{
			// ins = ft_memalloc(sizeof(t_ants));
			master->ants->i = 1;
			// do_one_move(master, ins);
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
