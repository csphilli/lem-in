/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 11:28:39 by cphillip         ###   ########.fr       */
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
	// ft_printf(">%s< | len: %d", new, ft_strlen(new));
	
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
	// ft_printf("In catmoves\n");
	// ft_printf("curdst: %s | %p\n", *dst, *dst);
	if (!*dst)
		*dst = ft_strdup(to_add);
	else
	{
		tmp = *dst;
		// ft_printf("tmp after deleting *dst: %s | %p\n", tmp, tmp);
		ltmp = ft_strlen(tmp);
		ladd = ft_strlen(to_add);
		new = ft_strnew(ltmp + ladd);
		// ft_printf("new1: %s\n", new);
		ft_strncpy(new, tmp, ltmp);
		// ft_printf("new2: %s\n", new);
		ft_strncat(new, to_add, ladd);
		// ft_printf("new3: %s\n", new);
		*dst = new;
		// ft_printf("dst at end: %s | %p\n", *dst, *dst);
		free(tmp);
		tmp = NULL;
		// ft_strdel(&new);
		// new = NULL;
	}
}



void	write_r2r(t_ants *ins, t_entry *entry1, t_entry *entry2, int i)
{
	char	*s;

	s = NULL;
	entry1->ant_id = entry2->ant_id;
	entry2->ant_id = 0;
	entry1->occ = 1;
	entry2->occ = 0;
	s = make_move(entry1->ant_id, entry1->name);
	// if (!ins->output)
	// 	ins->output = ft_strdup(s);
	// else
	// ins->output = cat_moves(ins, entry1->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	ft_strdel(&s);
	s = NULL;
	// ft_printf("%s", s);
	// cat_moves(&ins->output, s);
	// free(s);
	// s = NULL;
	// while (1)
	// {
		
	// }
	// ft_printf("%s", s);
	// ins->output = cat_moves(ins->output, s);
	// ft_printf("new way of writing moves: %s\n", ins->output);
	// ft_printf("L%d-%s", entry1->ant_id, entry1->name);
	// exit(1);
	// write(1, "r2r", 3);
}

void	write_r2e(t_ants *ins, t_entry *entry1, t_entry *entry2, int i)
{
	char	*s;

	s = NULL;
	s = make_move(entry2->ant_id, entry1->name);
	// if (!ins->output)
	// 	ins->output = ft_strdup(s);
	// else
	// ins->output = cat_moves(ins, entry2->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	// cat_moves(&ins->output, s);
	free(s);
	s = NULL;
	// ft_printf("%s", s);
	// ft_printf("L%d-%s", entry2->ant_id, entry1->name);
	entry2->ant_id = 0;
	entry2->occ = 0;
	ins->ants_e++;
	// while (1)
	// {
		
	// }
	// write(1, "r2e", 3);
}

void	write_s2r(t_ants *ins, t_entry *entry1, int i)
{
	// setbuf(stdout, NULL);
	// ft_printf("into s2r\n");
	char *s;

	s = NULL;
	s = make_move(ins->ant_id, entry1->name);
	// ft_printf("s: %p\n", s);
	// ins->output = cat_moves(ins, ins->ant_id, entry1->name);
	cat_moves(&ins->output, s);
	ft_strdel(&s);
	s = NULL;
	// ft_printf("moves: %s\n", ins->output);
	
	// ft_printf("%s", s);
	// ft_printf("L%d-%s", ins->ant_id, entry1->name);
	entry1->ant_id = ins->ant_id;
	entry1->occ = 1;
	ins->ant_id++;
	// while (1)
	// {
		
	// }
}

// int		most_ants(int *arr)
// {
// 	int max;
// 	int i;

// 	i = 0;
// 	max = 0;
// 	while (arr[i])
// 	{
// 		if (arr[i] >= max)
// 			max = arr[i];
// 		i++;
// 	}
// 	return (max);
// }
