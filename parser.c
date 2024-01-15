/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:20:31 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/15 06:14:46 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_intruder(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (1);
			if (i != 0 && str[i - 1] != 32)
				return (1);
		}
		if (str[i] != 32 && str[i] != '+' && str[i] != '-')
		{
			if (str[i] < '0' || str[i] > '9')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_number(av[i]) == 1 || check_intruder(av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	check_multi(int **args)
{
	int	i;
	int	num;
	int	j;

	i = -1;
	while (++i < *args[1])
	{
		num = args[0][i];
		j = -1;
		while (++j < *args[1])
		{
			if (j == i)
				j++;
			if (j == *args[1])
				break ;
			if (num == args[0][j])
			{
				return (1);
			}
		}
	}
	return (0);
}

int	**parser(char **av)
{
	int	len;
	int	**data_ar;

	if (check_args(av) == 1)
		return (NULL);
	len = check_len(av);
	if (len == 0)
		return (NULL);
	data_ar = get_data(av, len);
	if (data_ar == NULL)
		return (NULL);
	if (check_multi(data_ar) == 1)
	{
		free_res(data_ar);
		return (NULL);
	}
	return (data_ar);
}
