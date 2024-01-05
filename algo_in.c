/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:56:27 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 06:24:52 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_median(t_stack *a)
{
	int	*arr;
	int	med;

	arr = make_array(a);
	bubble_sort(arr, a->size);
	med = median(arr, a->size);
	return (med);
}

void	index_cost(t_stack **a_p, t_stack **b_p)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*a_list;
	t_node	*b_list;
	int		i;

	a = *a_p;
	b = *b_p;
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

void	calculate_target(t_stack **a_p, t_stack **b_p, int *big_5)
{
	t_stack *a;
	t_stack *b;
	t_node	*a_list;
	t_node	*b_list;
	int		save;
	t_node	*biggest;
	t_node	*no_target;

	a = *a_p;
	b = *b_p;
	a_list = a->items;
	b_list = b->items;
	save = INT32_MIN;
	while (a_list)
	{
		if (check_exist(big_5, a_list->value) == 0)
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
		}
		else
			a_list->target_node = NULL;
		a_list = a_list->next;
	}
	b_list = b->items;
	no_target = check_no_target(a, big_5);
	while (no_target)
	{
		biggest = get_biggest(&b);
		no_target->target_node = biggest;
		no_target = check_no_target(a, big_5);
	}
}

void	calculate_cost_action(t_stack **a_p, t_stack **b_p, int *big_5)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*a_list;
	t_node	*b_list;
	t_node	*target;
	int		cost;
	int		old_cost;
	t_node	*cheap_node;

	a = *a_p;
	b = *b_p;
	cheap_node = NULL;
	a_list = a->items;
	b_list = b->items;
	old_cost = INT32_MAX;
	cost = INT32_MAX;
	while (a_list)
	{
		if (check_exist(big_5, a_list->value) == 0)
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
		}
		a_list = a_list->next;
	}
	if (cheap_node != NULL) 
		cheap_node->cheap = true;
}

void	movement_of_nodes(t_stack **a_p, t_stack **b_p)
{
	t_stack	*a;
	t_stack	*b;
	t_node	*a_list;
	t_node	*b_list;
	t_node	*target;
	t_node	*cheap_node;
	int		mid_a;
	int		mid_b;

	a = *a_p;
	b = *b_p;
	a_list = a->items;
	b_list = b->items;
	mid_a = a->size / 2;
	mid_b = b->size / 2;
	cheap_node = NULL;
	while (a_list)
	{
		if (a_list->cheap == true)
			cheap_node = a_list;
		a_list = a_list->next;
	}
	if (cheap_node == NULL)
		return ;
	target = cheap_node->target_node;
	a_list = a->items;
	b_list = b->items;
	while (b_list->value != target->value)
	{
		if (target->index <= mid_b)
		{
			if (a_list->value != cheap_node->value && cheap_node->index <= mid_a)
				rr(a,b);
			else
			{
				rb(b);
				ft_printf("rb\n");
			}
		}
		else if (target->index > mid_b)
		{
			if (a_list->value != cheap_node->value && cheap_node->index > mid_a)
				rrr(a, b);
			else
			{
				rrb(b);
				ft_printf("rrb\n");
			}
		}
		a_list = a->items;
		b_list = b->items;
	}
	while (b_list->value != target->value)
	{
		if (target->index <= mid_b)
		{
			rb(b);
			ft_printf("rb\n");
		}
		else
		{
			rrb(b);
			ft_printf("rrb\n");
		}
		b_list = b->items;
	}
	a_list = a->items;
	b_list = b->items;
	pb(a, b);
	cheap_node->cheap = false;
}


void	algo_in(t_stack *a, t_stack *b, int *big_5)
{
	while (a->size > 3)
	{
		index_cost(&a, &b);
		calculate_target(&a, &b, big_5);
		calculate_cost_action(&a, &b, big_5);
		movement_of_nodes(&a, &b);
		clear_target(a, b);
	}

}