/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:30:30 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/16 21:47:02 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_params(char **argv1, char **argv2)
{
	char	*swap;

	swap = *argv1;
	*argv1 = *argv2;
	*argv2 = swap;
}

int	sort_params(int argc, char *argv[])
{
	int		i;
	int		sorted;

	if (argc == 1)
		return (1);
	sorted = 1;
	while (sorted)
	{
		sorted = 0;
		i = 1;
		while (i < argc - 1)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + 1]))
				return (0);
			if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			{
				swap_params(&argv[i], &argv[i + 1]);
				sorted = 1;
			}
			i++;
		}
	}
	return (1);
}
