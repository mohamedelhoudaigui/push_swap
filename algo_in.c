/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:56:27 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/04 05:44:35 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_cost(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;
	int		i;

	a_list = a->items;
	b_list = b->items;
	i = 0;
	while (a_list)
	{
		a_list->index = i;
		if (i <= a->size / 2)
			a_list->cost = i;
		else
			a_list->cost = a->size - i;
		a_list = a_list->next;
		i++;
	}
	i = 0;
	while (b_list)
	{
		b_list->index = i;
		if (i <= b->size / 2)
			b_list->cost = i;
		else
			b_list->cost = b->size - i;
		b_list = b_list->next;
		i++;
	}
}

void	calculate_target(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;
	int		save;
	t_node	*no_target;
	t_node	*biggest;

	a_list = a->items;
	b_list = b->items;
	save = INT32_MIN;
	while (a_list)
	{
		b_list = b->items;
		save = INT32_MIN;
		while (b_list)
		{
			if (a_list->value > b_list->value && b_list->value > save)
			{
				a_list->target_node = b_list;
				save = b_list->value;
			}
			b_list = b_list->next;
		}
		a_list = a_list->next;
	}
	no_target = check_no_target(a);
	while (no_target)
	{
		biggest = get_biggest(b);
		no_target->target_node = biggest;
		no_target = check_no_target(a);
	}
}

void	calculate_cost_action(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;
	t_node	*target;
	int		cost;
	int		old_cost;
	t_node	*cheap_node;

	a_list = a->items;
	b_list = b->items;
	old_cost = INT32_MAX;
	cost = INT32_MAX;
	while (a_list)
	{
		target = a_list->target_node;
		if (target != NULL)
		{
			cost = a_list->cost + target->cost;
			if (cost < old_cost)
			{
				cheap_node = a_list;
				old_cost = cost;
			}
		}
		a_list = a_list->next;
	}
	cheap_node->cheap = true;
}

void	movement_of_nodes(t_stack *a, t_stack *b)
{
	t_node	*a_list;
	t_node	*b_list;
	t_node	*target;
	t_node	*cheap_node;
	int		mid_a;
	int		mid_b;

	a_list = a->items;
	b_list = b->items;
	mid_a = a->size / 2;
	mid_b = b->size / 2;
	while (a_list)
	{
		if (a_list->cheap == true)
			cheap_node = a_list;
		a_list = a_list->next;
	}
	target = cheap_node->target_node;
	a_list = a->items;
	b_list = b->items;
	while (a_list->value != cheap_node->value)
	{
		if (cheap_node->index <= mid_a)
		{
			if (target->index <= mid_b)
				rr(a, b);
			else
				ra(a);
		}
		else if (cheap_node->index > mid_a)
		{
			if (target->index > mid_b)
				rrr(a, b);
			else
				rra(a);
		}
		a_list = a->items;
	}
	while (b_list->value != target->value)
	{
		if (target->index <= mid_b)
			rb(b);
		else
			rrb(b);
		b_list = b->items;
	}
	pb(a, b);
	cheap_node->cheap = false;
}


void	algo_in(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		index_cost(a, b);
		calculate_target(a, b);
		calculate_cost_action(a, b);
		movement_of_nodes(a, b);
	}
	
}