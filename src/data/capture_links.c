/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 22:37:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	chk_link_format(char *line)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			x++;
		i++;
	}
	if (x > 1)
		ft_errorExit("ERROR: Invalid link format\n");
}

int		dupe_link(t_entry *src, t_entry *add)
{
	t_bucket *tmp;

	tmp = src->links;
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (ft_strequ(tmp->entry->name, add->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	capture_links(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	int		index;
	t_entry	*entry;
	int		i;
	int		j;

	i = 0;
	j = 1;
	chk_link_format(line);
	data = ft_strsplit(line, '-');
	if (!master->a_room)
		ft_errorExit("ERROR: Cannot insert link. No rooms defined.\n");
	while (i < 2)
	{
		entry = get_entry(ht, data[i]);
		index = hash(entry->name);
		if (!(dupe_link(entry, get_entry(ht, data[j]))))
			insert_to_ll(&entry->links, get_entry(ht, data[j]));
		i++;
		j--;
	}
	master->link = 1;
	free_strsplit(&data);
	data = NULL;
}
