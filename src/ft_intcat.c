/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 08:34:27 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/22 14:50:22 by cphillip         ###   ########.fr       */
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
	if (!(src = ft_memalloc(sizeof(int) * (len + 2))))
		ft_error("ERROR: Failed to allocated memory.");
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
