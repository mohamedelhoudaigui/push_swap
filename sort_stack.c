/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:22:03 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 18:01:30 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		sa(a);
		ft_printf("sa\n");
	}
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		turk_algo(a, b);
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
