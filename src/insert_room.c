/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/23 08:39:41 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_split(char **str) // Move this to Lib once hashing is verified to function.
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
			str[j][i++] = '\0';
		free(str[j]);
		j++;
	}
	free(str);
}

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
	if (master->comment != NULL)
		new->comment = master->comment;
	ht[index] = new;
	free_split(data);
}

void	print_ht(t_room *ht[])
{
	int i;

	i = 0;
	while (i < HT_SIZE)
	{
		if (ht[i] != 0)
			printf("HT[%d]:\n Room Key: %d\n Room Name: %s\n", i, ht[i]->index, ht[i]->name);
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