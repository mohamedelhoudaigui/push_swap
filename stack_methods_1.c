/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:45:44 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:17 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*items;

	if (!stack || !stack->items)
	{
		ft_printf("empty stack\n");
		return ;
	}
	items = stack->items;
	ft_printf("\n");
	while (items)
	{
		ft_printf("value : %d addr : %p\n", items->value, items);
		items = items->next;
	}
	ft_printf("\n");
}

void	free_stack(t_stack *stack)
{
	t_node	*lst1;
	t_node	*tmp;

	lst1 = stack->items;
	while (lst1)
	{
		tmp = lst1->next;
		free(lst1);
		lst1 = tmp;
	}
	stack->items = NULL;
	free(stack);
	stack = NULL;
}

void	init_stacks(t_stack *a, t_stack *b, int size, int *data)
{
	int		i;
	t_node	*tmp;
	int		med;

	i = 0;
	med = size / 2;
	a->size = size;
	b->size = 0;
	a->top = size - 1;
	b->top = -1;
	while (i < size)
	{
		tmp = t_node_new(data[i]);
		tmp->index = i;
		tmp->target_node = NULL;
		if (i <= med)
			tmp->cost = i;
		else
			tmp->cost = size - i;
		tmp->cheap = false;
		t_node_add_back(&a->items, tmp);
		i++;
	}
}

void	sa(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp_next;
	t_node	*tmp_next_next;

	if (a->size < 2)
		return ;
	tmp = a->items;
	tmp_next = tmp->next;
	if (a->size == 2)
	{
		tmp_next->next = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp_next_next = tmp_next->next;
		tmp_next_next->prev = tmp;
		tmp->next = tmp_next_next;
		tmp_next->next = tmp;
	}
	tmp->prev = tmp_next;
	tmp_next->prev = NULL;
	a->items = tmp_next;
}
