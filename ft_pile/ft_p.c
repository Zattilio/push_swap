/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:38:06 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:38:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	auto_node(t_node *node)
{
	node->next = node;
	node->prev = node;
}

static void	ft_push(t_pile *pile_a, t_pile *pile_b)
{
	t_node	*node;

	if (pile_a->begin != NULL)
	{
		node = pile_a->begin;
		if (pile_a->begin == pile_a->begin->next)
			pile_a->begin = NULL;
		else
		{
			pile_a->begin->next->prev = pile_a->begin->prev;
			pile_a->begin->prev->next = pile_a->begin->next;
			pile_a->begin = pile_a->begin->next;
		}
		if (pile_b->begin != NULL)
		{
			node->next = pile_b->begin;
			node->prev = pile_b->begin->prev;
			pile_b->begin->prev->next = node;
			pile_b->begin->prev = node;
		}
		else
			auto_node(node);
	pile_b->begin = node;
	}
}

void	ft_pa(t_pile *pile_a, t_pile *pile_b)
{
	ft_push(pile_b, pile_a);
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_pile *pile_a, t_pile *pile_b)
{
	ft_push(pile_a, pile_b);
	ft_putendl_fd("pb", 1);
}
