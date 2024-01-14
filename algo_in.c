/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 04:56:27 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/12 00:57:38 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_in(t_stack *a, t_stack *b, int *big_3)
{
	while (a->size > 3)
	{
		index_cost(&a, &b);
		calculate_target(&a, &b, big_3);
		calculate_cost_action(&a, &b, big_3);
		movement_of_nodes(a, b);
		clear_target(a, b);
	}
}
