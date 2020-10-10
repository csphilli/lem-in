/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/10 13:49:40 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_links(t_entry **arr)
{
	int		i;

	i = 0;
	ft_printf(" | Links:");
	while (arr[i])
	{
		ft_printf(" %s", arr[i]->name);
		i++;
	}
}

void	print_extras(t_entry *entry)
{
	t_entry *tmp;

	tmp = entry;
	if (tmp->comment)
	{
		ft_printf(" | Comment: %s", tmp->comment);
	}
	if (tmp->link_arr)
		print_links(tmp->link_arr);
	ft_printf("}");
}

void	print_ht(t_bucket **ht, size_t size)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i < size)
	{
		ft_printf("HT[%2d]: ", i);
		if (ht[i] != NULL)
		{
			tmp = ht[i];
			while (tmp != NULL)
			{
				ft_printf("{Name: %s | Key: %d", tmp->entry->name,\
				tmp->entry->key);
				print_extras(tmp->entry);
				if (tmp->next)
					ft_printf("-->");
				tmp = tmp->next;
			}
		}
		ft_printf("\n");
		i++;
	}
}
