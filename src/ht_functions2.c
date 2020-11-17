/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:38:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 14:56:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket	**create_ht(t_master *master)
{
	t_bucket	**ht;
	size_t		i;

	i = 0;
	// if (!(ht = (t_bucket**)malloc(sizeof(t_bucket*) * (master->new_size + 1))))
	// 	exit_malloc();
	if (!(ht = ft_memalloc(sizeof(t_bucket) * (master->new_size + 1))))
		ft_error("Error. Failed to allocate memory for hash table.");
	while (i < master->new_size)
	{
		ht[i] = NULL;
		i++;
	}
	ht[i] = NULL;
	return (ht);
}
