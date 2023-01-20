/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 04:28:54 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:03:55 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->next;
	(void)pile_b;
}

void	rb(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->next;
	(void)pile_a;
}

void	rr(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->begin)
		pile_a->begin = pile_a->begin->next;
	if (pile_b->begin)
		pile_b->begin = pile_b->begin->next;
}
