/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzeht.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:40:24 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/20 21:10:23 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	analyze_ht(t_bucket **ht)
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
	while (index < TABLE_SIZE)
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
	res_unused = ((double)unused / (double)TABLE_SIZE) * 100;
	res = (double)conflict / ((double)TABLE_SIZE - (double)unused);
	print_ht(ht);
	ft_printf("Conflicts: %d\n", conflict);
	ft_printf("%% unused: %f2%%\n", res_unused);
	ft_printf("Unused indecies: %d\n", unused);
	ft_printf("Average Index Density: %f\n", res);
	// ft_error("Exiting after analyze");
}