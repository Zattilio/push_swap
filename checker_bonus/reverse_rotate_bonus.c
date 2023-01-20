/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:24:35 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:03:51 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rra(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->prev;
	(void)pile_b;
}

void	rrb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->prev;
	(void)pile_a;
}

void	rrr(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->prev;
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->prev;
}
