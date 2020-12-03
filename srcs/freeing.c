/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:51:53 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/03 19:27:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_node(t_bucket *node)
{
	free_entry(node->entry);
	free_bucket(node);
	node = NULL;
}

void	free_entry(t_entry *entry)
{
	int	i;

	i = 0;
	if (entry->name)
		ft_strdel(&entry->name);
	if (entry->comment)
		ft_strdel(&entry->comment);
	while (entry->links)
		pop_from_ll(&entry->links);
	entry->links = NULL;
	free(entry);
	entry = NULL;
}

void	free_bucket(t_bucket *bucket)
{
	bucket->entry = NULL;
	bucket->next = NULL;
	free(bucket);
	bucket = NULL;
}

void	free_ins(t_ants *ins)
{
	ft_strdel(&ins->input);
	dlt_output(ins);
	ins->output = NULL;
	ins->n_moves = '\0';
	ins->l = '\0';
	ins->ants_s = '\0';
	ins->ants_e = '\0';
	ins->max_ant = '\0';
	ins->ant_id = '\0';
	free(ins);
}
