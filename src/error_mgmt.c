/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:17:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/16 13:47:59 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_error(t_master *master, char *error_code)
{
	if (ft_strcmp(error_code, "nofile") == 0)
		ft_printf("Error: no file specified\n");
	else if (ft_strcmp(error_code, "malloc") == 0)
		ft_printf("in exit error\n");
	else if (ft_strcmp(error_code, "flags") == 0)
		ft_printf("Error: Invalid flag specified. Accepted: %s\n",\
		master->accepted_flags);
		
	
	// exit(-1);
}