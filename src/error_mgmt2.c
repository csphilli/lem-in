/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:02:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/20 19:30:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
