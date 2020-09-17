/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/17 22:02:45 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int valid_int_test(t_master *master, char *s)
{
	intmax_t nbr;

	nbr = ft_atoi(s);
	if (nbr >= 1 && nbr <= 2147483648)
		return (nbr);
	exit_error(master, "invalid_ant_int");
	return (0);
}

void		capture_ants(t_master *master, char *line)
{
	int nbr_ants;

	nbr_ants = valid_int_test(master, line);
	master->nbr_ants = nbr_ants;
	master->ants_added = true;
	ft_printf("captured ants: %d\n", master->nbr_ants);
}
