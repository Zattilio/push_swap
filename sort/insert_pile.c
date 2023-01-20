/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_pile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:17:30 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 12:26:21 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	insert_ra_rb(t_pile *a, t_pile *b, t_node *current)
{
	int	ra;
	int	rb;

	ra = 0;
	rb = 0;
	ra = calcul_ra(a, current);
	rb = calcul_rb(b, current);
	while (ra && rb)
	{
		ft_rr(a, b);
		ra--;
		rb--;
	}
	while (ra)
	{
		ft_ra(a, b);
		ra--;
	}
	while (rb)
	{
		ft_rb(a, b);
		rb--;
	}
	ft_pa(a, b);
}

static void	insert_rra_rrb(t_pile *a, t_pile *b, t_node *current)
{
	int	rra;
	int	rrb;

	rra = 0;
	rrb = 0;
	rra = calcul_rra(a, current);
	rrb = calcul_rrb(b, current);
	while (rra && rrb)
	{
		ft_rrr(a, b);
		rra--;
		rrb--;
	}
	while (rra)
	{
		ft_rra(a, b);
		rra--;
	}
	while (rrb)
	{
		ft_rrb(a, b);
		rrb--;
	}
	ft_pa(a, b);
}

static void	insert_ra_rrb(t_pile *a, t_pile *b, t_node *current)
{
	int	ra;
	int	rrb;

	ra = 0;
	rrb = 0;
	ra = calcul_ra(a, current);
	rrb = calcul_rrb(b, current);
	while (ra)
	{
		ft_ra(a, b);
		ra--;
	}
	while (rrb)
	{
		ft_rrb(a, b);
		rrb--;
	}
	ft_pa(a, b);
}

static void	insert_rra_rb(t_pile *a, t_pile *b, t_node *current)
{
	int	rra;
	int	rb;

	rra = 0;
	rb = 0;
	rra = calcul_rra(a, current);
	rb = calcul_rb(b, current);
	while (rra)
	{
		ft_rra(a, b);
		rra--;
	}
	while (rb)
	{
		ft_rb(a, b);
		rb--;
	}
	ft_pa(a, b);
}

void	insert_pile(t_pile *a, t_pile *b, t_node *current)
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
		insert_ra_rb(a, b, current);
	else if (rra_rrb < ra_rrb && rra_rrb < rra_rb)
		insert_rra_rrb(a, b, current);
	else if (ra_rrb < rra_rb)
		insert_ra_rrb(a, b, current);
	else
		insert_rra_rb(a, b, current);
}
