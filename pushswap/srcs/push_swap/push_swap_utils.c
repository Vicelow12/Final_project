/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngaulthi <ngaulthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:21:39 by ngaulthi          #+#    #+#             */
/*   Updated: 2024/04/25 19:36:28 by ngaulthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

size_t	count_elem(t_stack **stk)
{
	size_t	i;
	t_stack	*cur;

	cur = *stk;
	i = 0;
	while (cur != NULL)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

size_t	nb_nodes(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	return ((int)i);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_stack	*find_max(t_stack **stk)
{
	t_stack	*cur;
	t_stack	*mem;

	cur = *stk;
	mem = *stk;
	while (cur != NULL)
	{
		if (cur->index > mem->index)
			mem = cur;
		cur = cur->next;
	}
	return (mem);
}

t_stack	*find_min(t_stack **stk)
{
	t_stack	*cur;
	t_stack	*mem;

	cur = *stk;
	mem = *stk;
	while (cur != NULL)
	{
		if (cur->index < mem->index)
			mem = cur;
		cur = cur->next;
	}
	return (mem);
}
