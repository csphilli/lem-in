/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 16:14:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	validate_ants(char *line)
{
	char	*tmp;

	tmp = line;
	if (tmp)
	{
		while (*tmp)
		{
			if (!ft_isdigit(*tmp))
				ft_errorexit("ERROR: Ant amount must be unsigned integer\n");
			tmp++;
		}
	}
}

void	capture_ants(t_master *master, char *line)
{
	intmax_t	max_ants;
	int			ants;

	ants = 0;
	if (*line == '\0' || *line == ' ')
		ft_errorexit("ERROR: Missing ant amount or space preceding number.\n");
	validate_ants(line);
	max_ants = ft_atoimax(line);
	if (max_ants < 1 || max_ants > 2147483647)
		ft_errorexit("ERROR: Ant amount must be integer size and > 0.\n");
	ants = ft_atoi(line);
	master->nbr_ants = ants;
	master->flags.ants_added = true;
}
