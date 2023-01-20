/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_node_cost.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:44:26 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/28 22:23:09 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calcul_ra_rb(t_pile *a, t_pile *b, t_node *to_insert)
{
	int	ra;
	int	rb;

	ra = 0;
	rb = 0;
	ra = calcul_ra(a, to_insert);
	rb = calcul_rb(b, to_insert);
	if (ra > rb)
		return (ra);
	return (rb);
}

int	calcul_rra_rrb(t_pile *a, t_pile *b, t_node *to_insert)
{
	int	rra;
	int	rrb;

	rra = 0;
	rrb = 0;
	rra = calcul_rra(a, to_insert);
	rrb = calcul_rrb(b, to_insert);
	if (rra > rrb)
		return (rra);
	return (rrb);
}

int	calcul_ra_rrb(t_pile *a, t_pile *b, t_node *to_insert)
{
	int	ra;
	int	rrb;

	ra = 0;
	rrb = 0;
	ra = calcul_ra(a, to_insert);
	rrb = calcul_rrb(b, to_insert);
	return (ra + rrb);
}

int	calcul_rra_rb(t_pile *a, t_pile *b, t_node *to_insert)
{
	int	rra;
	int	rb;

	rra = 0;
	rb = 0;
	rra = calcul_rra(a, to_insert);
	rb = calcul_rb(b, to_insert);
	return (rra + rb);
}

int	calcul_node_cost(t_pile *a, t_pile *b, t_node *current)
{
	int	ra_rb;
	int	rra_rrb;
	int	ra_rrb;
	int	rra_rb;

	ra_rb = calcul_ra_rb(a, b, current);
	rra_rrb = calcul_rra_rrb(a, b, current);
	ra_rrb = calcul_ra_rrb(a, b, current);
	rra_rb = calcul_rra_rb(a, b, current);
	if (ra_rb < rra_rrb && ra_rb < ra_rrb && ra_rb < rra_rb)
		return (ra_rb);
	if (rra_rrb < ra_rrb && rra_rrb < rra_rb)
		return (rra_rrb);
	if (ra_rrb < rra_rb)
		return (ra_rrb);
	return (rra_rb);
}
