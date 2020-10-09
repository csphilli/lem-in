/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:55:45 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/03 20:36:21 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"

void	free_strsplit(char ***array)
{
	char **current;

	if (array && *array)
	{
		current = ((*array));
		while ((*current))
			free((*(current++)));
		free((*array));
		(*array) = NULL;
	}
}