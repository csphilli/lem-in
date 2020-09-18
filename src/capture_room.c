/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:01:34 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/18 14:39:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			capture_room(t_master *master, char *line)
{
	if (master && line)
	{
		ft_printf("inside room capture. Line: %s\n", line);
		// assign room address to master struct of latest room.
	}
}
