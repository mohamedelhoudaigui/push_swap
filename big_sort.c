/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:27:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/04 10:33:08 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_turk(t_stack *a, t_stack *b)
{
	pb(a, b);
	pb(a, b);
}

t_node	*get_biggest(t_stack *stack)
{
	t_node	*stack_list;
	int		bigest;
	t_node	*biggest_node;

	stack_list = stack->items;
	bigest = INT32_MIN;
	while (stack_list)
	{
		if (stack_list->value > bigest)
		{
			bigest = stack_list->value;
			biggest_node = stack_list;
		}
		stack_list = stack_list->next;
	}
	return (biggest_node);
}

t_node	*get_smallest(t_stack *stack)
{
	t_node	*stack_list;
	int		small;
	t_node	*small_node;

	stack_list = stack->items;
	small = INT32_MAX;
	while (stack_list)
	{
		if (stack_list->value < small)
		{
			small = stack_list->value;
			small_node = stack_list;
		}
		stack_list = stack_list->next;
	}
	return (small_node);
}

t_node	*check_no_target(t_stack *a)
{
	t_node	*a_list;
	
	a_list = a->items;
	while (a_list)
	{
		if (a_list->target_node == NULL)
			return (a_list);
		a_list = a_list->next;
	}
	return (NULL);
}

void	clear_target(t_stack *a, t_stack *b)
{
	t_node	*list_a;
	t_node	*list_b;

	list_a = a->items;
	list_b = b->items;

	while (list_a)
	{
		list_a->target_node = NULL;
		list_a = list_a->next;
	}
	while (list_b)
	{
		list_b->target_node = NULL;
		list_b = list_b->next;
	}
}

void	finish_touch(t_stack *a)
{
	t_node	*a_list;
	t_node	*smallest;

	a_list = a->items;
	smallest = get_smallest(a);
	while (a_list->value != smallest->value)
	{
		if (smallest->index <= a->size / 2)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			rra(a);
			ft_printf("rra\n");
		}
		a_list = a->items;
	}
}


void	turk_algo(t_stack *a, t_stack *b)
{
	init_turk(a, b);
	algo_in(a, b);
	sort_5(a, b);
	clear_target(a, b);
	algo_out(a, b);
	clear_target(a, b);
	finish_touch(a);
}