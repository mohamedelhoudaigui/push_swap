/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_methods.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 03:11:54 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/11 13:34:49 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(stack *stack)
{
	int	i;

	if (stack->top == -1)
	{
		ft_printf("empty\n");
		return ;
	}
	i = stack->top;
	while (i >= 0)
		ft_printf("%d\n", stack->items[i--]);
}

void	sort_3(stack *a)
{
	if (a->items[2] < a->items[1] && a->items[1] < a->items[0])
		return ;
    if (a->items[2] < a->items[1] && a->items[2] < a->items[0])
	{
		rra(a);
		sa(a);
	}
	else if (a->items[2] > a->items[1] && a->items[2] < a->items[0])
		sa(a);
	else if (a->items[2] < a->items[1] && a->items[2] > a->items[0])
		rra(a);
	else if (a->items[2] > a->items[1] && a->items[2] > a->items[0])
	{
		if (a->items[1] > a->items[0])
		{
			sa(a);
			rra(a);
		}
		else if (a->items[1] < a->items[0])
			ra(a);
	}
}

int		*find_min(int *data, int size)
{
	int	i;
	int	*min;

	i = 0;
	min = (int *)malloc(sizeof(int) * 2);
	if (!min)
		return (NULL);
	min[0] = data[size];
	min[1] = size;
	while (i <= size)
	{
		if (data[i] < min[0])
		{
			min[0] = data[i];
			min[1] = i;
		}
		i++;
	}
	return (min);
}

void sort_45(stack *a, stack *b, int variation)
{
	int	*min;

	if (variation == 5)
	{
		min = find_min(a->items, 4);
		if (!min)
			return ;
		while (a->items[4] != min[0])
		{
			if (min[1] <= 1)
				rra(a);
			else
				ra(a);
		}
		free(min);
		pb(a, b);
	}
	min = find_min(a->items, 3);
   	while (a->items[3] != min[0])
	{
		if (min[1] == 0)
			rra(a);
		else
			ra(a);
	}
	free(min);
    pb(a, b);
    sort_3(a);
    pa(b, a);
	if (variation == 5)
    	pa(b, a);
}

void	sort_array(int	*arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
    while (i < size)
	{
		j = 0;
        while (j < size - i)
		{
            if (arr[j] > arr[j + 1])
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
			j++;
        }
		i++;
    }
}

void	print_table(int *table, int size)
{
	int	i = 0;

	while (i < size)
		ft_printf("%d -", table[i++]);
	ft_printf("\n");
}

int		*make_table(int *table, int size)
{
	int	*table1;
	int	i;

	table1 = (int *)malloc(sizeof(int) * size);
	if (!table1)
		return (NULL);
	i = 0;
	while (i < size)
	{
		table1[i] = table[i];
		i++;
	}
	sort_array(table1, size - 1);
	return (table1);
}

int find_index(int value, int *sorted, int size)
{
	int	i;

	i = 0;
    while (i < size)
	{
        if (sorted[i] == value)
            return (i);
		i++;
    }
    return (-1);
}

int	*make_index(int *table, int *sorted, int start, int end, int size)
{
	int	i;
    int *index;
	int	j;
	
	index = (int *)malloc(sizeof(int) * end - start);
	i = start;
	j = 0;
    if (!index)
        return (NULL);
    while (j < end - start)
	{
        index[j] = find_index(table[i], sorted, size);
		i++;
		j++;
    }
    return (index);
}

int		int_check(int *table, int num, int start, int end)
{
	int	i;

	i = start;
	while (i >= start && i < end)
	{
		if (table[i] == num)
			return (1);
		i++;
	}
	return (0);
}

void	sort(stack *a, stack *b)
{
	int		*sorted;
	int		*index;
	int		start;
	int		end;
	int		diff;
	int		len;
	int		pivot;

	len = a->top + 1;
	start = 0;
	pivot = len / 4;
	end = pivot;
	diff = end - start;
	b->top = b->top;
	sorted = make_table(a->items, a->top + 1);
	index = make_index(a->items, sorted, start, end, a->top + 1);
	//index = make_index(a->items, sorted, a->top + 1);
	if (!sorted || !index)
		return ;
	
	
	// while (a->top != -1)
	// {
	// 	while (b->top != diff - 1)
	// 	{
	// 		if (int_check(sorted, a->items[a->top], start, end) == 1)
	// 			pb(a, b);
	// 		else
	// 			ra(a);
	// 	}
	// 	start = end;
	// 	end = end + pivot;
	// 	diff += pivot;
	// }
	
	free(sorted);
	free(index);
}


