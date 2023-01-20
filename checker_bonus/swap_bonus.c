/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:26:14 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:03:58 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

static void	ft_swap_node(t_node *node_a, t_node *node_b)
{
	ft_swap(&(node_a->value), &(node_b->value));
	ft_swap(&(node_a->pos), &(node_b->pos));
	ft_swap(&(node_a->grp_size), &(node_b->grp_size));
}

void	sa(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		ft_swap_node(pile_a->begin, pile_a->begin->next);
	(void)pile_b;
}

void	sb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		ft_swap_node(pile_b->begin, pile_b->begin->next);
	(void)pile_a;
}

void	ss(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		ft_swap_node(pile_a->begin, pile_a->begin->next);
	if (pile_b->begin)
		ft_swap_node(pile_b->begin, pile_b->begin->next);
}
