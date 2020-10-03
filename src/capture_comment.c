/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:27:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	exit_comment_start(void)
{
	ft_printf(E_START);
	exit(-1);
}

static void	exit_comment_end(void)
{
	ft_printf(E_END);
	exit(-1);
}

static void	validate_comment(t_master *master)
{
	if (master)
	{
		if (ft_strequ(master->comment, "start"))
		{
			if (master->s_toggle == true)
				exit_comment_start();
			master->s_toggle = true;
		}
		else if (ft_strequ(master->comment, "end"))
		{
			if (master->e_toggle == true)
				exit_comment_end();
			master->e_toggle = true;
		}
	}
}

void		capture_comment(t_master *master, char *str)
{
	if (master && str)
	{
		if (master->comment != NULL)
			ft_strdel(&master->comment);
		master->comment = ft_strdup(&str[2]);
		validate_comment(master);
	}	
}
