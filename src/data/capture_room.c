/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 07:58:33 by cphillip          #+#    #+#             */
/*   Updated: 2021/01/01 22:33:52 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		ft_errorExit("ERROR: Coordinate contains non-digit value.\n");
	return (0);
}

int		c_atoi(const char *str)
{
	int i;
	int sign;
	int res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && digit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int		split_len(char **src)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = src;
	while (*tmp++)
		i++;
	return (i);
}

void	chk_valid_entry(char **data)
{
	if (data[0][0] == 'L')
		ft_errorExit("ERROR: Room names cannot begin with 'L'.\n");
	if (split_len(data) != 3)
		ft_errorExit("ERROR: Invalid room input.\n");
}

void	capture_room(t_bucket **ht, t_master *master, char *line)
{
	char	**data;
	t_entry	*dst;

	dst = ft_memalloc(sizeof(t_entry));
	data = ft_strsplit(line, ' ');
	chk_valid_entry(data);
	dst->name = ft_strdup(data[0]);
	dst->x = c_atoi(data[1]);
	dst->y = c_atoi(data[2]);
	if (master->comment != NULL)
	{
		dst->comment = ft_strdup(master->comment);
		start_or_end(master, dst);
		ft_strdel(&master->comment);
	}
	assign_entry_to_ht(ht, master, dst);
	free_strsplit(&data);
	data = NULL;
}
