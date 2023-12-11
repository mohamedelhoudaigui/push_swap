/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:23:30 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/10 05:36:17 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *data, int size)
{
	stack	*stack_one;
	stack	*stack_two;
	int		*items1;
	int		*items2;
	int		i;

	stack_one = (stack *)malloc(sizeof(stack));
	stack_two = (stack *)malloc(sizeof(stack));
	items1 = (int *)malloc(sizeof(int) * size);
	items2 = (int *)malloc(sizeof(int) * size);
	if (!stack_one || !stack_two || !items1 || !items2)
		return ;
	stack_one->items = items1;
	stack_two->items = items2;
	stack_one->top = -1;
	stack_two->top = -1;
	size--;
	i = 0;
	while (i <= size)
		stack_one->items[++stack_one->top] = data[i++];
	if (stack_one->top == 1)
		sa(stack_one);
	else if (stack_one->top == 2)
		sort_3(stack_one);
	else if (stack_one->top == 3)
		sort_45(stack_one, stack_two, 4);
	else if (stack_one->top == 4)
		sort_45(stack_one, stack_two, 5);
	else
		sort(stack_one, stack_two);
	free(stack_one->items);
	free(stack_two->items);
	free(stack_one);
	free(stack_two);
	free(data);
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		char	*res;
		int		**data;
		int		dup;
		int		sorted;
		int		i;
	
		i = 0;
		res = ft_parser(av, ac);
		if (!res)
		{
			ft_printf("Error\n");
			free(res);
			return (1);
		}
		data = ft_convert_av(res);
		if (!data)
		{
			ft_printf("Error\n");
			free(data);
			return (1);
		}
		dup = ft_check_dups(data[0], *(data[1]));
		if (dup == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		sorted = ft_check_sorted(data[0], *(data[1]));
		if (sorted == 0)
			return (0);
		push_swap(data[0], *(data[1]));
		free(data);
	}
	return (0);
}