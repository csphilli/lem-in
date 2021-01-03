/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 18:47:11 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/03 20:48:08 by cphillip         ###   ########.fr       */
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
		ft_errorexit("ERROR: Invalid link format\n");
	else if (x == 0)
		ft_errorexit("ERROR: Input order must be ants > rooms > links.\n");
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

void	link_error_handling(t_bucket **ht, t_master *master, \
		char **data, char *line)
{
	t_entry *link0;
	t_entry *link1;

	link0 = get_entry(ht, data[0]);
	link1 = get_entry(ht, data[1]);
	if (!master->a_room)
		ft_errorexit("ERROR: Cannot insert link. No rooms defined.\n");
	if (!link0 || !link1)
		ft_errorexit("ERROR: Cannot insert link. Room not found.\n");
	chk_link_format(line);
	if (data[0][0] == 'L' || data[1][0] == 'L')
		ft_errorexit("ERROR: Link name cannot begin with 'L'.\n");
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
	data = ft_strsplit(line, '-');
	if (split_len(data) != 2)
		ft_errorexit("ERROR: Invalid link format.\n");
	link_error_handling(ht, master, data, line);
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
