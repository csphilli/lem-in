/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:08:18 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/28 12:10:07 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Prints a single path from the array.
*/

void	print_path(t_bucket *head)
{
	t_bucket *tmp;

	tmp = head;
	while (tmp)
	{
		ft_printf("%s", tmp->entry->name);
		if (tmp->next)
			ft_printf(",");
		tmp = tmp->next;
	}
	// ft_printf("\n");
}

/*
**	Prints all paths in a path array.
*/

void	print_paths(t_bucket **paths)
{
	t_bucket	**tmp;
	t_bucket	*curr;
	int			i;

	tmp = paths;
	i = 0;
	while (i < bucket_arr_len(paths))
	{
		curr = tmp[i];
		ft_printf("[%d]: ", i);
		while (curr)
		{
			ft_printf("%s", curr->entry->name);
			if (curr->next)
				ft_printf(",");
			curr = curr->next;
		}
		ft_printf("\n");
		i++;
	}
}

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
	if (entry->comment)
		ft_printf(" | Comment: %s", entry->comment);
	if (entry->link_arr)
		print_links(entry->link_arr);
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
