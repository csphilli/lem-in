/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:17:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 09:59:06 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	exit_error(t_master *master, char *error_code)
{
	if (master->adv_errors == true)
	{
		if (ft_strcmp(error_code, "nofile") == 0)
			ft_printf("Error: File not specified\n");
		else if (ft_strcmp(error_code, "malloc") == 0)
			ft_printf("Error: Failed to allocate memory.\n");
		else if (ft_strcmp(error_code, "flags") == 0)
			ft_printf("Error: Invalid flag specified. Accepted: %s\n",\
			master->accepted_flags);
		else if (ft_strcmp(error_code, "invalid_ant_int") == 0)
		{
			ft_printf("Error: Ant count must be >= 1 and an integer size.\n"); // need to separate negative and no ant errors
		}
		else if (ft_strcmp(error_code, "start_exists") == 0)
		{
			ft_printf("Error: Start room has already been designated.\n");
			ft_printf("\tDuplicate found on line: %d\n", master->line_nbr);
		}
		else if (ft_strcmp(error_code, "end_exists") == 0)
		{
			ft_printf("Error: End room has already been designated.\n");
			ft_printf("\tDuplicate found on line: %d\n", master->line_nbr);
		}

	}
	else
		ft_printf("Error. To see advanced errors, use the '-e' flag.\n");
	
	exit(-1);
}