/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 11:39:07 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	ant_debugger(t_master *master)
{
	if (master->colors == true)
	{
		ft_printf("CAPTURING ANTS:\n");
		ft_printf("%2cNumber of ants captured: "CYAN"%d\n"RESET, ' ',\
			master->nbr_ants);
	}
	else
	{
		ft_printf("Capturing Ants!\n");
		ft_printf("\tNumber of ants captured: %d\n", master->nbr_ants);
	}
}

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
	if (master->debugger)
		ant_debugger(master);
	master->ants_added = true;
}
