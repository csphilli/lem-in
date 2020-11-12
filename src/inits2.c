/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 09:04:00 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/12 14:17:42 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	init_instrux(t_ant_instrux *instrux)
{
	if (instrux)
	{
		instrux->ant_arr = NULL;
		instrux->moves_arr = NULL;
		instrux->max_index = 0;
		instrux->n_ants = 0;
	}
}

void	ft_init_int_arr(int *src, int len)
{
	int	i;

	i = 0;
	if (src)
	{
		while (i < len)
		{
			src[i] = '\0';
			i++;
		}
	}
}

// void	init_bfs(t_bfs *bfs)
// {
// 	if (bfs)
// 	{
// 		bfs->bfs = NULL;
// 		bfs->bfsq = NULL;
// 		bfs->exit = false;
// 		bfs->end = NULL;
// 		bfs->start = NULL;
// 		bfs->path_count = 0;
// 		// bfs->lolp = NULL;
// 		// bfs->lolq = NULL;
// 	}
// }
