/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:10:05 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:37:28 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char *argv[])
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	t_list	*lst;

	if (argc == 1)
		return (0);
	if (!check_argv(argc, argv))
		return (error());
	pile_a = parse(argc, argv);
	lst = get_instruction();
	if (!pile_a || !sort_params(argc, argv))
		return (free_pile(pile_a), error());
	give_place(pile_a, argv);
	pile_b = new_pile();
	if (!pile_b)
		return (free(pile_a), error());
	run_instructions(pile_a, pile_b, lst);
	display_result(check_sorted(pile_a) && !(pile_b->begin));
	ft_lstclear(&lst, &free);
	free_pile(pile_a);
	free_pile(pile_b);
	return (0);
}
