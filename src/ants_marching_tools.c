/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/03 20:10:02 by cphillip         ###   ########.fr       */
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

void	cat_move(t_ants *ins, int ant_id, char *name)
{
	char	*str;

	str = create_move(ins, ant_id, name);
	if (ins->input == NULL)
		ins->input = ft_strnew(LINEBUF);
	ins->input = ft_strcat(ins->input, str);
	ins->l += ft_strlen(str);
	ft_strdel(&str);
	str = NULL;
	if (ins->l > LINEBUF - 50)
	{
		ft_strcat(ins->input, "\0");
		append_move(ins, &ins->output);
		ft_strdel(&ins->input);
		ins->input = ft_strnew(LINEBUF);
		ins->l = 0;
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
		cat_move(ins, id, master->end_room->name);
		ants_e++;
		id++;
	}
	if (ins->l < LINEBUF)
	{
		ft_strcat(ins->input, "\0");
		append_move(ins, &ins->output);
	}
	ins->n_moves++;
}
