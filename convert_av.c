/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:02:55 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/15 06:19:47 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_len(char **av)
{
	int	i;
	int	j;
	int	res;

	i = -1;
	res = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == '-' || av[i][j] == '+'
				|| (av[i][j] >= '0' && av[i][j] <= '9'))
			{
				if (j == 0 || av[i][j - 1] == 32)
					res++;
			}
		}
	}
	return (res);
}

int	check_num_len(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (moded_ft_strlen(str[i]) > 12)
			return (1);
	}
	return (0);
}

int	check_len(char **av)
{
	char	**split_res;
	int		len;
	int		i;

	len = calculate_len(av);
	i = 0;
	while (av[++i])
	{
		split_res = ft_split(av[i], ' ');
		if (!split_res)
			return (0);
		if (check_num_len(split_res) == 1)
		{
			free_split(split_res);
			return (0);
		}
		free_split(split_res);
	}
	return (len);
}

int	**allocate_memory(int len)
{
	int	**res;

	res = ft_calloc(sizeof(int *), 3);
	if (res == NULL)
		return (NULL);
	res[0] = ft_calloc(sizeof(int), len);
	res[1] = ft_calloc(sizeof(int), 1);
	if (!res[0] || !res[1])
	{
		free(res[0]);
		free(res[1]);
		free(res);
		return (NULL);
	}
	*res[1] = len;
	return (res);
}

int	**get_data(char **av, int len)
{
	int		**res;
	char	**split;
	int		i;
	int		j;
	int		t;

	res = allocate_memory(len);
	if (res == NULL)
		return (NULL);
	i = 0;
	t = -1;
	while (av[++i])
	{
		split = ft_split(av[i], ' ');
		j = -1;
		while (split[++j])
		{
			if (check_atoi(split[j], split, res) == NULL)
				return (NULL);
			res[0][++t] = ft_atoi(split[j]);
		}
		free_split(split);
	}
	return (res);
}
