/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ht.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/08 13:55:00 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_links(t_entry *entry)
{
	char	**tmp;
	int		len;
	int		i;

	len = 0;
	i = 0;
	tmp = entry->link_arr;
	while (*tmp++)
		len++;
	ft_printf(" | Links:");
	while (i < len)
		ft_printf(" %s", entry->link_arr[i++]);
	ft_printf("}");
}

void	print_extras(t_entry *entry)
{
	if (entry->comment)
	{
		ft_printf(" | Comment: %s", entry->comment);
	}
	if (entry->link_arr)
	{
		ft_printf(" | Links: ");
		while (*(entry->link_arr))
			ft_printf(" %s", *(entry->link_arr++));
	}
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
