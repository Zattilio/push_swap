/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:41:08 by jlanza            #+#    #+#             */
/*   Updated: 2022/12/29 13:05:14 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <limits.h>

typedef struct s_node {
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				pos;
	int				grp_size;
	int				median;
}				t_node;

typedef struct s_pile {
	struct s_node	*begin;
}				t_pile;

///////////////PARSING////////////////////////

int		check_argv(int argc, char *argv[]);
int		error(void);
t_pile	*new_pile(void);
t_pile	*parse(int argc, char *argv[]);
int		sort_params(int argc, char *argv[]);
void	free_pile(t_pile *pile);
void	give_place(t_pile *pile, char *argv[]);

////////////////PRINT/////////////////////////

void	print_pile(t_pile *lst);
void	rev_print_pile(t_pile *lst);
void	print_pile_ab(t_pile *pile_a, t_pile *pile_b);
void	print_detailed_pile_ab(t_pile *pile_a, t_pile *pile_b);
void	print_full_pile_ab(t_pile *pile_a, t_pile *pile_b);
void	print_median_ab(t_pile *pile_a, t_pile *pile_b);

//////////////////SORT////////////////////////

void	sort_pile(t_pile *a, t_pile *b);
void	sort_size2_a(t_pile *a, t_pile *b);
void	sort_size2_b(t_pile *a, t_pile *b);
void	sort_size3(t_pile *a, t_pile *b);
void	sort_size_4_5(t_pile *a, t_pile *b);
void	sort_cost(t_pile *a, t_pile *b);
void	get_pos123(int *pos1, int *pos2, t_pile *p);

int		calcul_node_cost(t_pile *a, t_pile *b, t_node *current);
int		calcul_ra(t_pile *b, t_node *to_insert);
int		calcul_rb(t_pile *b, t_node *to_insert);
int		calcul_rra(t_pile *b, t_node *to_insert);
int		calcul_rrb(t_pile *b, t_node *to_insert);

int		calcul_ra_rb(t_pile *a, t_pile *b, t_node *to_insert);
int		calcul_rra_rrb(t_pile *a, t_pile *b, t_node *to_insert);
int		calcul_ra_rrb(t_pile *a, t_pile *b, t_node *to_insert);
int		calcul_rra_rb(t_pile *a, t_pile *b, t_node *to_insert);

void	insert_pile(t_pile *a, t_pile *b, t_node *current);
void	smaller_on_top(t_pile *a, t_pile *b);
void	divide_a(t_pile *a, t_pile *b);
void	divide_amod(t_pile *a, t_pile *b);
int		check_sorted(t_pile *a);

//////////////////FT_PILE/////////////////////

void	ft_sa(t_pile *pile_a, t_pile *pile_b);
void	ft_sb(t_pile *pilt_a, t_pile *pile_b);
void	ft_ss(t_pile *pile_a, t_pile *pile_b);
void	ft_pa(t_pile *pile_a, t_pile *pile_b);
void	ft_pb(t_pile *pile_a, t_pile *pile_b);
void	ft_ra(t_pile *pile_a, t_pile *pile_b);
void	ft_rb(t_pile *pile_a, t_pile *pile_b);
void	ft_rr(t_pile *pile_a, t_pile *pile_b);
void	ft_rra(t_pile *pile_a, t_pile *pile_b);
void	ft_rrb(t_pile *pile_a, t_pile *pile_b);
void	ft_rrr(t_pile *pile_a, t_pile *pile_b);

#endif
