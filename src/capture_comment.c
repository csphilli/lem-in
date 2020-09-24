/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 11:39:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	validate_comment(t_master *master)
{
	if (master)
	{
		ft_printf("VALIDATING COMMENT: %s:", master->comment);
		if (ft_strequ(master->comment, "start"))
		{
			if (master->s_toggle == true)
			{
				ft_printf("...failure!\n");
				exit_error(master, "start_exists");
			}
			master->s_toggle = true;
		}
		else if (ft_strequ(master->comment, "end"))
		{
			if (master->e_toggle == true)
			{
				ft_printf("...failure!\n");
				exit_error(master, "end_exists");
			}
			master->e_toggle = true;
		}
		ft_printf("...success!\n");
	}
}

void		capture_comment(t_master *master, char *str)
{
	if (master && str)
	{
		// ft_printf("capture comment: %s\n", &str[2]);
		if (master->comment != NULL)
			ft_strdel(&master->comment);
		master->comment = ft_strdup(&str[2]);
		if (master->debugger == true)
			validate_comment(master);
	}	
}
