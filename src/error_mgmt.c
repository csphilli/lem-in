/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_mgmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 20:17:06 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/19 11:52:57 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	bad_malloc(void)
{
	ft_printf("Failed to allocate memory. Malloc functions used in files:\n");
	ft_printf("%2s\n", "lem_in.c");
	ft_printf("%2s\n", "capture_flags.c");
	ft_printf("%2s\n", "capture_comment.c");
}

static void	exit_error_2(t_master *master, char *error_code)
{
	if (ft_strcmp(error_code, "no_rooms_or_links"))
		ft_printf("Error: No rooms or links specified\n");
	else if (ft_strequ(error_code, "L_present"))
	{
		ft_printf("Error: 'L' not permitted in room name.\n");
		ft_printf("%2cFound on line number: %d\n", master->line_nbr);
	}
	else	
		ft_printf("Error. To see advanced errors, use the '-e' flag.\n");
	master->dummy = true; // remove before submission. Just using up master. Might need it in the future.
}

void	exit_error(t_master *master, char *error_code)
{
	if (master->adv_errors == true || ft_strchr(master->input_flags, 'e'))
	{
		if (ft_strequ(error_code, "flags"))
			ft_printf("Error: Invalid flag specified. Accepted: %s\n",\
			master->accepted_flags);
		else if (ft_strequ(error_code, "malloc"))
			bad_malloc();
		else if (ft_strequ(error_code, "nofile"))
			ft_printf("Error: File not specified\n");
		else if (ft_strequ(error_code, "invalid_ant_int"))
		{
			ft_printf("Error: Ant count must be >= 1 and an integer size.\n"); // need to separate negative and no ant errors
		}
		else if (ft_strequ(error_code, "start_exists"))
		{
			ft_printf("Error: Start room has already been designated.\n");
			ft_printf("\tDuplicate found on line: %d\n", master->line_nbr);
		}
		else if (ft_strequ(error_code, "end_exists"))
		{
			ft_printf("Error: End room has already been designated.\n");
			ft_printf("\tDuplicate found on line: %d\n", master->line_nbr);
		}
		else
			exit_error_2(master, error_code);
	}	
	exit(-1);
}