/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:23:30 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/07 11:13:45 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *data, int size)
{
	stack	*stack_one;
	stack	*stack_two;
	int		*items1;
	int		*items2;

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
	while (size >= 0)
	{
		stack_one->items[++stack_one->top] = data[size];
		size--;
	}
	sort(&stack_one, &stack_two);
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
	
		res = ft_parser(av, ac);
		data = ft_convert_av(res);
		dup = ft_check_dups(data[0], *data[1]);
		if (!res || !data || dup == 1)
		{
			ft_printf("Error\n");
			return (1);
		}
		push_swap(data[0], *(data[1]));
	}
	return (0);
}