/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:22:11 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 04:30:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_variables(int *old_cost, int *cost, t_node **cheap_node)
{
	*old_cost = INT32_MAX;
	*cost = INT32_MAX;
	*cheap_node = NULL;
}

void	calculate_cost(t_node *a_list, t_node *target, int *cost)
{
	*cost = a_list->cost + target->cost;
}

void	update_cheap(t_node *a_list, int *old_cost, int cost, t_node **cheap)
{
	if (cost < *old_cost)
	{
		*cheap = a_list;
		*old_cost = cost;
	}
}

t_node	*find_cheap_node(t_stack *a, int *big_3)
{
	t_node	*a_list;
	t_node	*target;
	int		old_cost;
	int		cost;
	t_node	*cheap_node;

	a_list = a->items;
	initialize_variables(&old_cost, &cost, &cheap_node);
	while (a_list)
	{
		if (check_exist(big_3, a_list->value) == 0)
		{
			target = a_list->target_node;
			if (target != NULL)
			{
				calculate_cost(a_list, target, &cost);
				update_cheap(a_list, &old_cost, cost, &cheap_node);
			}
		}
		a_list = a_list->next;
	}
	return (cheap_node);
}

void	calculate_cost_action(t_stack **a_p, t_stack **b_p, int *big_3)
{
	t_stack	*a;
	t_node	*cheap_node;

	(void)b_p;
	a = *a_p;
	cheap_node = find_cheap_node(a, big_3);
	if (cheap_node != NULL)
		cheap_node->cheap = true;
}
