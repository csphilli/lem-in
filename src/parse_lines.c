/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:30:26 by cphillip         ###   ########.fr       */
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

void		parse_lines(t_master *master, char *line, t_bucket **ht)
{
	int			i;
	t_entry		*entry;
	
	i = 0;
	// ft_printf("Parsing Lines\n");
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
				// ft_printf("capturing room\n");
				entry = create_and_fill_entry(master, line);
				assign_entry_to_ht(ht, master, entry);
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