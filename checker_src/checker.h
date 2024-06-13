/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:10:38 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 20:06:17 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../push_swap.h"
# include <unistd.h>
# include <limits.h>

void	run_instructions(t_pile *a, t_pile *b, t_list *lst);
void	display_result(int r);
t_list	*get_instruction(void);

void	sa(t_pile *pile_a, t_pile *pile_b);
void	sb(t_pile *pile_a, t_pile *pile_b);
void	ss(t_pile *pile_a, t_pile *pile_b);
void	pa(t_pile *pile_a, t_pile *pile_b);
void	pb(t_pile *pile_a, t_pile *pile_b);
void	ra(t_pile *pile_a, t_pile *pile_b);
void	rb(t_pile *pile_a, t_pile *pile_b);
void	rr(t_pile *pile_a, t_pile *pile_b);
void	rra(t_pile *pile_a, t_pile *pile_b);
void	rrb(t_pile *pile_a, t_pile *pile_b);
void	rrr(t_pile *pile_a, t_pile *pile_b);

#endif
