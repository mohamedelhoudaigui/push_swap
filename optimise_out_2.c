/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_out_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:53:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/12 02:01:03 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_result(int *result)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		result[i++] = INT32_MIN;
	}
}

void	shift_result(int index, int *result)
{
	int	k;

	k = 2;
	while (k > index)
	{
		result[k] = result[k - 1];
		k--;
	}
}

void	update_result(int value, int *result)
{
	int	j;

	j = 0;
	while (j < 3)
	{
		if (value > result[j])
		{
			shift_result(j, result);
			result[j] = value;
			break ;
		}
		j++;
	}
}

int	*find_3_largest(int *arr, int size)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * 3);
	if (!result)
		return (NULL);
	initialize_result(result);
	i = 0;
	while (i < size)
	{
		update_result(arr[i], result);
		i++;
	}
	return (result);
}
