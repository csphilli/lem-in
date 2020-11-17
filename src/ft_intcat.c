/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 08:34:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/17 15:42:17 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	To be added to LIBFT once Lem-in completed
*/

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
	// if (!(src = (int*)malloc(sizeof(int) * (len + 2))))
	// 	exit(-1);
	if (!(src = ft_memalloc(sizeof(int) * (len + 2))))
		ft_error("Error: Failed to allocated memory.");
	// ft_init_int_arr(src, len + 2);
	while (i < len)
	{
		src[i] = tmp[i];
		i++;
	}
	src[i] = to_add;
	ft_init_int_arr(tmp, len);
	free(tmp);
	return (src);
}
