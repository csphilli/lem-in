/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_marching_tools.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 23:27:17 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 11:20:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*create_move(t_master *master, int id, char *name)
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
	len += (master->ants->i == 1 ? 1 : 0);
	new = ft_strnew(len);
	if (master->ants->i == 1)
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

void	cat_move(t_master *master, int ant_id, char *name)
{
	char	*str;

	if (!(master->moves))
		master->moves = create_io();
	str = create_move(master, ant_id, name);
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

void	do_one_move(t_master *master)
{
	int			ants_e;
	int			id;

	ants_e = 1;
	id = 2;
	while (ants_e < master->nbr_ants)
	{
		cat_move(master, id, master->end_room->name);
		ants_e++;
		id++;
	}
	if (master->moves->b_len < IO_BUF)
	{
		ft_strcat(master->moves->buf, "\0");
		buf_to_output(&master->moves);
	}
	master->ants->n_moves++;
}
