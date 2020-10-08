/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capture_links.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 12:16:07 by cphillip          #+#    #+#             */
/*   Updated: 2020/10/08 15:33:03 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_link_exists(char **arr, char *link)
{
	char	**tmp;
	int		i;

	i = 0;

	tmp = arr;
	while (tmp[i])
	{
		if (ft_strequ(tmp[i++], link))
			return (1);
	}
	return (0);
}

void	add_to_array(char **link_arr, char *new_link)
{
	char	**new;
	char	**tmp;
	int		len;
	int		i;

	tmp = link_arr;
	new = NULL;
	len = 0;
	i = 0;
	while (*tmp++)
		len++;
	len += 2;
	if (!(new = (char**)malloc(sizeof(char*) * (len))))
		exit_malloc();
	init_link_arr(new, len);
	while (i < len - 2)
	{
		new[i] = ft_strdup(link_arr[i]);
		i++;
	}
	new[i] = ft_strdup(new_link);
	// free_strsplit(&link_arr);
	link_arr = NULL;
}

void	insert_link(t_bucket *bucket, char *link)
{
	char	**arr;
	char	**tmp_arr;
	int		len;

	len = 0;
	tmp_arr = NULL;
	arr = NULL;
	if (!bucket->entry->link_arr)
	{
		if (!(bucket->entry->link_arr = (char**)malloc(sizeof(char*) * 2)))
			exit_malloc();
		init_link_arr(bucket->entry->link_arr, 2);
		bucket->entry->link_arr[0] = ft_strdup(link);
	}
	else
	{
		tmp_arr = bucket->entry->link_arr;
		if (!check_link_exists(tmp_arr, link))
			add_to_array(tmp_arr, link);
		else
			ft_printf("link: %s exists\n", link);
			// return (bucket->entry->link_arr);
	}
	// return (arr);
}

void	search_for_room(t_bucket *head, char *room, char *link)
{
	t_bucket	*tmp;
	int	i;

	i = 0;
	tmp = head;
	// while (!ft_strequ(room, tmp->entry->name) && tmp->next)
	// 	tmp = tmp->next;
	// ft_printf("tmp starting at: %s\n", tmp->entry->name);
	ft_printf("Head: %s\n", tmp->entry->name);
	while (tmp)
	{
		if (!ft_strequ(tmp->entry->name, room))
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp == NULL)
		exit_room_not_found(room);
	// ft_printf("Broke out of tmp and sitting at: %s\n", tmp->entry->name);
	// ft_printf("room: %s | tmp->room: %s\n", room, tmp->entry->name);
	ft_printf(" Inserting %s to Room: %s\n", link, tmp->entry->name);
	insert_link(tmp, link);
}

void	add_link_to_room(t_bucket **ht, t_master *master, char *line)
{
	char		**data;
	int			index;

	data = ft_strsplit(line, '-');
	index = gen_key(data[0]) % master->new_size;
	search_for_room(ht[index], data[0], data[1]);
	index = gen_key(data[1]) % master->new_size;
	search_for_room(ht[index], data[1], data[0]);
	free_strsplit(&data);
	data = NULL;
}

/*
char	**insert_link(t_bucket *bucket, char *link)
{
	char	**arr;
	char	**tmp_arr;
	int		len;

	len = 0;
	tmp_arr = NULL;
	arr = NULL;
	if (!bucket->entry->link_arr)
	{
		if (!(arr = (char**)malloc(sizeof(char*) * 2)))
			exit_malloc();
		init_link_arr(arr, 2);
		arr[0] = ft_strdup(link);
	}
	else
	{
		tmp_arr = bucket->entry->link_arr;
		if (check_link_exists(bucket->entry->link_arr, link))
			return (bucket->entry->link_arr);
		arr = fill_array(bucket->entry->link_arr, link);
	}
	return (arr);
}

char	**fill_array(char **src, char *new_link)
{
	char	**new;
	char	**tmp;
	int		len;
	int		i;

	tmp = src;
	new = NULL;
	len = 0;
	i = 0;
	while (*tmp++)
		len++;
	len += 2;
	if (!(new = (char**)malloc(sizeof(char*) * (len))))
		exit_malloc();
	init_link_arr(new, len);
	while (i < len - 2)
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	new[i] = ft_strdup(new_link);
	free_strsplit(&src);
	src = NULL;
	return (new);
}
*/