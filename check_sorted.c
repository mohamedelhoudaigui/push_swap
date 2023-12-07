/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:54 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/07 13:18:16 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sorted(int	*data, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (data[i] > data[i + 1])
			return (1);
		i++;
	}
	return (0);
}
