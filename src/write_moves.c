/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 14:38:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*make_move(int ant_id, char *entry_name)
{
	char	*new;
	int		ilen;
	int		slen;
	char	*ant_name;
	char	*name;

	name = ft_strdup(entry_name);
	ant_name = ft_itoa(ant_id);
	ilen = ft_nbr_size(ant_id);
	slen = ft_strlen(name);
	new = ft_memalloc(sizeof(char) * (ilen + slen + 4));
	ft_strncat(new, "L", 1);
	ft_strncat(new, ant_name, ilen);
	ft_strncat(new, "-", 1);
	ft_strncat(new, name, slen);
	ft_strncat(new, " ", 1);
	free(name);
	free(ant_name);
	name = NULL;
	ant_name = NULL;	
	return (new);
}

void	cat_moves(char **dst, char *to_add)
{
	char	*tmp;
	int		ltmp;
	int		ladd;
	char	*new;

	ltmp = 0;
	ladd = 0;
	new = NULL;
	if (!*dst)
		*dst = ft_strdup(to_add);
	else
	{
		tmp = *dst;
		ltmp = ft_strlen(tmp);
		ladd = ft_strlen(to_add);
		new = ft_strnew(ltmp + ladd);
		ft_strncpy(new, tmp, ltmp);
		ft_strncat(new, to_add, ladd);
		*dst = new;
		free(tmp);
		tmp = NULL;
	}
}

void	write_r2r(t_ants *ins, t_entry *entry1, t_entry *entry2)
{
	char	*s;

	s = NULL;
	entry1->ant_id = entry2->ant_id;
	entry2->ant_id = 0;
	entry1->occ = 1;
	entry2->occ = 0;
	s = make_move(entry1->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	ft_strdel(&s);
	s = NULL;
}

void	write_r2e(t_ants *ins, t_entry *entry1, t_entry *entry2)
{
	char	*s;

	s = NULL;
	s = make_move(entry2->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	free(s);
	s = NULL;
	entry2->ant_id = 0;
	entry2->occ = 0;
	ins->ants_e++;
}

void	write_s2r(t_ants *ins, t_entry *entry1)
{
	char *s;

	s = NULL;
	s = make_move(ins->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	ft_strdel(&s);
	s = NULL;
	entry1->ant_id = ins->ant_id;
	entry1->occ = 1;
	ins->ant_id++;
}