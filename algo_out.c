/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:59:23 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 04:57:51 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	link_three(t_stack *a, t_stack *b)
// {
// 	t_node	*a_list;
// 	t_node	*b_list;
// 	t_node	*target;
// 	t_node	*no_target;
// 	t_node	*smallest;

// 	a_list = a->items;
// 	b_list = b->items;
// 	while (b_list)
// 	{
// 		a_list = a->items;
// 		target = NULL; // Initialize target to NULL before comparing values
// 		while (a_list)
// 		{
// 			if (a_list->value > b_list->value)
// 			{
// 				if (target == NULL || a_list->value < target->value)
// 					target = a_list;
// 			}
// 			a_list = a_list->next;
// 		}
// 		b_list->target_node = target; // Assign the target node for the current b_list node
// 		b_list = b_list->next;
// 	}
// 	no_target = check_no_target(b);
// 	while (no_target)
// 	{
// 		smallest = get_smallest(a);
// 		no_target->target_node = smallest;
// 		no_target = check_no_target(b);
// 	}
// }

// void	push_back(t_stack *a, t_stack *b)
// {
// 	t_node	*a_list;
// 	t_node	*b_list;
// 	t_node	*target;
// 	int		a_mid;

// 	a_list = a->items;
// 	b_list = b->items;
// 	target = b_list->target_node;
// 	a_mid = a->size / 2;
// 	while (a_list->value != target->value)
// 	{
// 		if (target->index <= a_mid)
// 		{
// 			ra(a);
// 			ft_printf("ra\n");
// 		}
// 		else
// 		{
// 			rra(a);
// 			ft_printf("rra\n");
// 		}
// 		a_list = a->items;
// 	}
// 	pa(a, b);
// }

void	finish_touch_in(t_stack *b)
{
	t_node	*list_b;
	t_node	*biggest;
	
	biggest = get_biggest(&b);
	list_b = b->items;
	while (list_b->value != biggest->value)
	{
		if (biggest->index <= b->size / 2)
		{
			rb(b);
			ft_printf("rb\n");
		}
		else
		{
			rrb(b);
			ft_printf("rrb\n");
		}
		list_b = b->items;
	}
}

void	algo_out(t_stack *a, t_stack *b)
{
	(void)a;
	finish_touch_in(b);
}