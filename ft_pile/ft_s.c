/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:26:14 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 19:58:43 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_sa(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		ft_swap_node(pile_a->begin, pile_a->begin->next);
	(void)pile_b;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		ft_swap_node(pile_b->begin, pile_b->begin->next);
	(void)pile_a;
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		ft_swap_node(pile_a->begin, pile_a->begin->next);
	if (pile_b->begin)
		ft_swap_node(pile_b->begin, pile_b->begin->next);
	ft_putendl_fd("ss", 1);
}
