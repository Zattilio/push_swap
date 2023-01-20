/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p4_p5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:10:31 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 11:51:36 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_p4_p5_suite(t_pile *a, t_pile *b)
{
	sort_size2_b(a, b);
	if (a->begin->grp_size == 2)
		sort_size2_a(a, b);
	if (a->begin->grp_size == 3)
		sort_size3(a, b);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	sort_size_4_5(t_pile *a, t_pile *b)
{
	int	i;
	int	grp_size;
	int	median;

	i = 1;
	median = 0;
	grp_size = a->begin->grp_size;
	median = grp_size / 2;
	while (i <= grp_size)
	{
		if (a->begin->pos <= median)
		{
			a->begin->grp_size = median;
			ft_pb(a, b);
		}
		else
		{
			a->begin->grp_size = median + grp_size % 2;
			ft_ra(a, b);
		}
		i++;
	}
	sort_p4_p5_suite(a, b);
}
