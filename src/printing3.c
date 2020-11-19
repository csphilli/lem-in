/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:11:02 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 11:11:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	ft_printf("%-10sIndex position of list of list.\n", "Index:");
	ft_printf("%-10sLength of the list at index.\n", "Length:");
	ft_printf("%-10sMin moves to get 1 ant through path.\n", "Moves:");
	ft_printf("%-10sNumber of ants allocated to specific", "Ants:");
	ft_printf(" path.\n");
	ft_printf("%-10sMin number of ants to unlock allocation", "Unlock:");
	ft_printf(" at next index.\n\n");
	ft_printf("|%-10s%-10s", "Index", "Length");
	ft_printf("%-10s%-10s%-10s|\n", "Moves", "Ants", "Unlock");
	print_line_break(5, 10);
}

void	print_distro(t_lol **list)
{
	t_lol 		*tmp;

	tmp = *list;
	if (tmp)
	{
		print_cascade_header();
		while (tmp)
		{
			ft_printf("|%-10d", tmp->index);
			if (tmp->len)
				ft_printf("%-10d", tmp->len);
			if (tmp->cap)
				ft_printf("%-10d", tmp->cap);
			if (!tmp->nbr_ants)
				ft_printf("%-10d", 0);
			else
				ft_printf("%-10d", tmp->nbr_ants);
			if (tmp->unlock)
				ft_printf("%-10d|\n", tmp->unlock);
			print_line_break(5, 10);
			tmp = tmp->next;
		}
	}
}