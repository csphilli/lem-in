/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:17:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/02 19:34:49 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_error(t_master *master, char *error_code)
{
	if (ft_strcmp(error_code, "malloc") == 0)
		ft_printf("in exit error\n");
}