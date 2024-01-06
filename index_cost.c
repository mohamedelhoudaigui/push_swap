/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_cost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:10:31 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 04:14:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_cost_helper(t_stack *stack)
{
	t_node	*list;
	int		i;

	list = stack->items;
	i = 0;
	while (list)
	{
		list->index = i;
		if (i <= stack->size / 2)
			list->cost = i;
		else
			list->cost = stack->size - i;
		list = list->next;
		i++;
	}
}

void	index_cost(t_stack **a_p, t_stack **b_p)
{
	t_stack	*a;
	t_stack	*b;

	a = *a_p;
	b = *b_p;
	index_cost_helper(a);
	index_cost_helper(b);
}
