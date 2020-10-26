/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/25 09:50:30 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			gen_key(char *str)
{
	int		key;

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

t_entry		*fill_entry_from_line(t_master *master, t_entry *dst, char *line)
{
	char	**data;

	data = ft_strsplit(line, ' ');
	dst->name = ft_strdup(data[0]);
	dst->x = ft_atoi(data[1]);
	dst->y = ft_atoi(data[2]);
	dst->key = gen_key(dst->name);
	if (master->comment != NULL)
	{
		dst->comment = ft_strdup(master->comment);
		start_or_end(dst->comment, master, dst->name);
		ft_strdel(&master->comment);
	}
	free_strsplit(&data);
	data = NULL;
	return (dst);
}

t_entry		*copy_entry(t_entry *src)
{
	t_entry	*dst;
	int		len;
	int		i;

	len = 0;
	i = 0;
	dst = create_entry();
	if (src->comment)
		dst->comment = ft_strdup(src->comment);
	if (src->link_arr)
	{
		len = link_array_len(src->link_arr);
		while (i < len)
			insert_link(dst, src->link_arr[i++]);
	}
	dst->name = ft_strdup(src->name);
	dst->key = src->key;
	dst->x = src->x;
	dst->y = src->y;
	dst->visited = src->visited;
	return (dst);
}

/*
**	dup_coord function located in validate_coords.c
*/

void		assign_entry_to_ht(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t	index;

	if (!dup_coord(ht, master, entry))
	{
		index = entry->key % master->new_size;
		insert_node(ht, entry, index);
		master->room_count++;
		master->nbr_keys++;
	}
	else
		exit_dup_coord(master);
}
