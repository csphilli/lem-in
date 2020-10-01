/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:22:15 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/01 13:48:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 	print_ht(t_room **ht, t_master *master)
{
	// ft_printf("into printing\n");
	size_t	i;
	t_room	*tmp;

	i = 0;
	tmp = NULL;
	printf("new size: %zu\n", master->new_size);
	while (i < master->new_size)
	{
		if (ht[i] != NULL)
		{
			tmp = ht[i];
			printf("ht[%zu]: ", i);
			while (tmp)
			{
				printf("{%s | X:%d Y:%d}", tmp->name, tmp->x, tmp->y);
				if (tmp->next != NULL)
					printf("-->");
				tmp = tmp->next;
			}
			printf("\n");
		}
		else
			printf("ht[%zu]:\n", i);
		i++;
	}
	printf("Nbr keys: %d | Load: %f\n", master->nbr_keys, load(master));
}
