/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:49:24 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 17:49:57 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
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
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
