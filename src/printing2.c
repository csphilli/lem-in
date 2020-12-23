/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:11:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/23 20:55:56 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_int_arr(int *arr)
{
	int i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			ft_printf("%d", arr[i]);
			if (arr[i + 1])
				write(1, ",", 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	print_ll(t_bucket *ll)
{
	t_bucket *tmp;

	tmp = ll;
	if (tmp)
	{
		while (tmp)
		{
			ft_printf("%s", tmp->entry->name);
			if (tmp->next)
				write(1, ",", 1);
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
}


