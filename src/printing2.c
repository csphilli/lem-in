/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:11:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 20:41:57 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_int_arr(int *ants)
{
	int i;

	i = 0;
	ft_printf("\nANT DISTRIBUTION ALONG PATHS FOR SOLVING\n");
	ft_printf("INDEX:\tANTS\n");
	while (ants[i])
	{
		ft_printf("[%4d]:\t%d", i, ants[i]);
		if (ants[i + 1])
			ft_printf("\n");
		i++;
	}
	ft_printf("\n");
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
