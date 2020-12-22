/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:12:03 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/22 11:23:07 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_master	*create_structs(void)
{
	t_master *new;

	new = ft_memalloc(sizeof(t_master));
	new->ants = ft_memalloc(sizeof(t_ants));
	new->bfs = ft_memalloc(sizeof(t_bfs));
	new->flags.s_toggle = false;
	new->flags.e_toggle = false;
	new->flags.print_hash_table = false;
	new->flags.print_paths = false;
	new->flags.vis_distro = false;
	new->flags.accepted_flags = "dhpte";
	new->line_nbr = 1;
	new->ants->ant_id = 1;
	return (new);
}
