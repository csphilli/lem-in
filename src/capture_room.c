/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 20:55:34 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	scan_index(t_bucket *head, size_t index)
{
	t_bucket	*tmp;
	t_bucket	*test;

	tmp = head;
	while (tmp)
	{
		if (!tmp->next)
			break ;
		else
		{
			test = tmp->next;
			while (test->next)
			{
				if (ft_strequ(test->entry->name, tmp->entry->name))
					exit_dup(test->entry->name, index);
				test = test->next;
			}
		}
		tmp = tmp->next;
	}
}

void	validate_rooms(t_bucket **ht, t_master *master)
{
	size_t	i;

	i = 0;
	while (i < master->new_size)
	{
		if (ht[i])
			scan_index(ht[i], i);
		i++;
	}
}

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

t_entry		*capture_room(t_master *master, t_entry *dst, char *line)
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
		start_or_end(master, dst);
		ft_strdel(&master->comment);
	}
	free_strsplit(&data);
	data = NULL;
	return (dst);
}

