/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_distro_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 08:34:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/02 22:19:54 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_int_arr_len(int *n)
{
	int	i;

	i = 0;
	while (n[i])
		i++;
	return (i);
}

int		*ft_intcat(int *src, int to_add)
{
	int		*tmp;
	int		len;
	int		i;

	i = 0;
	tmp = src;
	len = (src == NULL ? 0 : ft_int_arr_len(src));
	src = ft_memalloc(sizeof(int) * (len + 2));
	while (i < len)
	{
		src[i] = tmp[i];
		i++;
	}
	src[i] = to_add;
	free_intarray(tmp, len);
	free(tmp);
	return (src);
}

void	create_path_array(t_lol *paths)
{
	t_lol		*tmp;
	int			*arr;

	arr = NULL;
	tmp = paths;
	while (tmp)
	{
		if (tmp->nbr_ants > 0)
			arr = ft_intcat(arr, tmp->nbr_ants);
		tmp = tmp->next;
	}
}

void	build_distro_array(t_bfs *bfs)
{
	t_lol *tmp;

	tmp = bfs->paths;
	while (tmp)
	{
		if (tmp->nbr_ants > 0)
		{
			bfs->s_distro = ft_intcat(bfs->s_distro, tmp->nbr_ants);
			bfs->moves = ft_intcat(bfs->moves, tmp->total_moves);
		}
		tmp = tmp->next;
	}
}
