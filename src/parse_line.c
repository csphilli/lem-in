/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 10:29:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"




static void 	append_room(t_master *master, t_room *room)
{
	t_room *tmp;

	tmp = master->room_head;
	if (master && room)
	{
		if (!master->room_head)
			master->room_head = room;
		else
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = room;
		}
	}
}

void			parse_line(t_master *master, char **av, int fd)
{
	t_room 	*room;
	char	*line;
	char	*c;
	if (av[0])
		av[0] += 0;
	c = NULL;
	ft_printf("In Parse Line\n");
	while (get_next_line(fd, &line) > 0)
	{
		ft_printf("inside while loop\n");
		c = line;
		capture_ants(master, line);
		while (*c)
			c++;
		c--;
		while (ft_isdigit(*c))
			c--;
		if (*c == '-')
			ft_printf("capture connetion\n");
			// capture_connection(master, line);
		else if (ft_strncmp(line, "##", 2) == 0)
			capture_comment(master, line);
		else
			room = capture_room(master, line);
		append_room(master, room);
		ft_strdel(&line);
	}
	ft_printf("End Parse Line\n");
}
