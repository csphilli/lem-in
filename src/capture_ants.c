/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/08/31 12:04:08 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// int	valid_int(char *str)
// {
// 	intmax_t	nbr;
// 	char		*tmp;

// 	tmp = str;
// 	// if (*tmp == '+' || *tmp == '-')
// 	// 	tmp++;
// 	while (*tmp)
// 	{
// 		if (!ft_isdigit(*tmp))
// 			invalid_input(stacks, tmp);
// 		tmp++;
// 	}
// 	nbr = ft_atoimax(str);
// 	if (nbr >= (-2147483647 - 1) && nbr <= 2147483648)
// 		return (nbr);
// 	else
// 	{
// 		stacks->advanced == 1 ? ft_printf(ER_SIZE) : ft_printf(ERROR);
// 		exit(-1);
// 	}
// 	return (0);
// }

void	capture_ants(t_master *master, char *line)
{
	int nbr_ants;

	nbr_ants = 0;
	nbr_ants = ft_atoi(line);
	
	ft_printf("in capture ants\n");
	ft_printf("line: %s\n", line);
	master->nbr_ants = 10;
}