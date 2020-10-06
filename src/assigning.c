/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assigning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/06 08:19:30 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		gen_key(char *str)
{
	int key;

	key = 0;
	while (*str)
	{
		if (*str >= (0 + '0') && *str <= (9 + '0'))
			key += (*str - 48);
		else if (*str >= 'a' && *str <= 'z')
			key += *str;
		else if (*str >= 'A' && *str <= 'Z')
			key += *str;
		str++;
	}
	return (key);
}

void	assign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t	index;

	index = entry->key % master->new_size;
	insert_node(ht, entry, index);
	master->room_count++;
	master->nbr_keys++;
}
