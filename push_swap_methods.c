/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/07 22:03:08 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(stack *stack)
{
	int	i;

	if (stack->top == -1)
	{
		ft_printf("empty\n");
		return ;
	}
	i = stack->top;
	while (i >= 0)
		ft_printf("%d\n", stack->items[i--]);
}

void	sort_3(stack *a)
{
	if (a->items[2] < a->items[1] && a->items[1] < a->items[0])
		return ;
	if (a->items[2] < a->items[1] && a->items[2] < a->items[0])
	{
		rra(a);
		sa(a);
	}
	else if (a->items[2] < a->items[1] && a->items[2] > a->items[0])
		rra(a);
	else if (a->items[2] > a->items[1] && a->items[2] < a->items[0])
		sa(a);
	else if (a->items[2] > a->items[1] && a->items[2] > a->items[0])
	{
		if (a->items[1] > a->items[0])
		{
			sa(a);
			rra(a);
		}
		else
		{
			rra(a);
			rra(a);
		}
	}
}

int	*find_min(int *data, int size)
{
	int	i;
	int	*min;

	i = 0;
	min = (int *)malloc(sizeof(int) * 2);
	if (!min)
		return (NULL);
	min[0] = data[0];
	while (i <= size)
	{
		if (data[i] < min[0])
		{
			min[0] = data[i];
			min[1] = i;
		}
		i++;
	}
	return (min);
}

void	sort_5(stack *a, stack *b)
{
	int	*min;

	min = find_min(a->items, 4);
	if (!min)
		return ;
	while (a->items[4] != min[0])
	{
		if (min[1] < 2)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	free(min);
	min = find_min(a->items, 3);
	while (a->items[3] != min[0])
	{
		if (min[1] == 0)
			rra(a);
		else
			ra(a);
	}
	free(min);
	pb(a, b);
	sort_3(a);
	pa(b, a);
	pa(b, a);
}

void	sort(stack *a, stack *b)
{
	while (a->top >= 0)
	{
		if (b->top == -1 || ((a->items[a->top]) > (b->items[b->top])))
			pb(a, b);
		else if ((a->items[a->top]) < (b->items[b->top]))
		{
			while (b->top >= 0 && (a->items[a->top]) < (b->items[b->top]))
			{
				pa(b, a);
				sa(a);
			}
		}
	}
	while (b->top >= 0)
		pa(b, a);
}
