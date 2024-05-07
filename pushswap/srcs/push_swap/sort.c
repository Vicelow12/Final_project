/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:21:32 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_t_stack(t_stack **a, t_stack **b, size_t nb_node)
{
	size_t	len_a;

	len_a = count_elem(a) - 1;
	pb(a, b);
	if (len_a-- > 3)
		pb(a, b);
	while (len_a-- > 3)
	{
		init_a(a, b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_b(a, b, nb_node);
		move_b_to_a(a, b);
	}
	set_pos(a);
	min_on_top(a);
}

int	is_sorted(t_stack	**stk)
{
	t_stack	*cur;

	cur = *stk;
	if (!cur)
		return (0);
	while (cur->next != NULL)
	{
		if (cur->node > cur->next->node)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	sort_three(t_stack **stk)
{
	t_stack	*cur;
	t_stack	*max;
	int		i;

	i = 0;
	cur = *stk;
	max = *stk;
	if (!cur || count_elem(stk) != 3 || is_sorted(stk))
		return ;
	while (cur->next != NULL)
	{
		cur = cur->next;
		if (max->node < cur->node)
		{
			max = cur;
			i++;
		}
	}
	if (i == 0)
		ra(stk);
	else if (i == 1)
		rra(stk);
	if (!is_sorted(stk))
		sa(stk);
}

void	init_b(t_stack **a, t_stack **b, size_t nb_node)
{
	set_pos(a);
	set_pos(b);
	set_target_b(a, b, nb_node);
}

void	init_a(t_stack **a, t_stack **b)
{
	set_pos(a);
	set_pos(b);
	set_target(a, b);
	set_push_cost(a, b);
	set_cheapest(a);
}
