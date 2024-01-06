/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sort_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:59:45 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 18:01:13 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_1(t_stack *a)
{
	rra(a);
	sa(a);
	ft_printf("rra\n");
	ft_printf("sa\n");
}

void	sort_case_2(t_stack *a)
{
	rra(a);
	ft_printf("rra\n");
}

void	sort_case_3(t_stack *a)
{
	sa(a);
	ft_printf("sa\n");
}

void	sort_case_4(t_stack *a, t_node *node1, t_node *node2)
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

void	sort_3(t_stack *a)
{
	t_node	*node0;
	t_node	*node1;
	t_node	*node2;

	node0 = a->items;
	node1 = node0->next;
	node2 = node1->next;
	if (node0->value < node1->value && node1->value < node2->value)
		return ;
	if (node0->value < node1->value && node0->value < node2->value)
		sort_case_1(a);
	else if (node0->value < node1->value && node0->value > node2->value)
		sort_case_2(a);
	else if (node0->value > node1->value && node0->value < node2->value)
		sort_case_3(a);
	else if (node0->value > node1->value && node0->value > node2->value)
		sort_case_4(a, node1, node2);
}
