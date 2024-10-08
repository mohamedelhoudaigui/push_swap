/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:16:54 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/15 06:46:09 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
	split = NULL;
}

void	*check_atoi(char *str, char **split, int **res)
{
	long	num;

	num = ft_atoi(str);
	if (num > INT32_MAX || num < INT32_MIN)
	{
		free_split(split);
		free_res(res);
		return (NULL);
	}
	return ((void *)1);
}

int	moded_ft_strlen(char *str)
{
	int	i;
	int	j;

	if (str[0] == '0' && str[1] == '\0')
		return (1);
	i = 0;
	while (str[i] == '0')
		i++;
	j = 0;
	while (str[i])
	{
		j++;
		i++;
	}
	return (j);
}

t_node	*get_biggest(t_stack *stack)
{
	t_node	*t_list;
	t_node	*biggest_node;
	int		biggest;

	biggest_node = NULL;
	t_list = stack->items;
	biggest = INT32_MIN;
	while (t_list)
	{
		if (t_list->value > biggest)
		{
			biggest_node = t_list;
			biggest = biggest_node->value;
		}
		t_list = t_list->next;
	}
	return (biggest_node);
}

t_node	*get_smallest(t_stack *stack)
{
	t_node	*stack_list;
	int		small;
	t_node	*small_node;

	stack_list = stack->items;
	small = INT32_MAX;
	while (stack_list)
	{
		if (stack_list->value < small)
		{
			small = stack_list->value;
			small_node = stack_list;
		}
		stack_list = stack_list->next;
	}
	return (small_node);
}
