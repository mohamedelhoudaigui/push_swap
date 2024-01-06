/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:02:55 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 17:42:39 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(char **splited)
{
	int	size;

	size = 0;
	while (splited[size])
		size++;
	return (size);
}

int	**allocate_memory(int size)
{
	int	**res;
	int	*data;

	res = (int **)malloc(sizeof(int *) * 3);
	data = (int *)malloc(sizeof(int) * size);
	if (!res || !data)
		return (NULL);
	res[0] = data;
	return (res);
}

void	fill_data(char **splited, int *data, int size)
{
	int			i;
	long long	tmp;

	i = 0;
	while (i < size)
	{
		tmp = ft_atol(splited[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			return ;
		data[i] = (int)tmp;
		i++;
	}
}

int	**ft_convert_av(char *full_args)
{
	char	**splited;
	int		size;
	int		**res;

	splited = ft_split(full_args, ' ');
	if (!splited)
		return (NULL);
	size = get_size(splited);
	res = allocate_memory(size);
	if (!res)
	{
		free(full_args);
		ft_free_2d(splited);
		return (NULL);
	}
	fill_data(splited, res[0], size);
	res[1] = &size;
	res[2] = NULL;
	free(full_args);
	ft_free_2d(splited);
	return (res);
}
