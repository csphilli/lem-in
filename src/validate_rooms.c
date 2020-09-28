/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:08:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 21:06:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	exit_l(t_master *master)
{
	ft_printf(E_L);
	ft_printf(" Found on line %d\n", master->line_nbr);
	exit(-1);
}

static void	exit_duplicate(t_master *master, t_room **ht, int index)
{
	if (master->adv_errors == true)
	{
		ft_printf(E_DUPL);
		ft_printf("'%s' originally defined on line %d.\n", \
		ht[index]->name, ht[index]->on_line);
		exit(-1);
	}
	else
		exit_error();
}

void	duplicate_room_check(t_master *master, t_room **ht)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < HT_SIZE)
	{
		j = i;
		if (ht[i])
		{
			if (ht[i]->name[0] == 'L')
				exit_l(master);
			while (ht[j + 1])
			{
				if (ft_strcmp(ht[j + 1]->name, ht[i]->name) == 0)
					exit_duplicate(master, ht, i);
				j++;
			}
		}
		i++;
	}
}


