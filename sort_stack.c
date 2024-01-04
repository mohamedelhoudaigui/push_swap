/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:22:03 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/04 01:51:13 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		turk_algo(a, b);
}

void	sort_3(t_stack *a)
{
	t_node *node0 = a->items;
	t_node *node1 = node0->next;
	t_node *node2 = node1->next;

	if (node0->value < node1->value && node0->value < node2->value)
	{
		rra(a);
		sa(a);
		ft_printf("rra\n");
		ft_printf("sa\n");
	}
	else if (node0->value < node1->value && node0->value > node2->value)
	{
		rra(a);
		ft_printf("rra\n");
	}
	else if (node0->value > node1->value && node0->value < node2->value)
	{
		sa(a);
		ft_printf("sa\n");
	}
	else if (node0->value > node1->value && node0->value > node2->value)
	{
		if (node1->value < node2->value)
		{
			rra(a);
			rra(a);
			ft_printf("rra\n");
			ft_printf("rra\n");
		}
		else if (node1->value > node2->value)
		{
			sa(a);
			rra(a);
			ft_printf("sa\n");
			ft_printf("rra\n");
		}
	}
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_min(a, b);
	push_min(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_4(t_stack *a, t_stack *b)
{
	push_min(a, b);
	sort_3(a);
	pa(a, b);
}