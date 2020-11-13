/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:02:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/13 17:16:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_room_not_found(char *str)
{
	ft_printf(E_FAILED_SEARCH"'%s'\n", str);
	exit(-1);
}

void	check_path_exists(t_entry *start, t_entry *end, t_bucket *bfs)
{
	t_bucket *tmp;
	int	s;
	int	e;

	s = 0;
	e = 0;
	tmp = bfs;
	while (tmp)
	{	
		if (ft_strequ(tmp->entry->name, start->name))
			s = 1;
		if (ft_strequ(tmp->entry->name, end->name))
			e = 1;
		if (s == 1 && e == 1)
			break ;
		tmp = tmp->next;
	}
	if (s == 0 || e == 0)
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
