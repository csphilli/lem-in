/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:11:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 19:46:26 by cphillip         ###   ########.fr       */
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
