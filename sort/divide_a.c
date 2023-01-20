/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:15:27 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 12:18:28 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	divide_amod(t_pile *a, t_pile *b)
{
	int	i;
	int	grp_size;

	i = 1;
	grp_size = a->begin->grp_size;
	while (i <= grp_size)
	{
		if (a->begin->pos > a->begin->median)
		{
			a->begin->grp_size = grp_size / 2 + (grp_size % 2);
			a->begin->median = a->begin->median + a->begin->grp_size / 2;
			ft_pb(a, b);
			if (b->begin->pos > b->begin->median && b->begin->grp_size > 3)
				ft_rb(a, b);
		}
		else
		{
			a->begin->grp_size = (grp_size / 2);
			a->begin->median = a->begin->median - a->begin->grp_size / 2;
			ft_ra(a, b);
		}
		i++;
	}
}

void	divide_a(t_pile *a, t_pile *b)
{
	int	i;
	int	grp_size;

	i = 1;
	grp_size = a->begin->grp_size;
	while (i <= grp_size)
	{
		if (a->begin->pos > a->begin->median)
		{
			a->begin->grp_size = grp_size / 2;
			a->begin->median = a->begin->median + a->begin->grp_size / 2;
			ft_pb(a, b);
		}
		else
		{
			a->begin->grp_size = (grp_size / 2) + (grp_size % 2);
			a->begin->median = a->begin->median - a->begin->grp_size / 2;
			ft_ra(a, b);
		}
		i++;
	}
}
