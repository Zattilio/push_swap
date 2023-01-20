/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_rx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:33:54 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/28 23:49:01 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calcul_rb(t_pile *b, t_node *to_insert)
{
	int		rb;
	t_node	*current;

	rb = 0;
	current = b->begin;
	while (current != to_insert)
	{
		current = current->next;
		rb++;
	}
	return (rb);
}

int	calcul_rrb(t_pile *b, t_node *to_insert)
{
	int		rrb;
	t_node	*current;

	rrb = 0;
	current = b->begin;
	while (current != to_insert)
	{
		current = current->prev;
		rrb++;
	}
	return (rrb);
}

static t_node	*get_node_to_insert(t_pile *a, t_node *to_insert)
{
	t_node	*current;

	current = a->begin;
	while (current->prev->pos < current->pos)
		current = current->next;
	if (to_insert->pos < current->pos)
		return (current);
	if (to_insert->pos > current->prev->pos)
		return (current);
	while (current->pos < to_insert->pos)
		current = current->next;
	return (current);
}

int	calcul_ra(t_pile *a, t_node *to_insert)
{
	int		ra;
	t_node	*current;

	if (a->begin == NULL || a->begin->next == a->begin)
		return (0);
	current = get_node_to_insert(a, to_insert);
	ra = 0;
	while (current != a->begin)
	{
		current = current->prev;
		ra++;
	}
	return (ra);
}

int	calcul_rra(t_pile *a, t_node *to_insert)
{
	int		rra;
	t_node	*current;

	if (a->begin == NULL || a->begin->next == a->begin)
		return (0);
	current = get_node_to_insert(a, to_insert);
	rra = 0;
	while (current != a->begin)
	{
		current = current->next;
		rra++;
	}
	return (rra);
}
