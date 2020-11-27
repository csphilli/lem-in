/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/27 23:37:56 by cphillip         ###   ########.fr       */
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
