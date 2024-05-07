/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_strat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:21:41 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	move_1(t_stack **a, t_stack	**b, t_stack *cheapest)
{
	while (cheapest->pos > 0 && cheapest->target->pos > 0)
	{
		rr(a, b);
		cheapest->pos--;
		cheapest->target->pos--;
	}
	while (cheapest->pos > 0)
	{
		ra(a);
		cheapest->pos--;
	}
	while (cheapest->target->pos > 0)
	{
		rb(b);
		cheapest->target->pos--;
	}
}

void	move_2(t_stack **a, t_stack	**b, t_stack *cheapest)
{
	size_t	len_a;
	size_t	len_b;

	len_a = count_elem(a);
	len_b = count_elem(b);
	while (cheapest->pos < (int)len_a && cheapest->target->pos < (int)len_b)
	{
		rrr(a, b);
		cheapest->pos++;
		cheapest->target->pos++;
	}
	while (cheapest->pos < (int)len_a)
	{
		rra(a);
		cheapest->pos++;
	}
	while (cheapest->target->pos < (int)len_b)
	{
		rrb(b);
		cheapest->target->pos++;
	}
}

void	move_3(t_stack **a, t_stack	**b, t_stack *cheapest)
{
	size_t	len_b;

	len_b = count_elem(b);
	while (cheapest->pos > 0)
	{
		ra(a);
		cheapest->pos--;
	}
	while (cheapest->target->pos < (int)len_b)
	{
		rrb(b);
		cheapest->target->pos++;
	}
}

void	move_4(t_stack **a, t_stack	**b, t_stack *cheapest)
{
	size_t	len_a;

	len_a = count_elem(a);
	while (cheapest->pos < (int)len_a)
	{
		rra(a);
		cheapest->pos++;
	}
	while (cheapest->target->pos > 0)
	{
		rb(b);
		cheapest->target->pos--;
	}
}

void	min_on_top(t_stack **a)
{
	while ((*a)->node != find_min(a)->node)
	{
		if (find_min(a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
