/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/01 13:34:04 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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



// int	probe(t_room *ht[], int index)
// {
// 	while (ht[index] != 0)
// 		index = (index + 1) % HT_SIZE;
// 	return (index);
// }

void 	insert_into_ht(t_room **ht, t_master *master, t_room *room)
{
	// t_room	*room;
	int		index;
	// int		key;
	// char	**data;

	// data = ft_strsplit(line, ' ');
	// if (!(room = (t_room*)malloc(sizeof(t_room))))
		// exit_malloc();
	// key = gen_key(room->name);
	// ft_printf("inside insert\n");
	master->nbr_keys++;
	index = room->key % master->new_size;
	// room->key = key;
	// room = init_room(room, data, key, index, master);
	insert_node(ht, room, index);
	// ft_free_strsplit(data);
	// ft_printf("Done with strsplit_free\n");
}

t_room *create_room(void)
{
	t_room *new;

	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit_malloc();
	new->x = '\0';
	new->y = '\0';
	new->key = '\0';
	new->on_line = '\0';
	new->name = NULL;
	new->comment = NULL;
	new->start_or_end = NULL;
	new->occupied = false;
	new->next = NULL;
	new->links = NULL;
	return (new);
}

void	fill_room(t_room *room, t_master *master, char *line)
{
	char	**data;

	data = ft_strsplit(line, ' ');
	room->name = ft_strdup(data[0]);
	room->x = ft_atoi(data[1]);
	room->y = ft_atoi(data[2]);
	room->key = gen_key(room->name);
	if (master->comment != NULL)
	{
		room->comment = ft_strdup(master->comment);
		ft_strdel(&master->comment);
	}
	// room->on_line = master->line_nbr;
	ft_free_strsplit(data);
}
