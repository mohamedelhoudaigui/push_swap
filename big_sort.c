/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:27:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 06:20:43 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_turk(t_stack *a, t_stack *b, int *big_5)
{
	t_node	*a_list;
	int		i;

	a_list = a->items;
	i = 0;
	while (a_list && i < 2)
	{
		if (check_exist(big_5, a_list->value) == 0)
		{
			pb(a, b);
			i += 1;
		}
		else
		{
			ra(a);
			ft_printf("ra\n");
		}
		a_list = a->items;
	}
}

t_node	*get_biggest(t_stack **stack_p)
{
	t_stack	*stack;
	t_node	*t_list;
	t_node	*biggest_node;
	int		biggest;

	biggest_node = NULL;
	stack = *stack_p;
	t_list = stack->items;
	biggest = INT32_MIN;
	while (t_list)
	{
		if (t_list->value > biggest)
		{
			biggest_node = t_list;
			biggest = biggest_node->value;
		}
		t_list = t_list->next;
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

t_node	*check_no_target(t_stack *a, int *big_5)
{
	t_node	*a_list;
	
	a_list = a->items;
	while (a_list)
	{
		if (a_list->target_node == NULL && check_exist(big_5, a_list->value) == 0)
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

int		*get_big_5(t_stack *a)
{
	int		*arr;
	int		*big_5;

	arr = make_array(a);
	if (!arr)
		return (NULL);
	big_5 = find_5_largest(arr, a->size);
	free(arr);
	if (!big_5)
		return (NULL);
	return (big_5);
}

int		*get_big_3(t_stack *a)
{
	int		*arr;
	int		*big_3;

	arr = make_array(a);
	if (!arr)
		return (NULL);
	big_3 = find_3_largest(arr, a->size);
	free(arr);
	if (!big_3)
		return (NULL);
	return (big_3);
}

void	turk_algo(t_stack *a, t_stack *b)
{
	int	*big_5;

	big_5 = get_big_5(a);
	if (big_5 == NULL)
		return ;
	init_turk(a, b, big_5);
	algo_in(a, b, big_5);
	sort_3(a);
	algo_out(a, b);
	while (b->size > 0)
		pa(a, b);
}