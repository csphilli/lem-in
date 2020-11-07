/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_paths copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 09:22:20 by cphillip          #+#    #+#             */
/*   Updated: 2020/11/07 09:11:13 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_q(t_bfs *bfs)
{
	int	i;
	t_lol 		*tmp;
	t_bucket 	*curr;

	i = 0;
	tmp = bfs->que;
	curr = NULL;
	while (tmp)
	{
		if (tmp)
		curr = tmp->list;
		while (curr)
		{
			ft_printf("%s", curr->entry->name);
			if (curr->next)
				write(1, ",", 1);
			curr = curr->next;
		}
		if (tmp->next)
			write(1, "\n", 1);
		tmp = tmp->next;
	}
}

t_lol		*create_list(void)
{
	t_lol *new;

	if (!(new = (t_lol*)malloc(sizeof(t_lol))))
		exit_malloc();
	new->list = NULL;
	new->next = NULL;
	return (new);
}

t_bucket  *copy_ll(t_bucket *head)
{
	t_bucket 	*new;
	t_bucket  	*tmp;
	
	tmp = head;
	new = NULL;
	while (tmp)
	{
		new = insert_node_to_path(new, tmp->entry);
		tmp = tmp->next;
	}
	return (new);
}

void		insert_to_q(t_bfs *bfs, t_bucket *head)
{
	t_lol *tmp;

	tmp = bfs->que;
	if (tmp == NULL)
	{
		ft_printf("que head was NULL\n");
		tmp = create_list();
		tmp->list = copy_ll(head);
	}
	else
	{
		ft_printf("que head was NOT NULL\n");
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_list();
		tmp->next->list = copy_ll(head);
	}
	// return (que);
}

void	freelist(t_bucket *list)
{
	t_bucket *tmp;
	t_bucket *curr;

	tmp = list;
	if (tmp->next)
	{
		while (tmp->next)
		{
			curr = tmp;
			tmp = tmp->next;
			free_entry(curr->entry);
			free_bucket(curr);
			curr = NULL;
		}
	}
	free_entry(tmp->entry);
	free_bucket(tmp);
	tmp = NULL;
}

void	pop_from_lol(t_lol *list)
{
	t_lol *tmp;
	t_lol *curr;
	// t_p *head;

	tmp = list;
	curr = NULL;
	if (tmp)
	{
		if (tmp->next)
			curr = tmp->next;
		// ft_printf("No tmp->next\n");
		freelist(tmp->list);
		tmp->list = NULL;
		free(tmp);
		list = curr;
		
		// ft_printf("que: %p\n", head);
	}
	// return (head);
}



		examine_curr(t_bfs *bfs, t_bucket *curr)
{
	t_bucket 	*tmp;
	t_bucket	*copy;
	int			len;
	int			i;

	tmp = curr;
	i = 0;
	// set_visited(tmp, 1);
	copy = NULL;
	while (tmp->next)
		tmp = tmp->next;
	if (ft_strequ(tmp->entry->name, bfs->goal->name))
		ft_printf("add path to solution set\n");
		// add_path_to_lol(paths, curr);
	else
	{
		len = link_array_len(tmp->entry->link_arr);
		ft_printf("len: %d\n", len);
		while (i < len)
		{
			if (!tmp->entry->link_arr[i]->visited)
			{
				ft_printf("%s's visited status: %d\n", tmp->entry->link_arr[i]->name, tmp->entry->link_arr[i]->visited);
				copy = copy_ll(curr);
				ft_printf("The copy: ");
				print_path(copy);
				copy = insert_node_to_path(copy, tmp->entry->link_arr[i]);
				ft_printf("With addition: ");
				print_path(copy);
				// ft_printf("\n");
				que = insert_to_q(que, copy);
				ft_printf("The que after addition:\n");
				print_q(que);
				ft_printf("\n");
				freelist(copy);
				copy = NULL;
			}
			i++;
		}
	}
	return (que);
}

t_p		*build_paths_2(t_bfs *bfs)
{
	t_bucket *curr;

	curr = NULL;
	while (que)
	{
		curr = copy_ll(que->path);
		set_visited(curr, 1);
		pop_from_lol(que);
		// que = examine_curr(paths, que, bfs, curr);
		ft_printf("que: %p\n", que);
		print_path(curr);
		freelist(curr);
		curr = NULL;
	}
	return (paths);
}

void	build_paths(t_bucket **ht, t_master *master, t_bfs *bfs)
{
	t_lol 		*paths;
	t_lol 		*que;
	t_entry		*end;
	t_bucket	*b_end;

	paths = NULL;
	que = NULL;
	b_end = NULL;
	end = get_entry(ht, master, master->end_room);
	b_end = insert_node_to_path(b_end, end);

	que = insert_to_q(que, b_end);
	que = build_paths_2(paths, que, bfs);
	ft_printf("Back to base\n");
	// freelist(b_end);
	// b_end = NULL;

	if (paths)
		print_q(paths);
	while (1)
	{
		
	}


}

