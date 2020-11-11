/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 17:11:31 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/10 17:04:24 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_lol(t_lol *list)
{
	ft_printf("printing lol\n");
	t_lol *tmp;

	tmp = list;
	if (tmp)
	{
		while (tmp)
		{
			print_ll(tmp->list);
			tmp = tmp->next;
		}
	}

}

t_bucket	*append_to_ll(t_bucket *src, t_entry *entry)
{
	t_bucket 	*new;
	t_bucket	*head;
	t_bucket	*tmp;

	new = create_bucket();
	new->entry = copy_entry(entry);
	head = src;
	tmp = NULL;
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

t_lol	*create_lol(void)
{
	t_lol *new;

	if (!(new = (t_lol*)malloc(sizeof(t_lol))))
		exit_malloc();
	new->list = NULL;
	new->next = NULL;
	return (new);
}

t_bucket	*copy_ll(t_bucket *ll)
{
	t_bucket	*tmp;
	t_bucket	*new;

	tmp = ll;
	new = NULL;
	while (tmp)
	{
		new = append_to_ll(new, tmp->entry);
		tmp = tmp->next;		
	}
	return (new);
}

void	append_lol(t_lol *list, t_bucket *ll)
{
	t_lol 	*tmp;
	// t_bucket	*head;

	tmp = list;
	ft_printf("list: %p\n", list);
	ft_printf("list->list: %p\n", list->list);
	if (!tmp->list)
		tmp->list = copy_ll(ll);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		ft_printf("tmp->list address after iteration: %p\n", tmp->list);
		tmp->next->list = copy_ll(ll);
	}
	// list = tmp;
	ft_printf("list->list: %p\n", list->list);
	ft_printf("Printing list from inside append");
	print_lol(list);

}

void	free_ll(t_bucket *ll)
{
	t_bucket	*cur;

	if (ll)
	{
		while (ll->next)
		{
			cur = ll;
			ll = ll->next;
			free_node(cur);
		}
		free_node(ll);
		ll = NULL;
	}
}

void	pop_from_lol(t_lol *list)
{
	t_bucket	*tmp;
	t_bucket	*head;

	head = list->list;
	tmp = head;
	if (head->next)
		head = head->next;
	free_ll(tmp);
	tmp->next = NULL;
	list->list = head;
}

// void	build_paths_2(t_bfs *bfs)
// {
// 	while (bfs->lolq)
// 	{

// 	}
// }

void	build_paths(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_entry		*start;
	t_entry		*end;
	t_bucket	*ll;
	t_bucket	*ll2;

	ll = NULL;
	ll2 = NULL;
	end = bfs->goal;
	start = bfs->start;
	bfs->lolq = create_lol();
	ll = append_to_ll(ll, start);
	// build_paths_2(bfs);
	ll = append_to_ll(ll, start);
	// print_ll(ll);
	ll2 = append_to_ll(ll2, end);
	ll2 = append_to_ll(ll2, end);
	

	append_lol(bfs->lolq, ll);
	ft_printf("printing 1 list\n");
	print_lol(bfs->lolq);
	append_lol(bfs->lolq, ll2);
	// ft_printf("printing 2 list\n");
	// print_lol(bfs->lolq);
	// ft_printf("BEFORE: List head: %p\n", bfs->lolq);
	// pop_from_lol(bfs->lolq);
	// ft_printf("AFTER: List head: %p\n", bfs->lolq);
	// print_lol(bfs->lolq);
	// ft_printf("lolq: %p\n", bfs->lolq);
	// ft_printf("lolq->list: %p\n", bfs->lolq->list);
	while (1)
	{
		
	}

}