/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:22:25 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_stack **stk)
{
	t_stack	*cur;
	t_stack	*prev_cur;
	size_t	i;

	if (*stk == NULL)
		return ;
	cur = *stk;
	prev_cur = *stk;
	i = 0;
	while (cur->next != NULL)
	{
		cur = cur->next;
		if (i > 0)
			prev_cur = prev_cur->next;
		i++;
	}
	cur->next = *stk;
	*stk = cur;
	prev_cur->next = NULL;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
