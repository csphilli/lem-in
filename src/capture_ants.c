/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_ants.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 10:12:54 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/21 23:59:06 by cphillip         ###   ########.fr       */
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

void	capture_ants(t_master *master, char *line)
{
	intmax_t	max_ants;
	int			ants;

	ants = 0;
	if (*line == '\0' || *line == ' ' || !validate_ants(line))
		master->flags.errors ? ft_error("ERROR: Invalid ant definition format") :\
		ft_error("ERROR");
	max_ants = ft_atoimax(line);
	if (max_ants < 1 || max_ants > 2147483647)
		master->flags.errors ? ft_error("ERROR: Invalid ant size.") :\
		ft_error("ERROR");
	ants = ft_atoi(line);
	master->nbr_ants = ants;
	master->flags.ants_added = true;
}
