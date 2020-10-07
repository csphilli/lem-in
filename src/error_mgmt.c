/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/07 10:50:20 by cphillip         ###   ########.fr       */
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
