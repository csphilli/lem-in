/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 15:03:45 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		acceptable(char c)
{
	return (c >= 33 && c <= 126);
}

void		parse_lines(t_master *master, char *line, t_bucket **ht)
{
	int			i;
	t_entry		*entry;

	i = 0;
	entry = NULL;
	if (!master->ants_added)
		capture_ants(master, line);
	else if (line[i] == '#')
		capture_comment(master, line);
	else if (master->ants_added == true && line[i] != '#')
	{
		while (acceptable(line[i++]))
		{
			if (line[i] == ' ')
				capture_room(ht, master, line);
			else if (line[i] == '-')
				capture_links(ht, master, line);
		}
	}
	ft_strdel(&line);
	master->line_nbr++;
}
