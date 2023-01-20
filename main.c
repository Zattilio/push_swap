/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 13:43:55 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 13:06:45 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1)
		return (0);
	if (!check_argv(argc, argv))
		return (error());
	pile_a = parse(argc, argv);
	if (!pile_a || !sort_params(argc, argv))
		return (free_pile(pile_a), error());
	give_place(pile_a, argv);
	if (check_sorted(pile_a))
		return (free_pile(pile_a), 0);
	pile_b = new_pile();
	if (!pile_b)
		return (free(pile_a), error());
	sort_pile(pile_a, pile_b);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
