/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 14:51:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/12/23 21:52:14 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"



void	init_moves(t_distro *moves)
{
	t_distro	*tmp;
	int		i;

	tmp = moves;
	i = 0;
	if (tmp)
	{
		while (tmp)
		{
			tmp->index = i;
			tmp->len = list_length(tmp->list);
			tmp->cap = tmp->len - 1;
			tmp = tmp->next;
			i++;
		}
	}
}

// void	init_caps2(t_bucket *head)
// {
// 	t_bucket	*tmp;
// 	t_bucket	*links;

// 	tmp = head;
// 	while (tmp)
// 	{
// 		links = tmp->entry->links;
// 		while (links)
// 		{
// 			links->cap = 1;
// 			links->res->cap = 1;
// 			links = links->next;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void	init_caps(t_bucket **ht)
// {
// 	t_bucket	*tmp;
// 	t_bucket	*links;
// 	size_t		i;

// 	i = 0;
// 	tmp = NULL;
// 	links = NULL;
// 	while (i < TABLE_SIZE)
// 	{
// 		if (ht[i])
// 		{
// 			tmp = ht[i];
// 			init_caps2(tmp);
// 		}
// 		i++;
// 	}
// }



void	init_caps(t_bucket **ht)
{
	t_bucket	*tmp;
	t_bucket	*links;
	size_t		i;

	i = 0;
	tmp = NULL;
	links = NULL;
	while (i < TABLE_SIZE)
	{
		if (ht[i])
		{
			tmp = ht[i];
			while (tmp)
			{
				links = tmp->entry->links;
				while (links)
				{
					links->cap = 1;
					links = links->next;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	free_intarray(int *src, int len)
{
	int	i;

	i = 0;
	if (src)
	{
		while (i < len)
		{
			src[i] = '\0';
			i++;
		}
	}
}

