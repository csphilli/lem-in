/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_room_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 11:39:22 by cphillip          #+#    #+#             */
/*   Updated: 2020/09/20 07:47:55 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	free_split(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
			str[j][i++] = '\0';
		free(str[j]);
		j++;
	}
	free(str);
}

static void	validate_room_name(t_master *master, char *s)
{
	if (ft_strchr(s, 'L'))
		exit_error(master, "L_present");
}

t_room	*create_room_node(t_master *master, char *line)
{
	ft_printf("Inside Create New Node. Line: %s\n", line);
	t_room 	*new;
	char	**data;

	new = NULL;
	data = NULL;
	if (!(new = (t_room*)malloc(sizeof(t_room))))
		exit_error(master, "malloc");
	new = init_room(new);
	data = ft_strsplit(line, ' ');
	// ft_printf("data[%d]: %s | data[%d]: %d | data[%d]: %d\n", 0, data[0], 1, ft_atoi(data[1]), 2, ft_atoi(data[2]));
	new->name = ft_strdup(data[0]);
	validate_room_name(master, new->name);
	if (!ft_isdigit(data[1][0]))
		exit_error(master, "not_digit");
	new->x = ft_atoi(data[1]);
	if (!ft_isdigit(data[2][0]))
		exit_error(master, "not_digit");
	new->y = ft_atoi(data[2]);
	free_split(data);
	return(new);
}