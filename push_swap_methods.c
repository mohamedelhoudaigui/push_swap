/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/04 01:52:37 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		{
			ra(a);
			ft_printf("ra\n");
		}
		else if (min[1] == 3 || min[1] == 4)
		{
			rra(a);
			ft_printf("rra\n");
		}
		head = a->items;
	}
	pb(a, b);
	free(min);
}