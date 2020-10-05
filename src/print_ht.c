/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/05 14:11:33 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_ht(t_bucket **ht, size_t size)
{
	size_t	i;
	t_bucket *tmp;

	i = 0;
	tmp = NULL;
	while(i < size)
	{
		ft_printf("HT[%2d]: ", i);
		if (ht[i] != NULL)
		{
			tmp = ht[i];
			while (tmp != NULL)
			{
				ft_printf("{Name: %s | Key: %d}", tmp->entry->name, tmp->entry->key);
				if (tmp->next)
					ft_printf("-->");
				tmp = tmp->next;
			}
			// ft_printf("\n")
		}
		ft_printf("\n");
		i++;
	}
}
