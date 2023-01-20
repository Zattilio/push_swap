/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:57:37 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 11:42:26 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_str(char *s)
{
	int			i;
	int			j;
	long long	n;
	int			signe;

	n = 0;
	signe = 1;
	i = 0;
	while (('\t' <= s[i] && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '-')
		signe = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] < '0' || '9' < s[i])
		return (0);
	j = 0;
	while ('0' <= s[i + j] && s[i + j] <= '9')
	{
		n = n * 10 + (s[i + j] - '0');
		if (n * signe < INT_MIN || INT_MAX < n * signe)
			return (0);
		j++;
	}
	return (!s[i + j]);
}

int	check_argv(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!check_str(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	check_sorted(t_pile *a)
{
	t_node	*index;

	index = a->begin;
	while (index->next != a->begin)
	{
		if (index->pos + 1 != index->next->pos)
			return (0);
		index = index->next;
	}
	return (1);
}
