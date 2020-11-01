/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:11:59 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/01 14:17:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_paths(t_paths *paths)
{
	delete_old_path(paths->p);
	delete_old_path(paths->c);
	free_entry(paths->s_room);
	free_entry(paths->e_room);
	paths->max_paths = '\0';
	paths->s_index = '\0';
	paths->index = '\0';
	paths->p_len = '\0';
	paths->c_len = '\0';
	paths->collision = '\0';
	paths->nbr_moves = '\0';
	paths->nbr_ants_s = '\0';
	paths->nbr_ants_e = '\0';
	paths->ant_id = '\0';
	paths->max_id = '\0';
	free(paths);
	paths = NULL;
}
