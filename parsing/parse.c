/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:25:24 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 06:01:04 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*new_node(int value, int grp_size)
{
	t_node	*new;

	new = malloc(sizeof(t_node) * 1);
	if (new == NULL)
		return (NULL);
	new->next = new;
	new->prev = new;
	new->value = value;
	new->pos = 0;
	new->grp_size = grp_size;
	new->median = grp_size / 2;
	return (new);
}

t_pile	*new_pile(void)
{
	t_pile	*new;

	new = malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->begin = NULL;
	return (new);
}

void	add_last(t_pile *pile, t_node *node)
{
	t_node	*begin;

	if (pile->begin == NULL)
		pile->begin = node;
	else
	{
		begin = pile->begin;
		if (begin->next == begin)
			begin->next = node;
		node->next = begin;
		node->prev = begin->prev;
		begin->prev->next = node;
		begin->prev = node;
	}
}

void	free_pile(t_pile *pile)
{
	t_node	*node;

	node = pile->begin;
	if (node != NULL)
	{
		while (node->next != pile->begin)
		{
			node = node->next;
			free(node->prev);
		}
		free(node);
	}
	free(pile);
}

t_pile	*parse(int argc, char *argv[])
{
	t_pile	*lst;
	t_node	*node;
	int		i;

	lst = new_pile();
	i = 1;
	while (i < argc)
	{
		node = new_node(ft_atoi(argv[i]), argc - 1);
		if (node == NULL)
			return (free_pile(lst), NULL);
		add_last(lst, node);
		i++;
	}
	return (lst);
}
