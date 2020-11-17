/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 15:39:29 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_coord(int line_nbr)
{
	ft_printf(E_COORD"%d\n", line_nbr);
	exit(-1);
}

void	exit_dup(char *s, size_t index)
{
	ft_printf(E_DUPL"'%s' at index: %d.\n", s, index);
	exit(-1);
}

void	exit_room_not_found(char *str)
{
	ft_printf(E_FAILED_SEARCH"'%s'\n", str);
	exit(-1);
}

void	exit_dup_coord(t_master *master)
{
	ft_printf("Error. Duplicate coordinate of line %d found on line %d.\n", \
		master->line_nbr - 1, master->line_nbr);
	exit(-1);
}