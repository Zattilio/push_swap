/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smaller_on_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:12:23 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 12:19:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*get_smaller_pos(t_pile *b)
{
	t_node	*current;
	t_node	*smaller_node;
	int		smaller;
	int		doo;

	current = b->begin;
	smaller_node = b->begin;
	smaller = INT_MAX;
	doo = 1;
	while (doo || current != b->begin)
	{
		doo = 0;
		if (smaller > current->pos)
		{
			smaller = current->pos;
			smaller_node = current;
		}
		current = current->next;
	}
	return (smaller_node);
}

void	smaller_on_top(t_pile *a, t_pile *b)
{
	t_node	*smaller;
	int		ra;
	int		rra;

	ra = 0;
	rra = 0;
	smaller = get_smaller_pos(a);
	ra = calcul_rb(a, smaller);
	rra = calcul_rrb(a, smaller);
	while (a->begin != smaller)
	{
		if (ra < rra)
			ft_ra(a, b);
		else
			ft_rra(a, b);
	}
}
