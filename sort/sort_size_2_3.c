/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p2_p3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:54:21 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 12:02:35 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_size2_a(t_pile *a, t_pile *b)
{
	if (a->begin->pos > a->begin->next->pos)
		ft_sa(a, b);
}

void	sort_size2_b(t_pile *a, t_pile *b)
{
	if (b->begin->pos < b->begin->next->pos)
		ft_sb(a, b);
}

void	get_pos_123(int *pos1, int *pos2, t_pile *p)
{
	int	p1;
	int	p2;
	int	p3;

	p1 = p->begin->pos;
	p2 = p->begin->next->pos;
	p3 = p->begin->next->next->pos;
	if (p1 < p2 && p1 < p3)
		*pos1 = 1;
	if ((p1 < p2 && p1 > p3) || (p1 > p2 && p1 < p3))
		*pos1 = 2;
	if (p1 > p2 && p1 > p3)
		*pos1 = 3;
	if (p2 < p1 && p2 < p3)
		*pos2 = 1;
	if ((p2 < p1 && p2 > p3) || (p2 > p1 && p2 < p3))
		*pos2 = 2;
	if (p2 > p1 && p2 > p3)
		*pos2 = 3;
}

void	sort_size3(t_pile *a, t_pile *b)
{
	int	pos1;
	int	pos2;

	pos1 = 0;
	pos2 = 0;
	get_pos_123(&pos1, &pos2, a);
	if (pos1 == 1 && pos2 == 3 && 2)
	{
		ft_ra(a, b);
		ft_sa(a, b);
		ft_rra(a, b);
	}
	if (pos1 == 2 && pos2 == 1 && 3)
		ft_sa(a, b);
	if (pos1 == 2 && pos2 == 3 && 1)
		ft_rra(a, b);
	if (pos1 == 3 && 1 && 2)
		ft_ra(a, b);
	if (pos1 == 3 && pos2 == 2 && 1)
		ft_sa(a, b);
}
