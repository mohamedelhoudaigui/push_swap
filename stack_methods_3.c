/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:50:29 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 17:50:37 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss");
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*head_a;
	t_node	*head_b;
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

void	pb(t_stack *a, t_stack *b)
{
	t_node	*head_a;
	t_node	*head_b;
	t_node	*next_a;

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
}
