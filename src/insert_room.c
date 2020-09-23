/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/23 11:59:16 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"



static int	hash_code(int key)
{
	return (key % HT_SIZE);
}

int gen_key(char *str)
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

static int	probe(t_room *ht[], int index)
{
	while (ht[index] != 0)
		index = (index + 1) % HT_SIZE;
	return (index);
}

void	insert_room(t_room *ht[], char *line, t_master *master) // must validate data on room names (no L) and that in values are ints
{
	t_room *new;
	char **data;
	int index;
	int key;

	data = ft_strsplit(line, ' ');
	new = (t_room*)malloc(sizeof(t_room));	
	key = gen_key(data[0]);
	index = hash_code(key);
	if (ht[index] != NULL)
		index = probe(ht, index);
	new->index = index;
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	if (master->comment != NULL) // fix comments. Not deleting after inserting properly
		new->comment = master->comment;
	ht[index] = new;
	ft_free_strsplit(data);
}

void	print_ht(t_room *ht[])
{
	int i;

	i = 0;
	while (i < HT_SIZE)
	{
		if (ht[i] != 0)
		{
			ft_printf("HT[%d]:\n Room Index: %d\n Room Name: %s\n"\
				, i, ht[i]->index, ht[i]->name);
			ft_printf(" X: %d\n Y: %d\n", ht[i]->x, ht[i]->y);
			ht[i]->comment != NULL ? ft_printf(" Comment: %s\n"\
			, ht[i]->comment) : ft_printf(" Comment: ---\n");
		}
		i++;
	}
}

// void	insert(t_room *ht[], char *name, t_master *master)
// {
// 	t_room *new;
// 	new = (t_room*)malloc(sizeof(t_room));
// 	int index;
// 	int key;
// 	key = gen_key(name);
// 	index = hash_code(key);
// 	if (ht[index] != NULL)
// 		index = probe(ht, index);
// 	new->index = index;
// 	new->name = ft_strdup(name);
// 	ht[index] = new;
// }