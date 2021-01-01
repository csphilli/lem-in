/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 17:47:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Could get rid of these and just us basic error messages. Remove line functionality. who cares...

void	ft_error(char *error_msg)
{
	write(1, error_msg, ft_strlen(error_msg));
	exit(-1);
}

// void	exit_coord(t_master *master)
// {
// 	master->flags.errors ? ft_error("ERROR: Coordinate must be digit.") : \
// 	ft_error("ERROR");
// }

// void	exit_dup(t_master *master, char *s)
// {
// 	if (master->flags.errors)
// 	{
// 		ft_printf("ERROR: Duplicate room name found: '%s'.\n", s);
// 		exit(-1);
// 	}
// 	else
// 		ft_error("ERROR");
// }

// void	exit_room_not_found(t_master *master, char *str)
// {
// 	if (master->flags.errors)
// 	{
// 		ft_printf("ERROR: Could not insert link. Room '%s' not found\n", str);
// 		exit(-1);
// 	}
// 	ft_error("ERROR");
// }

// void	exit_dup_coord(t_master *master)
// {
// 	if (master->flags.errors)
// 	{
// 		ft_printf("Error. Duplicate coordinate found on line %d.\n", \
// 			master->line_nbr);
// 		exit(-1);
// 	}
// 	else
// 		ft_error("ERROR");
// }
