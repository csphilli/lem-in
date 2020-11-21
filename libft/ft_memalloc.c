/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:47:26 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/21 21:15:32 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
	{
		ft_printf("ERROR: Failed to allocate memory.\n");
		return (NULL);
	}
	ft_bzero(mem, size);
	return (mem);
}
