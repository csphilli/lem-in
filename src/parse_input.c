/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 15:18:17 by cphillip         ###   ########.fr       */
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
static void		parsing_lines(t_master *master, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
	
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
				else if (line[i] == '-')
					capture_link(master, line);
			}
		}
		// else if (master->ants_added == false)
		// {
		// 	while (ft_isalnum(line[i]))
		// 		i++;
		// 	ft_printf(RED"char at line[%d]: %c\n"RESET, i, *line);	
		// }
		
		// capture_room(master, line); // this needs to be within an if else statement otherwise previous
									// line values are not yet deleted.
			
		ft_strdel(&master->comment); // before deleting comment, must add it to respective room.
		// ft_printf("parsing line: %s\n", line);
		// parse_line(master, line);
		ft_strdel(&line);
		master->line_nbr++;
	}
}

// need to add conditionals to step into help or other bonus functions. 
// IDEAS
// usage flag
//	output map for smaller room counts (less than 10?)

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
