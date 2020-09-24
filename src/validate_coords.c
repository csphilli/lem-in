/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_coords.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:57:50 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 12:58:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	error_coord(int line_nbr)
{
	ft_printf(E_COORD"%d\n", line_nbr);
	exit(-1);
}

void	validate_coords(t_master *master, char *n1, char *n2)
{
	int i;

	i = 0;
	while (n1[i])
	{
		if (!ft_isdigit(n1[i]))
			error_coord(master->line_nbr);
		i++;
	}
	i = 0;
	while (n2[i])
	{
		if (!ft_isdigit(n2[i]))
			error_coord(master->line_nbr);
		i++;
	}
}