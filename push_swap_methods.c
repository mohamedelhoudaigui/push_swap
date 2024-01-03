/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/03 06:32:15 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	t_node *node_0 = a->items;
	t_node *node_1 = node_0->next;
	t_node *node_2 = node_1->next;

	if (node_0->value < node_2)
}

// int		*find_min(int *data, int size)
// {
// 	int	i;
// 	int	*min;

// 	i = 0;
// 	min = (int *)malloc(sizeof(int) * 2);
// 	if (!min)
// 		return (NULL);
// 	min[0] = data[size];
// 	min[1] = size;
// 	while (i <= size)
// 	{
// 		if (data[i] < min[0])
// 		{
// 			min[0] = data[i];
// 			min[1] = i;
// 		}
// 		i++;
// 	}
// 	return (min);
// }

// void sort_45(t_stack *a, t_stack *b, int variation)
// {
// 	int	*min;

// 	if (variation == 5)
// 	{
// 		min = find_min(a->items, 4);
// 		if (!min)
// 			return ;
// 		while (a->items[4] != min[0])
// 		{
// 			if (min[1] <= 1)
// 				rra(a);
// 			else
// 				ra(a);
// 		}
// 		free(min);
// 		pb(a, b);
// 	}
// 	min = find_min(a->items, 3);
//    	while (a->items[3] != min[0])
// 	{
// 		if (min[1] == 0)
// 			rra(a);
// 		else
// 			ra(a);
// 	}
// 	free(min);
//     pb(a, b);
//     sort_3(a);
//     pa(b, a);
// 	if (variation == 5)
//     	pa(b, a);
// }
