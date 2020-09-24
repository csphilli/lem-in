/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:08:25 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 11:36:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	duplicate_rooms(t_master *master, t_room *ht[])
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
				exit_error(master, "L_present");
			while (ht[j + 1])
			{
				if (ft_strcmp(ht[j + 1]->name, ht[i]->name) == 0)
					exit_error(master, "duplicate");
				j++;
			}
		}
		i++;
	}
}

void	validate_coords(t_master *master, char *n1, char *n2)
{
	int i;

	i = 0;
	while (n1[i])
	{
		if (!ft_isdigit(n1[i]))
		{
			ft_printf("Error: Invalid coordinate '%s' on line %d.\n", n1\
			, master->line_nbr);
			exit(-1);
		}
		i++;
	}
	i = 0;
	while (n2[i])
	{
		if (!ft_isdigit(n2[i]))
		{
			ft_printf("Error: Invalid coordinate '%s' on line %d\n", n2\
			, master->line_nbr);
			exit(-1);
		}
		i++;
	}
}
