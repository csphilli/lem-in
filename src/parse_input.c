/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/19 21:43:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"



// static void 	append_room(t_master *master, t_room *room)
// {
// 	t_room *tmp;

// 	tmp = master->room_head;
// 	if (master && room)
// 	{
// 		if (!master->room_head)
// 			master->room_head = room;
// 		else
// 		{
// 			while (tmp->next != NULL)
// 				tmp = tmp->next;
// 			tmp->next = room;
// 		}
// 	}
// 	master->latest_room = room;
// }

// void			parse_line(t_master *master, char **av, int fd)
// static void			parse_line(t_master *master, char *line)
// {
// }

// If comment of start or end is the last line, must return error because those values
// need to be known. Would be good to have an if else to either capture another comment
// or to verify that there is another line.

static void		parsing_lines(t_master *master, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		// ft_printf("Line: %s\n", line);
		if (!master->ants_added)
			capture_ants(master, line);
		else if (line[i] == '#')
			capture_comment(master, line);
		else if (master->ants_added == true && line[i] != '#')
		{
			while (ft_isalnum(line[i++]))
			{
				if (line[i] == ' ')
					capture_room(master, line);
				// else if (line[i] == '-')
				// 	capture_link(master, line);
			}
		}
		else
			ft_printf("random printf\n");
		// if (master->comment != NULL)
		// {	
		// 	ft_strdel(&master->comment);
		// 	master->comment = NULL;
		// }
		ft_strdel(&line);
		master->line_nbr++;
	}
}

void		parse_input(t_master *master, int fd)
{
	int		i;

	i = 1;
	if (fd < 0)
		exit_error(master, "nofile");
	parsing_lines(master, fd);
	close(fd);
	ft_printf("flags: %s\n", master->input_flags);
	
}
