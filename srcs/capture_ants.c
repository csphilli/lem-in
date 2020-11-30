/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/30 16:12:28 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validate_ants(char *line)
{
	char	*tmp;

	tmp = line;
	if (tmp)
	{
		while (*tmp)
		{
			if (!ft_isdigit(*tmp))
				return (0);
			tmp++;
		}
		return (1);
	}
	return (0);
}

void		valid_int_test(char *s)
{

	if (*s == '\0')
		ft_error("ERROR: Missing ant amount.");
	else if (*s == ' ')
		ft_error("ERROR: Space preceding ant value.");
	if (validate_ants(s) == 0)
		ft_error("ERROR: Invalid ant amount specified.");
}

void	capture_ants(t_master *master, char *line)
{
	intmax_t 	max_ants;
	int			ants;

	ants = 0;
	valid_int_test(line);
	max_ants = ft_atoimax(line);
	if (max_ants < 1 || max_ants > 2147483647)
		ft_error("ERROR");
	ants = ft_atoi(line);
	master->nbr_ants = ants;
	master->ants_added = true;
	// ft_printf("ants: %d\n", ants);
}

/*
void	capture_ants(t_master *master, char *line)
{
	int nbr_ants;

	nbr_ants = valid_int_test(line);
	master->nbr_ants = nbr_ants;
	master->ants_added = true;
}
*/
