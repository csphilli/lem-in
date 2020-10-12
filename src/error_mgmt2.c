/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:02:09 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/12 16:54:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_room_not_found(char *str)
{
	ft_printf(E_FAILED_SEARCH"'%s'\n", str);
	exit(-1);
}

void	check_path_exists(t_entry *start, t_entry *end, t_routes *routes)
{
	if (!link_exists(routes->q, start) || !link_exists(routes->q, end))
	{
		ft_printf(E_NOPATH);
		exit(-1);
	}
}
