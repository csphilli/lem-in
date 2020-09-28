/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 21:05:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 19:56:16 by cphillip         ###   ########.fr       */
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