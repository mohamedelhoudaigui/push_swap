/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:23:30 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/15 06:47:12 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(int **res)
{
	int	i;

	if (!res)
		return (1);
	i = 0;
	while (i < *res[1])
	{
		if (i == *res[1] - 1)
			break ;
		if (res[0][i] > res[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	f(void)
{
	system("leaks push_swap");
}

void	free_res(int **res)
{
	free(res[0]);
	free(res[1]);
	free(res);
	res = NULL;
}

void	push_swap(int ***data_p)
{
	t_stack	*a;
	t_stack	*b;
	int		**data_ar;
	int		size;
	int		*data;

	data_ar = *data_p;
	size = *data_ar[1];
	data = data_ar[0];
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	init_stacks(a, b, size, data);
	sort_stack(a, b);
	free_stack(a);
	free_stack(b);
	free_res(data_ar);
}

int	main(int ac, char **av)
{
	int		**data_ar;

	atexit(f);
	if (ac < 2)
		return (0);
	data_ar = parser(av);
	if (data_ar == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (check_sorted(data_ar) == 1)
	{
		free_res(data_ar);
		return (0);
	}
	push_swap(&data_ar);
	return (0);
}
