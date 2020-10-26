/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:02:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/25 10:24:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// I CAN CLEAN THESE UP. Have a function called ERRORS. Then when I have the toggle on
//	it will go into the nicely defined functions, else just return a standard error.

void	exit_room_not_found(char *str)
{
	ft_printf(E_FAILED_SEARCH"'%s'\n", str);
	exit(-1);
}

void	check_path_exists(t_entry *start, t_entry *end, t_dfs *dfs)
{
	if (!link_exists(dfs->q, start) || !link_exists(dfs->q, end))
	{
		ft_printf(E_NOPATH);
		exit(-1);
	}
}

void	exit_dup_coord(t_master *master)
{
	ft_printf("Error. Duplicate coordinate of line %d found on line %d.\n", \
		master->line_nbr - 1, master->line_nbr);
	exit(-1);
}

void	exit_no_solution(void)
{
	ft_printf(E_NOSOLUTION"\n");
	exit(-1);
}

void	exit_no_path(void)
{
	ft_printf(E_NOPATH);
	exit(-1);
}
