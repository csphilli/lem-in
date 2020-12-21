/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_direct_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:55:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 20:10:02 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		chk_direct_link(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_entry		*start;
	t_bucket	*end_links;
	t_ants		*ins;

	ins = NULL;
	end_links = bfs->end->links;
	start = get_entry(ht, master, bfs->start->name);
	while (end_links)
	{
		if (ft_strequ(end_links->entry->name, start->name))
		{
			ins = ft_memalloc(sizeof(t_ants));
			ins->i = 1;
			do_one_move(master, ins);
			print_io(master->map, 1);
			ft_printf("L%d-%s", 1, master->end_room->name);
			print_io(master->moves, 0);
			write(1, "\n", 1);
			free(ins);
			return (1);
		}
		end_links = end_links->next;
	}
	return (0);
}
