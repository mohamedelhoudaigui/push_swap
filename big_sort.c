/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:27:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 04:07:02 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_turk(t_stack *a, t_stack *b, int *big_3)
{
	t_node	*a_list;
	int		i;

	a_list = a->items;
	i = 0;
	while (a_list && i < 2)
	{
		if (check_exist(big_3, a_list->value) == 0)
		{
			pb(a, b);
			i += 1;
		}
		else
		{
			ra(a);
			ft_printf("ra\n");
		}
		a_list = a->items;
	}
}

void	clear_target(t_stack *a, t_stack *b)
{
	t_node	*list_a;
	t_node	*list_b;

	list_a = a->items;
	list_b = b->items;
	while (list_a)
	{
		list_a->target_node = NULL;
		list_a = list_a->next;
	}
	while (list_b)
	{
		list_b->target_node = NULL;
		list_b = list_b->next;
	}
}

int	*get_big_3(t_stack *a)
{
	int		*arr;
	int		*big_3;

	arr = make_array(a);
	if (!arr)
		return (NULL);
	big_3 = find_3_largest(arr, a->size);
	free(arr);
	if (!big_3)
		return (NULL);
	return (big_3);
}

void	finish_touch_in(t_stack *b)
{
	t_node	*list_b;
	t_node	*biggest;

	biggest = get_biggest(b);
	list_b = b->items;
	while (list_b->value != biggest->value)
	{
		if (biggest->index <= b->size / 2)
		{
			rb(b);
			ft_printf("rb\n");
		}
		else
		{
			rrb(b);
			ft_printf("rrb\n");
		}
		list_b = b->items;
	}
}

void	turk_algo(t_stack *a, t_stack *b)
{
	int	*big_3;

	big_3 = get_big_3(a);
	if (big_3 == NULL)
		return ;
	init_turk(a, b, big_3);
	algo_in(a, b, big_3);
	free(big_3);
	sort_3(a);
	finish_touch_in(b);
	while (b->size > 0)
		pa(a, b);
}
