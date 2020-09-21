/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:01:34 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/20 07:52:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_list(t_master *master)
{
	// ft_printf("inside print list\n");
	t_room *start;

	start = master->list_head;
	// ft_printf("start->next: %s\n", start->next);
	while (start)
	{
		ft_printf("- - - - - - - - - - - - - - - - - - - - - - - - - -");
		ft_printf(" - - - - - - - - - \n");
		ft_printf(CYAN"Name: %-10s"RESET"| Address: %p | Next: %p\n", \
		start->name, start, start->next);
		ft_printf("%c%-15s| X: %d | Y: %d\n", ' ', "Coords",\
		start->x, start->y);
		start = start->next;
	}
	ft_printf("Room Count: %d\n", master->room_count);
}

void			capture_room(t_master *master, char *line)
{
	t_room	*new;
	t_room	*tmp;

	new = create_room_node(master, line);
	tmp = master->list_head;
	if (master && new)
	{
		if (!master->list_head)
			master->list_head = new;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	master->room_count++;
}
