/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:38:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 15:19:10 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	init_entry(t_entry *entry)
{
	entry->name = NULL;
	entry->comment = NULL;
	entry->x = '\0';
	entry->y = '\0';
	entry->key = '\0';
}

t_bucket 	**create_ht(t_master *master)
{
	t_bucket	**ht;
	size_t		i;

	i = 0;
	if (!(ht = malloc(sizeof(t_bucket*) * (master->new_size + 1))))
		exit_malloc();
	while (i < master->new_size)
	{
		ft_printf("Creating spot %zu in ht\n", i);
		if (!(ht[i] = malloc(sizeof(t_bucket))))
			exit_malloc();
		ht[i]->entry = NULL;
		ht[i]->next = NULL;
		i++;
	}
	ht[i] = NULL;
	print_ht(ht, master);
	return (ht);
}

t_bucket *create_bucket(void)
{
	t_bucket	*new;

	if (!(new = malloc(sizeof(t_bucket))))
		exit_malloc();
	new->entry = NULL;
	new->next = NULL;
	return (new);
}

t_entry *create_and_fill_entry(t_master *master, char *line)
{
	t_entry *new;
	char	**data;

	if (!(new = malloc(sizeof(t_entry))))
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
		ft_strdel(&master->comment);
	}
	ft_free_strsplit(data);
	return (new);
}
