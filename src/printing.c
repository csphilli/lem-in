/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/24 15:03:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_links(t_bucket *src)
{
	setbuf(stdout, NULL);
	t_bucket	*tmp;

	tmp = src;
	ft_printf(" | Links/Cap/Vis: ");
	while (tmp)
	{
		ft_printf("%s/%d/%d", tmp->entry->name, tmp->cap, tmp->entry->visited);
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

void	print_ht(t_bucket **ht, size_t size)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i < size)
	{
		ft_printf("HT[%d]: ", i);
		if (ht[i] != NULL)
		{
			tmp = ht[i];
			while (tmp != NULL)
			{
				ft_printf("{Name: %s", tmp->entry->name);
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
