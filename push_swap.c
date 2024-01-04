/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:23:30 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/04 10:28:43 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *data, int size)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	init_stacks(a, b, size, data);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
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