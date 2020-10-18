/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:38:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/18 12:24:38 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_bucket	**create_ht(t_master *master)
{
	t_bucket	**ht;
	size_t		i;

	i = 0;
	if (!(ht = (t_bucket**)malloc(sizeof(t_bucket*) * (master->new_size + 1))))
		exit_malloc();
	while (i < master->new_size)
	{
		ht[i] = NULL;
		i++;
	}
	ht[i] = NULL;
	return (ht);
}

t_bucket	*create_bucket(void)
{
	t_bucket	*new;

	if (!(new = malloc(sizeof(t_bucket))))
		exit_malloc();
	new->entry = NULL;
	new->next = NULL;
	return (new);
}

void		start_or_end(char *s, t_master *master, char *name)
{
	if (ft_strequ(s, "start"))
		master->start_room = ft_strdup(name);
	else if (ft_strequ(s, "end"))
		master->end_room = ft_strdup(name);
}

t_entry		*create_and_fill_entry(t_master *master, char *line)
{
	t_entry *new;
	char	**data;

	if (!(new = (t_entry*)malloc(sizeof(t_entry))))
		exit_malloc();
	init_entry(new);
	data = ft_strsplit(line, ' ');
	new->name = ft_strdup(data[0]);
	new->x = ft_atoi(data[1]);
	new->y = ft_atoi(data[2]);
	new->key = gen_key(new->name);
	if (master->comment != NULL)
	{
		new->comment = ft_strdup(master->comment);
		start_or_end(new->comment, master, new->name);
		ft_strdel(&master->comment);
	}
	free_strsplit(&data);
	data = NULL;
	return (new);
}
