/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzeht.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:40:24 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/14 21:41:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	analyze_ht(t_bucket **ht, t_master *master)
{
	int	conflict;
	double		res;
	int	unused;
	double res_unused;
	// int sum;
	size_t index;
	t_bucket *tmp;

	conflict = 0;
	index = 0;
	unused = 0;
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
		else if (!ht[index])
			unused++;
		index++;
	}
	res_unused = ((double)unused / (double)master->new_size) * 100;
	res = (double)conflict / ((double)master->new_size - (double)unused);
	print_ht(ht, master->new_size);
	ft_printf("%% unused: %f2%%\n", res_unused);
	ft_printf("Unused indecies: %d\n", unused);
	ft_printf("Average Index Density: %f\n", res);
	// ft_error("Exiting after analyze");
}