/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_out_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:36:09 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/12 02:02:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_array(t_stack *head)
{
	t_node	*list_stack;
	int		i;
	int		*arr;

	i = 0;
	list_stack = head->items;
	arr = (int *)ft_calloc(head->size, sizeof(int));
	while (i < head->size)
	{
		arr[i] = list_stack->value;
		i++;
		list_stack = list_stack->next;
	}
	return (arr);
}

int	check_exist(int *big_3, int value)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (big_3[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void	swap(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	bubble_sort(int *arr, int n)
{
	int	swapped;
	int	i;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < n - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
	}
}
