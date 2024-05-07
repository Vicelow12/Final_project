/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:21:58 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_target_b(t_stack **a, t_stack **b, size_t nb_node)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	size_t	best_match_index;
	int		check;

	cur_b = *b;
	cur_a = *a;
	best_match_index = nb_node;
	check = 0;
	while (cur_a != NULL)
	{
		if (cur_a->index > cur_b->index && cur_a->index <= best_match_index)
		{
			best_match_index = cur_a->index;
			cur_b->target = cur_a;
			check = 1;
		}
		cur_a = cur_a->next;
	}
	if (check == 0)
		cur_b->target = find_min(a);
}

void	set_cheapest(t_stack **stk)
{
	t_stack	*cur;
	t_stack	*cheapest_node;
	size_t	cheapest_value;

	if (!stk)
		return ;
	cur = *stk;
	cheapest_node = cur;
	cheapest_value = cur->push_cost;
	while (cur != NULL)
	{
		if (cur->push_cost < cheapest_value)
		{
			cheapest_node = cur;
			cheapest_value = cur->push_cost;
		}
		cur->cheapest = 0;
		cur = cur->next;
	}
	cheapest_node->cheapest = 1;
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	size_t	best_match_index;

	cur_a = *a;
	while (cur_a != NULL)
	{
		best_match_index = 0;
		cur_b = *b;
		while (cur_b != NULL)
		{
			if ((cur_b->index < cur_a->index)
				&& (cur_b->index > best_match_index))
			{
				best_match_index = cur_b->index;
				cur_a->target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best_match_index == 0)
			cur_a->target = find_max(b);
		cur_a = cur_a->next;
	}
}

void	set_pos(t_stack **a)
{
	size_t	pos;
	t_stack	*cur;
	size_t	median;

	pos = 0;
	cur = *a;
	median = (count_elem(a) + 1) / 2;
	while (cur != NULL)
	{
		if (pos + 1 <= median)
			cur->above_median = 1;
		else
			cur->above_median = 0;
		cur->pos = pos++;
		cur = cur->next;
	}
}

void	set_push_cost(t_stack **a, t_stack **b)
{
	size_t	len_a;
	size_t	len_b;
	t_stack	*cur_a;

	len_a = count_elem(a);
	len_b = count_elem(b);
	cur_a = *a;
	while (cur_a != NULL)
	{
		if (cur_a->above_median == 1)
			push_cost_above_median(cur_a, len_b);
		else
			push_cost_below_median(cur_a, len_a, len_b);
		cur_a = cur_a->next;
	}
}
