/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/23 08:37:09 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// If comment of start or end is the last line, must return error because those values
// need to be known. Would be good to have an if else to either capture another comment
// or to verify that there is another line.

static void		parsing_lines(t_master *master, int fd, t_room *ht[])
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
					insert_room(ht, line, master);
				// else if (line[i] == '-')
				// 	capture_link(master, line);
			}
		}
		else
			ft_printf("random printf\n");
		ft_strdel(&line);
		master->line_nbr++;
	}
}

void		parse_input(t_master *master, int fd, t_room *ht[])
{
	int		i;

	i = 1;
	if (fd < 0)
		exit_error(master, "nofile");
	parsing_lines(master, fd, ht);
	close(fd);
	ft_printf("flags: %s\n", master->input_flags);
	
}
