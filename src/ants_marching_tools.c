/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 19:53:51 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	append_move(t_ants *ins, t_output **output)
{
	t_output *head;
	t_output *tmp;

	head = *output;
	tmp = head;
	if (!head)
	{
		head = ft_memalloc(sizeof(t_output));
		head->line = ft_strdup(ins->input);
		head->len = ins->l;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_output));
		tmp->next->line = ft_strdup(ins->input);
		tmp->next->len = ins->l;
	}
	*output = head;
}

char	*create_move(t_ants *ins, int id, char *name)
{
	char	*new;
	char	*ant_id;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ant_id = ft_itoa(id);
	len = ft_strlen(name) + ft_strlen(ant_id) + 2;
	len += (ins->i == 1 ? 1 : 0);
	new = ft_strnew(len);
	if (ins->i == 1)
		new[i++] = ' ';
	new[i++] = 'L';
	while (ant_id[j])
		new[i++] = ant_id[j++];
	new[i++] = '-';
	j = 0;
	while (name[j])
		new[i++] = name[j++];
	ft_strdel(&ant_id);
	ant_id = NULL;
	return (new);
}

void	cat_move(t_master *master, t_ants *ins, int ant_id, char *name)
{
	char	*str;

	if (!(master->moves))
		master->moves = create_io();
	str = create_move(ins, ant_id, name);
	master->moves->buf = ft_strcat(master->moves->buf, str);
	master->moves->b_len += ft_strlen(str);
	ft_strdel(&str);
	str = NULL;
	if (master->moves->b_len > IO_BUF - 50)
	{
		ft_strcat(master->moves->buf, "\0");
		buf_to_output(&master->moves);
		ft_strdel(&master->moves->buf);
		master->moves->buf = ft_strnew(IO_BUF);
		master->moves->b_len = 0;
	}
}

void	dlt_output(t_ants *ins)
{
	t_output	*cur;
	t_output	*tmp;

	cur = NULL;
	tmp = ins->output;
	while (tmp)
	{
		cur = tmp;
		tmp = tmp->next;
		ft_strdel(&cur->line);
		cur->line = NULL;
		cur->next = NULL;
		cur->len = '\0';
		free(cur);
		cur = NULL;
	}
}

void	do_one_move(t_master *master, t_ants *ins)
{
	int			ants_e;
	int			id;

	ants_e = 1;
	id = 2;
	while (ants_e < master->nbr_ants)
	{
		cat_move(master, ins, id, master->end_room->name);
		ants_e++;
		id++;
	}
	if (master->moves->b_len < IO_BUF)
	{
		ft_strcat(master->moves->buf, "\0");
		buf_to_output(&master->moves);
	}
	ins->n_moves++;
}
