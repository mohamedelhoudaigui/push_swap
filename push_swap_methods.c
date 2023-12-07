/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/05 02:03:38 by mel-houd         ###   ########.fr       */
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

void	sort(stack **a_d, stack **b_d)
{
	stack	*a;
	stack	*b;

	a = *a_d;
	b = *b_d;
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
