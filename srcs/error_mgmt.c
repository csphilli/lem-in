/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/02 15:21:10 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_coord(t_master *master)
{
	if (master->errors)
		ft_error("ERROR: Coordinate must be digit.");
	else
		ft_error("ERROR");
}

void	exit_dup(t_master *master, char *s)
{
	if (master->errors)
	{
		ft_printf(E_DUPL"'%s'.\n", s);
		exit(-1);
	}
	else
		ft_error("ERROR");
	
}

void	exit_room_not_found(t_master *master, char *str)
{
	if (master->errors)
	{
		ft_printf(E_FAILED_SEARCH"'%s'\n", str);
		exit(-1);		
	}
	ft_error("ERROR");
}

void	exit_dup_coord(t_master *master)
{
	if (master->errors)
	{
		ft_printf("Error. Duplicate coordinate of line %d found on line %d.\n", \
			master->line_nbr - 1, master->line_nbr);
		exit(-1);
	}
	else
		ft_error("ERROR");
	
}
