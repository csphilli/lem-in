/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/06 09:11:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_malloc(void)
{
	ft_printf(E_MALLOC);
	exit(-1);
}

void	exit_error(void)
{
	ft_printf(E_BASIC);
	exit(-1);
}

void	exit_usage(void)
{
	ft_printf(E_USAGE);
	exit(-1);
}

void	error_coord(int line_nbr)
{
	ft_printf(E_COORD"%d\n", line_nbr);
	exit(-1);
}
