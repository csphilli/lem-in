/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_distro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:11:02 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/02 13:27:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_line_break(int nbr, int amount)
{
	int sum;

	sum = nbr * amount;
	while (sum--)
		write(1, "-", 1);
	write(1, "\n", 1);
}

void	print_cascade_header(void)
{
	ft_printf("%-11sIndex position of path in set.\n", "Index:");
	ft_printf("%-11sNbr of nodes in path.\n", "Length:");
	ft_printf("%-11sNbr moves to get 1 ant through path.\n", "Min:");
	ft_printf("%-11sNumber of ants allocated to path\n", "Ants:");
	ft_printf("%-11sMin number of ants to unlock next path\n\n", "Unlock:");
	ft_printf("|%-11s%-11s", "Index", "Length");
	ft_printf("%-11s%-11s", "Min", "Ants");
	ft_printf("%-11s%-11s|\n", "Unlock", "Total Moves");
	print_line_break(6, 11);
}

void	print_distro(t_distro **list)
{
	t_distro	*tmp;

	tmp = *list;
	if (tmp)
	{
		print_cascade_header();
		while (tmp)
		{
			ft_printf("|%-11d", tmp->index);
			if (tmp->len)
				ft_printf("%-11d", tmp->len);
			if (tmp->cap)
				ft_printf("%-11d", tmp->cap);
			!tmp->nbr_ants ? ft_printf("%-11d", 0) :\
			ft_printf("%-11d", tmp->nbr_ants);
			if (tmp->unlock)
				ft_printf("%-11d", tmp->unlock);
			!tmp->total_moves ? ft_printf("%-11d|\n", 0) :\
			ft_printf("%-11d|\n", tmp->total_moves);
			print_line_break(6, 11);
			tmp = tmp->next;
		}
	}
	write(1, "\n", 1);
}
