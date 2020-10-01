/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/01 14:17:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// If comment of start or end is the last line, must return error because those values
// need to be known. Would be good to have an if else to either capture another comment
// or to verify that there is another line.

// static void		exit_no_file(void)
// {
// 	ft_printf(E_NOFILE);
// 	exit(-1);
// }

void		parse_lines(t_master *master, char *line, t_room **ht)
{
	int		i;
	t_room *room;
	
	i = 0;
	
	room = NULL;
	// ft_printf("created room\n");
	// ft_printf("Master->comment at start of parse: %s\n", master->comment);
	if (!master->ants_added)
		capture_ants(master, line);
	else if (line[i] == '#')
		capture_comment(master, line);
	else if (master->ants_added == true && line[i] != '#')
	{
		while (ft_isalnum(line[i++]))
		{
			if (line[i] == ' ')
			{
				room = create_room();
				fill_room(room, master, line);
				// ft_printf("Name: %s | Address: %p\n", room->name, room);
				// ft_printf("filled room\n");
				insert_into_ht(ht, master, room);
				// ft_printf("inserted room\n");
				// clear_room(room);
			}
			// else if (line[i] == '-')
			// 	capture_link(ht, line, master);
		}
	}
	else
		ft_printf("random printf\n");
	ft_strdel(&line);
	master->line_nbr++;
}