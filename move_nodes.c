/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 04:40:00 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 06:02:05 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheap_node(t_stack *a)
{
	t_node	*a_list;
	t_node	*cheap_node;

	a_list = a->items;
	while (a_list)
	{
		if (a_list->cheap == true)
		{
			cheap_node = a_list;
			return (cheap_node);
		}
		a_list = a_list->next;
	}
	return (NULL);
}

void	move_b(t_stack *a, t_stack *b, t_node *ch_n, t_node *t)
{
	t_node	*b_list;
	t_node	*a_list;

	a_list = a->items;
	b_list = b->items;
	while (b_list->value != t->value)
	{
		if (t->index <= b->size / 2)
		{
			if (a_list->value != ch_n->value && ch_n->index <= a->size / 2)
				rr(a, b);
			else
				p_rb(b);
		}
		else if (t->index > b->size / 2)
		{
			if (a_list->value != ch_n->value && ch_n->index > a->size / 2)
				rrr(a, b);
			else
				p_rrb(b);
		}
		a_list = a->items;
		b_list = b->items;
	}
}

void	move_a(t_stack *a, t_node *cheap_node)
{
	t_node	*a_list;

	a_list = a->items;
	while (a_list->value != cheap_node->value)
	{
		if (cheap_node->index <= a->size / 2)
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
		{
			rra(a);
			ft_printf("rra\n");
		}
		a_list = a->items;
	}
}

void	movement_of_nodes(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;
	t_node	*target;
	t_node	*cheap_node;

	a_list = a->items;
	b_list = b->items;
	cheap_node = get_cheap_node(a);
	if (cheap_node == NULL)
		return ;
	target = cheap_node->target_node;
	a_list = a->items;
	b_list = b->items;
	move_b(a, b, cheap_node, target);
	move_a(a, cheap_node);
	pb(a, b);
	cheap_node->cheap = false;
}
