/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:34:11 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:52 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

typedef struct s_stack
{
	int				node;
	struct s_stack	*next;
	size_t			index;
	int				pos;
	int				above_median;
	struct s_stack	*target;
	size_t			push_cost;
	int				cheapest;
	int				move_strat;
}	t_stack;

int		is_sorted(t_stack	**stk);
void	sort_three(t_stack **stk);
void	free_split(char **argv);
size_t	count_elem(t_stack **stk);
void	reverse_rotate(t_stack **stk);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate(t_stack **stk);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	swap(t_stack **stk);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		check_duplicate(t_stack	**a);
int		check_arg(char	*arg);
void	free_t_stack(t_stack **a);
void	free_error(t_stack	**a, char **tab);
void	create_t_stack(t_stack **a, char **argv, size_t argc, size_t i);
void	sort_t_stack(t_stack **a, t_stack **b, size_t nb_node);
size_t	set_index(t_stack **a);
void	init_a(t_stack **a, t_stack **b);
void	set_pos(t_stack **a);
void	set_target(t_stack **a, t_stack **b);
t_stack	*find_max(t_stack **stk);
void	set_push_cost(t_stack **a, t_stack **b);
void	push_cost_above_median(t_stack *cur_a, size_t len_b);
void	push_cost_below_median(t_stack *cur_a, size_t len_a, size_t len_b);
void	set_cheapest(t_stack **stk);
void	move_a_to_b(t_stack	**a, t_stack	**b);
t_stack	*get_cheapest(t_stack **stk);
void	init_b(t_stack **a, t_stack **b, size_t nb_node);
void	set_target_b(t_stack **a, t_stack **b, size_t nb_node);
t_stack	*find_min(t_stack **stk);
void	move_b_to_a(t_stack	**a, t_stack **b);
void	min_on_top(t_stack **a);
void	init_t_stack(t_stack **a, char **argv);
char	**create_tab(char **tab, char **argv, int argc);
size_t	ft_strlen(char *str);
size_t	nb_nodes(char **argv);
char	**ft_split(char const *s, char c);
void	move_1(t_stack **a, t_stack	**b, t_stack *cheapest);
void	move_2(t_stack **a, t_stack	**b, t_stack *cheapest);
void	move_3(t_stack **a, t_stack	**b, t_stack *cheapest);
void	move_4(t_stack **a, t_stack	**b, t_stack *cheapest);
char	**init_arg(int argc, char **argv, char **tab);
int		ft_atoi(const char *nptr, t_stack **a, char **argv);

#endif