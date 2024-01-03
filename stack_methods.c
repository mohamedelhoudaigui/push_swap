/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:45:44 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/03 09:26:35 by mel-houd         ###   ########.fr       */
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

	i = 0;
	a->size = size;
	b->size = 0;
	a->top = size - 1;
	b->top = -1;
	while (i < size)
	{
		tmp = t_node_new(data[i]);
		tmp->index = i;
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
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	t_node	*tmp;
	t_node	*tmp_next;
	t_node	*tmp_next_next;

	if (b->size < 2)
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
	t_node	*next_b;

	if (b->items == NULL)
		return ;
	head_b = b->items;
	next_b = head_b->next;
	head_a = a->items;
	if (next_b != NULL)
		next_b->prev = NULL;
	b->items = next_b;
	a->items = head_b;
	head_b->next = NULL;
	head_b->next = head_a;
	if (a->items->next != NULL)
		head_a->prev = head_b;
	head_b->prev = NULL;
	a->size++;
	a->top++;
	b->size--;
	b->top--;
	ft_printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
	t_node *head_a;
	t_node *head_b;
	t_node *next_a;

	if (a->items == NULL)
		return ;
	head_a = a->items;
	next_a = head_a->next;
	head_b = b->items;
	if (next_a != NULL)
		next_a->prev = NULL;
	a->items = next_a;
	b->items = head_a;
	head_a->next = NULL;
	head_a->next = head_b;
	if (b->items->next != NULL)
		head_b->prev = head_a;
	head_a->prev = NULL;
	a->size--;
	a->top--;
	b->size++;
	b->top++;
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

void	rrb(t_stack *b)
{
	t_node	*head;
	t_node	*tmp1;
	t_node	*tmp2;

	if (b->size < 2)
		return ;
	head = b->items;
	tmp1 = t_node_last(head);
	tmp2 = tmp1->prev;
	tmp2->next = NULL;
	tmp1->next = head;
	tmp1->prev = NULL;
	head->prev = tmp1;
	b->items = tmp1;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}