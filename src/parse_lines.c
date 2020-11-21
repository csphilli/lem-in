/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:04:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/22 01:14:00 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		acceptable(char c)
{
	return (c >= 33 && c <= 126);
}

// int		acceptable(char *line)
// {
// 	int space;
// 	int	dash;
// 	int	i;

// 	space = 0;
// 	dash = 0;
// 	i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == ' ')
// 			space++;
// 		if (line[i] == '-')
// 			dash++;
// 		if (line[i] <= 33 && line[i] >= 126)
// 			ft_error("ERROR. Invalid input.");
// 		i++;
// 	}
// 	if (space == 0 && dash == 0)
// 		ft_error("ERROR. Empty line.");
// 	else if (space == 2 || dash == 1)
// 		return (1);
// 	ft_printf("Acceptable == zero\n");
// 	return (0);
// }

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
	else if (line[i] == '\0')
		ft_error("ERROR. Empty line.");
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
