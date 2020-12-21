/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 11:55:11 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_moves(t_output *output)
{
	t_output *tmp;

	tmp = output;
	while (tmp)
	{
		write(1, tmp->line, tmp->len);
		tmp = tmp->next;
	}
}

void	print_output(t_output *output)
{
	t_output *tmp;

	tmp = output;
	while (tmp)
	{
		write(1, tmp->line, tmp->len);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

void	print_links(t_bucket *src)
{
	t_bucket	*tmp;

	tmp = src;
	ft_printf(" | Links: ");
	while (tmp)
	{
		ft_printf("%s", tmp->entry->name);
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
				ft_printf("{Name: %s", tmp->entry->name);
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
