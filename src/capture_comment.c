/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 13:52:53 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	validate_comment(t_master *master)
{
	if (master)
	{
		if (ft_strequ(master->comment, "start"))
		{
			if (master->flags.s_toggle == true)
				ft_error("ERROR: Start room already defined.\n");
			master->flags.s_toggle = true;
		}
		else if (ft_strequ(master->comment, "end"))
		{
			if (master->flags.e_toggle == true)
				ft_error("ERROR: End node already defined.\n");
			master->flags.e_toggle = true;
		}
	}
}

void	capture_comment(t_master *master, char *str)
{
	if (master && str)
	{
		if (master->comment != NULL)
			ft_strdel(&master->comment);
		if (str[1] == '#')
			master->comment = ft_strdup(&str[2]);
		else
			master->comment = ft_strdup(&str[1]);
		validate_comment(master);
	}
}
