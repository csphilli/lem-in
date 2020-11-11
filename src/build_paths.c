/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:40:08 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/11 19:54:31 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//append link to list
//append list to list

void	print_lol(t_lol *list)
{
	t_lol *tmp;
	t_bucket *curr;

	tmp = list;
	curr = NULL;
	while (tmp)
	{
		curr = tmp->list;
		while (curr)
		{
			ft_printf("%s", curr->entry->name);
			curr->next ? write(1, ",", 1) : 1;
			curr = curr->next;
		}
		tmp->next ? write(1, "\n", 1) : 1;
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

t_bucket    *append_to_ll(t_bucket *ll, t_entry *entry)
{
    t_bucket    *node;
	t_bucket	*tmp;
	t_bucket	*head;

	head = ll;
	tmp = head;
    node = ft_memalloc(sizeof(t_bucket));
    node->entry = copy_entry(entry);
    if (head == NULL)
		head = node;
    else
    {
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
    }
	return (head);
}

t_bucket 	*copy_ll(t_bucket *ll)
{
	t_bucket *new;
	t_bucket *tmp;

	new = NULL;
	tmp = ll;
	while (tmp)
	{
		new = append_to_ll(new, tmp->entry);
		tmp = tmp->next;
	}
	return (new);
}

t_lol	*ll_to_que(t_lol *que, t_bucket *ll)
{
	t_lol	*new;
	t_lol	*head;
	t_lol	*tmp;

	head = que;
	tmp = head;
	new = ft_memalloc(sizeof(t_lol));
	new->list = copy_ll(ll);
	if (head == NULL)
		head = new;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (head);
}

// void	create_node(t_bucket **src, t_entry *entry)
// {
// 	t_entry	*new;

// 	new = copy_entry(entry);
// 	*src = ft_memalloc(sizeof(t_bucket));
// 	(*src)->entry = new;
// }
void	execute_que(t_bucket **ht, t_bfs *bfs, t_lol *que)
{
	while (que)
	{
		
	}
}

void	build_paths(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_bucket	*new;
	t_lol		*que;

	que = NULL;
	new = NULL;
	new = append_to_ll(new, bfs->start);
	// new = append_to_ll(new, bfs->goal);
	que = ll_to_que(que, new);
	execute_que(ht, bfs, que);
	ft_printf("PRINTING LIST\n");
	print_ll(new);
	ft_printf("PRINTING QUE\n");
	print_lol(que);
	print_ll(bfs->bfs);
	// ft_printf("entry name: %s\n", new->entry->name);

	while (1)
	{
		
	}

}