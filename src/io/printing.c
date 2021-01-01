/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/30 18:34:39 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


void	print_links(t_bucket *src)
{
	t_bucket	*tmp;

	tmp = src;
	ft_printf(" | Links: ");
	while (tmp)
	{
		ft_printf("<%s|c:%d/f:%d>", tmp->entry->name, tmp->cap, tmp->edge_flow);
		if (tmp->next)
			write(1, ",", 1);
		tmp = tmp->next;
	}
}

void	print_extras(t_entry *entry)
{
	t_entry *tmp;

	tmp = entry;
	if (entry->comment)
		ft_printf(" | Comment: %s", entry->comment);
	if (entry->links)
		print_links(entry->links);
	write(1, "}", 1);
}

void	print_ht(t_bucket **ht)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i < TABLE_SIZE)
	{
		if (ht[i] != NULL)
		{
			ft_printf("HT[%d]: ", i);
			tmp = ht[i];
			while (tmp != NULL)
			{
				ft_printf("{Name: %s|v: %d", tmp->entry->name, tmp->entry->visited);
				// if (tmp->entry->flow_to)
				// 	ft_printf(" | flow_to: %s", tmp->entry->flow_to->name);
				// if (tmp->entry->flow_to->name)
				// 	ft_printf("%s", tmp->entry->flow_to->name);
				print_extras(tmp->entry);
				if (tmp->next)
					ft_printf("-->");
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
		i++;
	}
}
