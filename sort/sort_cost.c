/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:05:38 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 12:26:21 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node	*calcul_cost(t_pile *a, t_pile *b)
{
	int		cheaper_price;
	int		current_price;
	t_node	*cheaper_node;
	t_node	*current;

	cheaper_price = INT_MAX;
	cheaper_node = b->begin;
	current = b->begin;
	while (current->next != b->begin)
	{
		current_price = calcul_node_cost(a, b, current) + current->pos;
		if (cheaper_price > current_price)
		{
			cheaper_price = current_price;
			cheaper_node = current;
		}
		current = current->next;
	}
	return (cheaper_node);
}

void	sort_cost(t_pile *a, t_pile *b)
{
	t_node	*to_insert;

	divide_amod(a, b);
	while (a->begin->grp_size > 3)
		divide_a(a, b);
	sort_pile(a, b);
	while (b->begin)
	{
		to_insert = calcul_cost(a, b);
		insert_pile(a, b, to_insert);
	}
	smaller_on_top(a, b);
}
