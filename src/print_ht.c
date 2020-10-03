/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 18:14:59 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ht(t_bucket **ht, t_master *master)
{
	size_t	i;

	i = 0;
	while(i < master->new_size)
	{
		ft_printf("HT[%d]: ", i);
		if (ht[i]->entry)
		{
			while (ht[i]->entry)
			{
				ft_printf("{Name: %s | Key: %d}", ht[i]->entry->name, ht[i]->entry->key);
				if (ht[i]->next)
					ft_printf("-->");
				if (ht[i]->next)
					ht[i] = ht[i]->next;
				else
					break ;
			}
		}
		ft_printf("\n");		
		i++;
	}
}