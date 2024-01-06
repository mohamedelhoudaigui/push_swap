/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:14:36 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 04:19:16 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_lists(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;

	b_list = b->items;
	a_list = a->items;
	while (a_list)
	{
		a_list->target_node = NULL;
		a_list = a_list->next;
	}
	while (b_list)
	{
		b_list->target_node = NULL;
		b_list = b_list->next;
	}
}

void	assign_target_nodes(t_stack *a, t_stack *b, int *big_5)
{
	t_node	*a_list;
	t_node	*b_list;
	int		save;

	a_list = a->items;
	while (a_list)
	{
		if (check_exist(big_5, a_list->value) == 0)
		{
			b_list = b->items;
			save = INT32_MIN;
			while (b_list)
			{
				if (a_list->value > b_list->value && b_list->value > save)
				{
					a_list->target_node = b_list;
					save = b_list->value;
				}
				b_list = b_list->next;
			}
		}
		a_list = a_list->next;
	}
}

void	assign_remaining_targets(t_stack *a, t_stack *b, int *big_5)
{
	t_node	*no_target;
	t_node	*biggest;

	no_target = check_no_target(a, big_5);
	while (no_target)
	{
		biggest = get_biggest(b);
		no_target->target_node = biggest;
		no_target = check_no_target(a, big_5);
	}
}

void	calculate_target(t_stack **a_p, t_stack **b_p, int *big_5)
{
	t_stack	*a;
	t_stack	*b;

	a = *a_p;
	b = *b_p;
	initialize_lists(a, b);
	assign_target_nodes(a, b, big_5);
	assign_remaining_targets(a, b, big_5);
}
