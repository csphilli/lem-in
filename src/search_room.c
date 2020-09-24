/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 20:20:37 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/24 20:58:20 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void exit_failed_search(void)
{
	ft_printf(E_FAILED_SEARCH);
	exit(-1);
}

static int search_probe(t_room *ht[], int index, char *name)
{
	while (ft_strcmp(ht[index]->name, name) != 0)
		index = (index + 1) % HT_SIZE;
	return (index);
}

int	room_search(t_room *ht[], char *name)
{
	int index;
	int	key;

	key = gen_key(name);
	// ft_printf("key: %d\n", key);
	index = key % HT_SIZE;
	// ft_printf("index: %d\n", index);
	if (ht[index] == NULL)
		exit_failed_search();
	else if (ft_strcmp(ht[index]->name, name) != 0)
		index = search_probe(ht, index, name);
	// ft_printf("index: %d\n", index);
	return (index);
}

static void	p_results(t_room *ht[], int index)
{
	if (index)
		ft_printf("Room found! Added on line %d\n", ht[index]->on_line);
}

void	test_room_search(t_room *ht[], char *name)
{
	int index;

	index = 0;
	index = room_search(ht, name);
	p_results(ht, index);
}