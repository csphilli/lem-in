/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 19:04:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		validate_ants(char *line)
{
	char	*tmp;

	tmp = line;
	if (tmp)
	{
		while (*tmp)
		{
			if (!ft_isdigit(*tmp))
				return (0);
			tmp++;
		}
		return (1);
	}
	return (0);
}

void	capture_ants(t_master *master, char *line)
{
	intmax_t	max_ants;
	int			ants;

	ants = 0;
	if (*line == '\0' || *line == ' ' || !validate_ants(line))
		ft_errorExit("ERROR: Missing ant amount or space preceding number.\n");
	max_ants = ft_atoimax(line);
	if (max_ants < 1 || max_ants > 2147483647)
		ft_errorExit("ERROR: Ant amount must be integer size.\n");
	ants = ft_atoi(line);
	master->nbr_ants = ants;
	master->flags.ants_added = true;
}
