/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:11:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/14 13:48:20 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_int_arr(int *ants)
{
	int i;

	i = 0;
	ft_printf("\nANT DISTRIBUTION ALONG PATHS FOR SOLVING\n");
	ft_printf("INDEX:\tANTS\n");
	while (ants[i])
	{
		ft_printf("[%4d]:\t%d", i, ants[i]);
		if (ants[i + 1])
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	print_ll(t_bucket *ll)
{
	t_bucket *tmp;

	tmp = ll;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->entry->visited)
				ft_printf(RED);
			ft_printf("%s"RESET, tmp->entry->name);
			if (tmp->next)
				write(1, ",", 1);
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
}

void	print_lol(t_lol *list)
{
	t_lol *tmp;
	t_bucket *curr;

	tmp = list;
	curr = NULL;
	if (tmp && tmp->list)
	{
		while (tmp)
		{
			curr = tmp->list;
			while (curr)
			{
				ft_printf("%s", curr->entry->name);
				curr->next ? write(1, ",", 1) : 1;
				curr = curr->next;
			}
			tmp->next ? write(1, "\n", 1) : 1;
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
}
