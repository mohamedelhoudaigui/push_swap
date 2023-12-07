/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 02:45:44 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/07 19:14:31 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(stack *a)
{
	int tmp;
	if (a->top > 0)
	{
		tmp = a->items[a->top];
		a->items[a->top] = a->items[a->top - 1];
		a->items[a->top - 1] = tmp;
	}
	ft_printf("sa\n");
}

void    sb(stack *b)
{
	int tmp;
	if (b->top > 0)
	{
		tmp = b->items[b->top];
		b->items[b->top] = b->items[b->top - 1];
		b->items[b->top - 1] = tmp;
	}
	ft_printf("sb\n");
}

void    ss(stack *a, stack *b)
{
	sa(a);
	sb(b);
}

void    pa(stack *b, stack *a)
{
	if (b->top > -1)
	{
		a->items[a->top + 1] = b->items[b->top];
		a->top++;
		b->top--;
	}
	ft_printf("pa\n");
}

void    pb(stack *a, stack *b)
{
	if (a->top > -1)
	{
		b->items[b->top + 1] = a->items[a->top];
		b->top++;
		a->top--;
	}
	ft_printf("pb\n");
}

void    rra(stack *a)
{
	int	tmp;
	int	i;
	
	i = 0;
	if (a->top > 0)
	{
		while (i < a->top)
		{
			tmp = a->items[i];
			a->items[i] = a->items[i + 1];
			a->items[i + 1] = tmp;
			i++;
		}
	}
	ft_printf("rra\n");
}

void    rrb(stack *b)
{
	int	tmp;
	int	i;
	
	i = 0;
	if (b->top > 0)
	{
		while (i < b->top)
		{
			tmp = b->items[i];
			b->items[i] = b->items[i + 1];
			b->items[i + 1] = tmp;
			i++;
		}
	}
	ft_printf("rrb\n");
}


void	ra(stack *a)
{
	int	i;
	int	tmp;

	i = a->top;
	if (a->top > 0)
	{
		while (i > 0)
		{
			tmp = a->items[i];
			a->items[i] = a->items[i - 1];
			a->items[i - 1] = tmp;
			i--;
		}
	}
	ft_printf("ra\n");
}

void	rb(stack *b)
{
	int	i;
	int	tmp;

	i = b->top;
	if (b->top > 0)
	{
		while (i > 0)
		{
			tmp = b->items[i];
			b->items[i] = b->items[i - 1];
			b->items[i - 1] = tmp;
			i--;
		}
	}
	ft_printf("rb\n");
}

void	rrr(stack *a, stack *b)
{
	rra(a);
	rrb(b);
}

void	rr(stack *a, stack *b)
{
	ra(a);
	rb(b);
}