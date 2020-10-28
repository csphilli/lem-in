/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:38:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/26 11:57:27 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket	**create_ht(t_master *master)
{
	t_bucket	**ht;
	size_t		i;

	i = 0;
	if (!(ht = (t_bucket**)malloc(sizeof(t_bucket*) * (master->new_size + 1))))
		exit_malloc();
	while (i < master->new_size)
	{
		ht[i] = NULL;
		i++;
	}
	ht[i] = NULL;
	return (ht);
}

t_bucket	*create_bucket(void)
{
	t_bucket	*new;

	if (!(new = (t_bucket*)malloc(sizeof(t_bucket))))
		exit_malloc();
	new->entry = NULL;
	new->next = NULL;
	return (new);
}

t_entry		*create_entry(void)
{
	t_entry	*entry;

	if (!(entry = (t_entry*)malloc(sizeof(t_entry))))
		exit_malloc();
	init_entry(entry);
	return (entry);
}
