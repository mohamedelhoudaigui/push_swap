/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods_4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 05:47:01 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 05:56:12 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p_rb(t_stack *b)
{
	rb(b);
	ft_printf("rb\n");
}

void	p_ra(t_stack *a)
{
	ra(a);
	ft_printf("ra\n");
}

void	p_rrb(t_stack *b)
{
	rrb(b);
	ft_printf("rrb\n");
}

void	p_rra(t_stack *a)
{
	rra(a);
	ft_printf("rra\n");
}
