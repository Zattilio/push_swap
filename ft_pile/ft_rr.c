/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:24:35 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 19:58:35 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->prev;
	(void)pile_b;
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->prev;
	(void)pile_a;
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->prev;
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->prev;
	ft_putendl_fd("rrr", 1);
}
