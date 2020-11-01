/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 14:32:25 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validate_ants(char *line)
{
	if (line)
	{
		while (*line)
		{
			if (!ft_isdigit(*line))
				return (0);
			line++;
		}
		return (1);
	}
	return (0);
}

int		valid_int_test(char *s)
{
	intmax_t nbr;

	if (validate_ants(s) == 0)
	{
		ft_printf(E_ANTS);
		exit(-1);
	}
	nbr = ft_atoi(s);
	if (nbr >= 1 && nbr <= 2147483648)
		return (nbr);
	return (0);
}

void	capture_ants(t_master *master, char *line)
{
	int nbr_ants;

	nbr_ants = valid_int_test(line);
	master->nbr_ants = nbr_ants;
	master->ants_added = true;
}
