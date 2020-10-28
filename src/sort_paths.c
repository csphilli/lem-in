/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 09:35:58 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/28 11:33:06 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_shortest_path(t_paths *paths)
{
	int			pos;
	int			min;
	int			i;
	int			len;

	pos = 0;
	min = 100000;
	i = 0;
	len = 1;
	while (i < bucket_arr_len(paths->c))
	{
		len = list_length(paths->c[i]);
		if (len <= min)
		{
			min = len;
			pos = i;
		}
		i++;
	}
	paths->s_index = pos;
}

void  swap(t_bucket *a, t_bucket *b)
{
	t_bucket	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int		sorted(t_paths *paths)
{
	int	len;
	int	x;
	int	y;
	int	i;

	len = bucket_arr_len(paths->p);
	i = 0;
	while (i < len - 1)
	{
		x = list_length(paths->p[i]);
		y = list_length(paths->p[i + 1]);
		if (x > y)
			return (0);
		i++;
	}
	return (1);
}

void	sort_chosen_paths(t_paths *paths)
{
	int	len;
	int	x;
	int	y;
	int	i;

	i = 0;
	len = bucket_arr_len(paths->p);
	while (i < len - 1)
	{
		if (i == len - 1)
			break ;
		x = list_length(paths->p[i]);
		y = list_length(paths->p[i + 1]);
		if (x > y)
		{
			swap(paths->p[i], paths->p[i + 1]);
			i = 0;
		}
		i++;
	}
}
