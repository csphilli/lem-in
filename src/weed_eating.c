/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weed_eating.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:37:47 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/15 18:40:57 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_vis(t_bucket **links)
{
	t_bucket	*tmp;
	int			count;

	tmp = *links;
	count = 0;
	while (tmp)
	{
		if (tmp->entry->visited)
			count++;
		tmp = tmp->next;
	}
	return (count);
}



int		same_links(t_bucket **ll1, t_bucket **ll2)
{
	t_bucket	*tmp1;
	t_bucket	*tmp2;

	tmp1 = *ll1;
	tmp2 = *ll2;
	while ((tmp1 && tmp2) && \
			ft_strequ(tmp1->entry->name, tmp2->entry->name))
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	if (!tmp1 && !tmp2)
		return (1);
	return (0);
}

void	que_visited(t_bucket **que, t_bucket **paths)
{
	t_bucket *tmp;

	tmp = *paths;
	while (tmp)
	{
		if (tmp->entry->visited)
			append_to_ll(que, tmp->entry);
		tmp = tmp->next;
	}
}

void	weed_eating2(t_bucket **paths)
{
	t_bucket	*tmp;
	t_bucket	*que;

	tmp = NULL;
	que = NULL;
	que_visited(&que, paths);
	while (que)
	{
		tmp = que->entry->links;
		while (tmp)
		{
			if (list_length(tmp->entry->links) - \
				count_vis(&tmp->entry->links) == 1)
			{
				append_to_ll(&que, tmp->entry);
				tmp->entry->visited = 1;
			}
			tmp = tmp->next;
		}
		pop_from_ll(&que);		
	}
}

void	weed_eating1(t_bucket **paths)
{
	t_bucket 	*tmp;
	t_bucket	*cur;
	t_bucket	*head;

	head = *paths;
	cur = head;
	while (cur)
	{
		tmp = cur->next;
		list_length(cur->entry->links) == 1 ? cur->entry->visited = 1 : 1;
		while (tmp)
		{
			if (same_links(&cur->entry->links, &tmp->entry->links))
				cur->entry->visited = 1;
			tmp = tmp->next;
		}
		cur = cur->next;
	}
	*paths = head;
}