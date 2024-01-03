/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/03 09:29:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *a)
{
	t_node *node0 = a->items;
	t_node *node1 = node0->next;
	t_node *node2 = node1->next;

	if (node0->value < node1->value && node0->value < node2->value)
	{
		rra(a);
		sa(a);
	}
	else if (node0->value < node1->value && node0->value > node2->value)
		rra(a);
	else if (node0->value > node1->value && node0->value < node2->value)
		sa(a);
	else if (node0->value > node1->value && node0->value > node2->value)
	{
		if (node1->value < node2->value)
		{
			rra(a);
			rra(a);
		}
		else if (node1->value > node2->value)
		{
			sa(a);
			rra(a);
		}
	}
}

int	*find_min(t_node *head)
{
	int		*min;
	int		i;
	t_node	*tmp;

    if (!head)
        return NULL;
	min = (int *)malloc(sizeof(int) * 2);
	if (!min)
		return (NULL);
    min[0] = head->value;
    min[1] = 0;
    i = 0;
    tmp = head;
    while (tmp)
	{
        if (tmp->value < min[0])
		{
            min[0] = tmp->value;
            min[1] = i;
        }
        tmp = tmp->next;
        i++;
    }
    return min;
}

void	push_min(t_stack *a, t_stack *b)
{
	int		*min;
	t_node	*head;

	head = a->items;
	if (head == NULL)
		return ;
	min = find_min(a->items);
	if (!min)
		return ;
	while (head->value != min[0])
	{
		if (min[1] == 1 || min[1] == 2)
			ra(a);
		else if (min[1] == 3 || min[1] == 4)
			rra(a);
		head = a->items;
	}
	pb(a, b);
	free(min);
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

// void	sort_4(t_stack *a, t_stack *b)
// {
// 	push_min(a, b);
// 	sort_3(a);
// 	pa(a, b);
// }

// void sort_5(t_stack *a, t_stack *b)
// {
// 	int	*min;

// 	if (variation == 5)
// 	{
// 		min = find_min(a->items, 4);
// 		if (!min)
// 			return ;
// 		while (a->items[4] != min[0])
// 		{
// 			if (min[1] <= 1)
// 				rra(a);
// 			else
// 				ra(a);
// 		}
// 		free(min);
// 		pb(a, b);
// 	}
// 	min = find_min(a->items, 3);
//    	while (a->items[3] != min[0])
// 	{
// 		if (min[1] == 0)
// 			rra(a);
// 		else
// 			ra(a);
// 	}
// 	free(min);
//     pb(a, b);
//     sort_3(a);
//     pa(b, a);
// 	if (variation == 5)
//     	pa(b, a);
// }
