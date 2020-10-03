/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_ht.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 19:18:44 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:04:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket 	**realloc_ht(t_bucket **src, t_master *master)
{
	ft_printf("%d\n", src[0]->entry->name);
	ft_printf("%d\n", master->nbr_ants);
	return (0);
}

t_bucket 	**grow_ht(t_bucket **ht, t_master *master)
{
	t_bucket **new;

	master->old_size = master->new_size;
	master->new_size *= 2;
	master->nbr_keys = 0;
	new = realloc_ht(ht, master);
	return (new);
}


