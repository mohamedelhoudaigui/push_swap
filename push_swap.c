/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:23:30 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/07 09:02:55 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data_ar(int **data_ar)
{
	int	*data;

	data = data_ar[0];
	free(data);
	free(data_ar);
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
	free_data_ar(data_ar);
}

int	**parser(char	**av, int ac)
{
	char	*res;
	int		dup;
	int		**data_ar;

	res = ft_parser(av, ac);
	if (!res)
		return (NULL);
	data_ar = ft_convert_av(res);
	if (!data_ar)
	{
		free(res);
		return (NULL);
	}
	dup = ft_check_dups(data_ar[0], *(data_ar[1]));
	if (dup == 1)
	{
		free(data_ar[0]);
		free(data_ar);
		return (NULL);
	}
	return (data_ar);
}

int	main(int ac, char **av)
{
	int		**data_ar;
	int		sorted;

	if (ac >= 2)
	{
		data_ar = parser(av, ac);
		if (data_ar == NULL)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		sorted = ft_check_sorted(data_ar[0], *(data_ar[1]));
		if (sorted == 0)
			return (0);
		push_swap(&data_ar);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
