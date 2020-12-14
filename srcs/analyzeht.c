/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzeht.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:40:24 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/14 14:27:40 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	analyze_ht(t_bucket **ht, t_master *master)
{
	float	conflict;
	// int sum;
	size_t index;
	t_bucket *tmp;

	conflict = 0.0;
	index = 0;
	tmp = NULL;
	while (index < master->new_size)
	{
		if (ht[index])
		{
			// conflict = 0;
			tmp = ht[index];
			{
				if (tmp->next)
				{
					while (tmp)
					{
						conflict += 1.0;
						tmp = tmp->next;
					}
				}
			}
		}
		index++;
	}
	print_ht(ht, master->new_size);
	ft_printf("Count: %d\n", conflict);
	ft_printf("Conflict Density: %d\n", conflict / (float)master->new_size);
	ft_error("Exiting after analyze");
}