/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 06:10:28 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 11:53:58 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_pile(t_pile *a, t_pile *b)
{
	if (a->begin->grp_size == 1)
		return ;
	else if (a->begin->grp_size == 2)
		sort_size2_a(a, b);
	else if (a->begin->grp_size == 3)
		sort_size3(a, b);
	else if (a->begin->grp_size == 4 || a->begin->grp_size == 5)
		sort_size_4_5(a, b);
	else
		sort_cost(a, b);
}
