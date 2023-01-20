/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:28:54 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 19:58:19 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->next;
	(void)pile_b;
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->next;
	(void)pile_a;
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->next;
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->next;
	ft_putendl_fd("rr", 1);
}
