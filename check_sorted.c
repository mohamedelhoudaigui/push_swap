/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 04:04:20 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorted(int	*data, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (data[i] > data[i + 1])
			return (1);
		i++;
	}
	return (0);
}

t_node	*get_biggest(t_stack *stack)
{
	t_node	*t_list;
	t_node	*biggest_node;
	int		biggest;

	biggest_node = NULL;
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
