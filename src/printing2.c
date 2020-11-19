/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:11:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/19 11:11:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_int_arr(int *arr)
{
	int i;

	i = 0;
	if (arr)
	{
		ft_printf("\nANT DISTRIBUTION ALONG PATHS FOR SOLVING\n");
		ft_printf("INDEX:\tANTS\n");
		while (arr[i])
		{
			ft_printf("%d", arr[i]);
			if (arr[i + 1])
				write(1, ",", 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	print_ll(t_bucket *ll)
{
	t_bucket *tmp;

	tmp = ll;
	if (tmp)
	{
		while (tmp)
		{
			if (tmp->entry->visited)
				ft_printf(RED);
			ft_printf("%s"RESET, tmp->entry->name);
			if (tmp->next)
				write(1, ",", 1);
			tmp = tmp->next;
		}
		write(1, "\n", 1);
	}
}

void	print_lol(t_lol **list)
{
	t_lol 		*tmp;

	tmp = *list;
	if (tmp)
	{
		while (tmp)
		{
			print_ll(tmp->list);
			tmp = tmp->next;
		}
	}
}




// WAS ONLY USED FOR DEBUGGING. NOT NEEDED ANYMORE.
// void		print_map(t_pmap *map)
// {
// 	t_pmap *tmp;

// 	tmp = map;
// 	while (tmp)
// 	{
// 		ft_printf("{f: %s | v: %s}", tmp->fnd->name, tmp->via->name);
// 		tmp->next ? write(1, "->", 2) : 1;
// 		tmp = tmp->next;
// 	}
// 	write(1, "\n", 1);
// }
