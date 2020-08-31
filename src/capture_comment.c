/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:05:39 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 10:44:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		capture_comment(t_master *master, char *str)
{
	if (master && str)
	{
		ft_printf("inside capture comment\n"); // uneeded
		while (*str == '#')
			str++;
		ft_strcpy(master->comment, str);
		if (ft_strcmp(master->comment, "start") == 0)
			master->s_toggle = 1;
		else if (ft_strcmp(master->comment, "end") == 0)
			master->e_toggle = 1;
	}
}