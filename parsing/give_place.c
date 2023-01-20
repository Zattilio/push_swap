/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:49:23 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/16 23:07:33 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_pos(char *argv[], int n)
{
	int	i;

	i = 1;
	while (ft_atoi(argv[i]) != n)
		i++;
	return (i);
}

void	give_place(t_pile *pile, char *argv[])
{
	t_node	*begin;

	begin = pile->begin;
	while (begin->next != pile->begin)
	{
		begin->pos = get_pos(argv, begin->value);
		begin = begin->next;
	}
	begin->pos = get_pos(argv, begin->value);
}
