/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/28 21:06:58 by cphillip         ###   ########.fr       */
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

void 	insert_into_ht(t_room **ht, t_master *master, char *line)
{
	t_room	*room;
	int		index;
	int		key;
	char	**data;

	data = ft_strsplit(line, ' ');
	if (!(room = (t_room*)malloc(sizeof(t_room))))
		exit_malloc();
	key = gen_key(data[0]);
	// ft_printf("inside insert\n");
	master->nbr_keys++;
	index = key % master->new_size;
	room = init_room(room, data, key, index, master);
	insert_node(ht, room, index);
	ft_free_strsplit(data);
	// ft_printf("Done with strsplit_free\n");
}

// void	insert_room(t_room *ht[], char *line, t_master *master) // must validate data on room names (no L) and that in values are ints
// {
// 	t_room *new;
// 	char **data;
// 	int index;
// 	int key;

// 	data = ft_strsplit(line, ' ');
// 	validate_coords(master, data[1], data[2]);
// 	new = (t_room*)malloc(sizeof(t_room));	
// 	key = gen_key(data[0]);
// 	index = key % HT_SIZE;
// 	if (ht[index] != NULL)
// 		index = probe(ht, index);
// 	new->index = index;
// 	new->name = ft_strdup(data[0]);
// 	new->x = ft_atoi(data[1]);
// 	new->y = ft_atoi(data[2]);
// 	new->on_line = master->line_nbr;
// 	if (master->comment != NULL)
// 	{
// 		new->comment = ft_strdup(master->comment);
// 		ft_strdel(&master->comment);
// 	}
// 	ht[index] = new;
// 	ft_free_strsplit(data);

// }


