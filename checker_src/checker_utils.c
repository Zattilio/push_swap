/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:18:29 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:10:38 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	run_instruction(t_pile *a, t_pile *b, char *str)
{
	if (!ft_strncmp("sa\n", str, ft_strlen(str)))
		sa(a, b);
	if (!ft_strncmp("sb\n", str, ft_strlen(str)))
		sb(a, b);
	if (!ft_strncmp("ss\n", str, ft_strlen(str)))
		ss(a, b);
	if (!ft_strncmp("pa\n", str, ft_strlen(str)))
		pa(a, b);
	if (!ft_strncmp("pb\n", str, ft_strlen(str)))
		pb(a, b);
	if (!ft_strncmp("ra\n", str, ft_strlen(str)))
		ra(a, b);
	if (!ft_strncmp("rb\n", str, ft_strlen(str)))
		rb(a, b);
	if (!ft_strncmp("rr\n", str, ft_strlen(str)))
		rr(a, b);
	if (!ft_strncmp("rra\n", str, ft_strlen(str)))
		rra(a, b);
	if (!ft_strncmp("rrb\n", str, ft_strlen(str)))
		rrb(a, b);
	if (!ft_strncmp("rrr\n", str, ft_strlen(str)))
		rrr(a, b);
}

void	run_instructions(t_pile *a, t_pile *b, t_list *lst)
{
	while (lst)
	{
		run_instruction(a, b, lst->content);
		lst = lst->next;
	}
}

void	display_result(int r)
{
	if (r)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

static int	check_instruct(char *str)
{
	if (!ft_strncmp("sa\n", str, ft_strlen(str))
		|| !ft_strncmp("sb\n", str, ft_strlen(str))
		|| !ft_strncmp("ss\n", str, ft_strlen(str))
		|| !ft_strncmp("pa\n", str, ft_strlen(str))
		|| !ft_strncmp("pb\n", str, ft_strlen(str))
		|| !ft_strncmp("ra\n", str, ft_strlen(str))
		|| !ft_strncmp("rb\n", str, ft_strlen(str))
		|| !ft_strncmp("rr\n", str, ft_strlen(str))
		|| !ft_strncmp("rra\n", str, ft_strlen(str))
		|| !ft_strncmp("rrb\n", str, ft_strlen(str))
		|| !ft_strncmp("rrr\n", str, ft_strlen(str)))
		return (1);
	return (0);
}

t_list	*get_instruction(void)
{
	char	*str;
	t_list	*lst;
	t_list	*new;
	int		doo;

	doo = 1;
	lst = NULL;
	while (doo || str != NULL)
	{
		doo = 0;
		str = get_next_line(0);
		if (str != NULL)
		{
			if (!check_instruct(str))
				return (ft_lstclear(&lst, &free), NULL);
			new = ft_lstnew(str);
			ft_lstadd_back(&lst, new);
		}
	}
	return (lst);
}
