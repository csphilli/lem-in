/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/03 17:49:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	valid_int(char *str)
{
	intmax_t	nbr;
	char		*tmp;

	tmp = str;
	if (*tmp == '+')
		tmp++;
	else if (*tmp == '-')
	{
		ft_printf("need exit error for negative ants\n");
		exit(-1);
	}
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
		{
			ft_printf("Need exit error for invalid int of ant count\n");
			exit(-1);
		}
		tmp++;
	}
	nbr = ft_atoimax(str);
	if (nbr >= (-2147483647 - 1) && nbr <= 2147483648)
		return (nbr);
	else
	{
		ft_printf("need error for invalid in size\n");
		exit(-1);
	}
	return (0);
}

void		capture_ants(t_master *master, char *line)
{
	int nbr_ants;

	nbr_ants = valid_int(line);
	master->nbr_ants = nbr_ants;
	master->ants_added = true;
	ft_printf("captured ants: %d\n", master->nbr_ants);
}
