/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 01:46:24 by cphillip         ###   ########.fr       */
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
				master->flags.errors ? \
				ft_error("ERROR: Start node already defined.") :\
				ft_error("ERROR");
			master->flags.s_toggle = true;
		}
		else if (ft_strequ(master->comment, "end"))
		{
			if (master->flags.e_toggle == true)
				master->flags.errors ? \
				ft_error("ERROR: End node already defined.") :\
				ft_error("ERROR");
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
