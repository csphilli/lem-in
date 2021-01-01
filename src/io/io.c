/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:28:14 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 17:23:47 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_io	*create_io(void)
{
	t_io	*new;

	if (!(new = ft_memalloc(sizeof(t_io))))
		return (NULL);
	if (!(new->buf = ft_strnew(IO_BUF)))
		return (NULL);
	new->output = NULL;
	new->o_len = 0;
	new->b_len = 0;
	new->next = NULL;
	return (new);
}

void	buf_to_output(t_io **main)
{
	t_io *head;
	t_io *tmp;

	head = *main;
	tmp = head;
	if (!(head->output))
	{
		head->output = ft_strdup((*main)->buf);
		head->o_len = (*main)->b_len;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_memalloc(sizeof(t_io));
		tmp->next->output = ft_strdup((*main)->buf);
		tmp->next->o_len = (*main)->b_len;
	}
	*main = head;
}

void	print_io(t_io *tgt, int i)
{
	t_io	*tmp;

	tmp = tgt;
	while (tmp)
	{
		write(1, tmp->output, tmp->o_len);
		tmp = tmp->next;
	}
	if (i == 1)
		write(1, "\n", 1);
}
