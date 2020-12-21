/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/01 14:03:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	validate_comment(t_master *master)
{
	if (master)
	{
		if (ft_strequ(master->comment, "start"))
		{
			if (master->s_toggle == true)
				master->errors ? \
				ft_error("ERROR: Start node already defined.") :\
				ft_error("ERROR");
			master->s_toggle = true;
		}
		else if (ft_strequ(master->comment, "end"))
		{
			if (master->e_toggle == true)
				master->errors ? \
				ft_error("ERROR: End node already defined.") :\
				ft_error("ERROR");
			master->e_toggle = true;
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