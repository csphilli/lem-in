/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 10:47:43 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/20 10:47:18 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*make_str(int ant_id, char *name)
{
	char	*new;
	int		ilen;
	int		slen;

	ilen = ft_intlen_max(ant_id);
	slen = ft_strlen(name);

	new = ft_strnew(sizeof(char) * (ilen + slen + 2));
	new = ft_strncat(new, "L", 1);
	new = ft_strncat(new, ft_itoa(ant_id), ilen);
	new = ft_strncat(new, "-", 1);
	new = ft_strncat(new, name, slen);
}

void	write_r2r(t_entry *entry1, t_entry *entry2)
{
	entry1->ant_id = entry2->ant_id;
	entry2->ant_id = 0;
	entry1->occ = 1;
	entry2->occ = 0;
	ft_printf("L%d-%s", entry1->ant_id, entry1->name);
	// write(1, "r2r", 3);
}

void	write_r2e(t_ants *ins, t_entry *entry1, t_entry *entry2)
{
	ft_printf("L%d-%s", entry2->ant_id, entry1->name);
	entry2->ant_id = 0;
	entry2->occ = 0;
	ins->ants_e++;
	// write(1, "r2e", 3);
}

void	write_s2r(t_ants *ins, t_entry *entry1)
{
	ft_printf("L%d-%s", ins->ant_id, entry1->name);
	entry1->ant_id = ins->ant_id;
	entry1->occ = 1;
	ins->ant_id++;
	// paths->nbr_ants_s--;
	// write(1, "s2r", 3);
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
