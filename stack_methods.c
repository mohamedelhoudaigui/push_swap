/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:45:44 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/03 06:00:01 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node *items;

	if (!stack || !stack->items)
	{
		ft_printf("empty stack\n");
		return ;
	}
	items = stack->items;
	while (items)
	{
		ft_printf("%d\n", items->value);
		items = items->next;
	}
}

void	init_stacks(t_stack *a, t_stack *b, int size, int *data)
{
	int		i;
	t_node	*tmp;
	t_node	*tmp2;

	i = 0;
	a->size = size;
	b->size = size;
	a->top = size - 1;
	b->top = size - 1;
	a->items = t_node_new(data[0]);
	b->items = t_node_new(data[0]);
	while (++i < size)
	{
		tmp = t_node_new(data[i]);
		tmp2 = t_node_new(data[i]);
		t_node_add_back(&a->items, tmp);
		t_node_add_back(&b->items, tmp2);
	}
}

void	sa(t_stack *a)
{
	t_node	*tmp;
	t_node	*tmp_next;
	t_node	*tmp_next_next;

	if (a->size <= 1)
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
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*tmp;
	t_node	*tmp_next;
	t_node	*tmp_next_next;

	if (b->size <= 1)
		return ;
	tmp = b->items;
	tmp_next = tmp->next;
	if (b->size == 2)
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
	b->items = tmp_next;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node *head_a;
	t_node *head_b;

	if (b->size == 0 || b->items == NULL)
		return ;
	head_b = b->items;
	head_a = a->items;
	b->items = head_b->next;
	head_b->next->prev = NULL;
	head_b->next = NULL;
	t_node_add_front(&a->items, head_b);
	a->size++;
	a->top++;
	b->size--;
	b->top--;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	t_node *head_a;
	t_node *head_b;

	if (a->size == 0 || a->items == NULL)
		return ;
	head_b = b->items;
	head_a = a->items;
	a->items = head_a->next;
	head_a->next->prev = NULL;
	head_a->next = NULL;
	t_node_add_front(&b->items, head_a);
	b->size++;
	b->top++;
	a->size--;
	a->top--;
	ft_printf("pb\n");
}

void	ra(t_stack *a)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (a->size < 2)
		return ;
	head = a->items;
	tmp1 = head->next;
	tmp2 = t_node_last(head);
	tmp1->prev = NULL;
	head->next = NULL;
	tmp2->next = head;
	head->prev = tmp2;
	a->items = tmp1;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (b->size < 2)
		return ;
	head = b->items;
	tmp1 = head->next;
	tmp2 = t_node_last(head);
	tmp1->prev = NULL;
	head->next = NULL;
	tmp2->next = head;
	head->prev = tmp2;
	b->items = tmp1;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (a->size < 2)
		return ;
	head = a->items;
	tmp1 = t_node_last(head);
	tmp2 = tmp1->prev;
	tmp2->next = NULL;
	tmp1->next = head;
	tmp1->prev = NULL;
	head->prev = tmp1;
	a->items = tmp1;
	ft_printf("rra\n");
}