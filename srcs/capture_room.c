/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/01 09:30:57 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	validate_coords(t_master *master, char *n1, char *n2)
{
	int i;

	i = 0;
	while (n1[i])
	{
		if (!ft_isdigit(n1[i]))
			exit_coord(master->line_nbr);
		i++;
	}
	i = 0;
	while (n2[i])
	{
		if (!ft_isdigit(n2[i]))
			exit_coord(master->line_nbr);
		i++;
	}
}

int		dup_coord(t_bucket **ht, t_master *master, t_entry *entry)
{
	size_t		i;
	t_bucket	*tmp;

	i = 0;
	tmp = NULL;
	while (i < master->new_size)
	{
		if (ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				if (tmp->entry->x == entry->x && tmp->entry->y == entry->y)
					return (1);
				tmp = tmp->next;
			}
		}
		i++;
	}
	return (0);
}

int		split_len(char **src)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = src;
	while (*tmp++)
		i++;
	return (i);
}

void	capture_room(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	t_entry	*dst;

	dst = ft_memalloc(sizeof(t_entry));
	data = ft_strsplit(line, ' ');
	if (data[0][0] == 'L')
		ft_error("ERROR: Room names cannot begin with 'L'");
	if (split_len(data) == 3)
	{
		dst->name = ft_strdup(data[0]);
		dst->x = ft_atoi(data[1]);
		dst->y = ft_atoi(data[2]);
		dst->key = gen_key(dst->name);
		if (master->comment != NULL)
		{
			dst->comment = ft_strdup(master->comment);
			start_or_end(master, dst);
			ft_strdel(&master->comment);
		}
		assign_entry_to_ht(ht, master, dst);
		free_strsplit(&data);
		data = NULL;
	}
	else
		ft_error("ERROR. Rooms need a name and x and y coord.");
}
