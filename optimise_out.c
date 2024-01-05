/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:36:09 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/05 04:42:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *make_array(t_stack *head)
{
    t_node      *list_stack;
        int             i;
        int             *arr;

        i = 0;
        list_stack = head->items;
        arr = (int *)ft_calloc(head->size, sizeof(int));
        while (i < head->size)
        {
                arr[i] = list_stack->value;
                i++;
                list_stack = list_stack->next;
        }
        return (arr);
}

int     *find_5_largest(int arr[], int size)
{
   int  *result;

   result = (int *)malloc(sizeof(int) * 5);
   if (!result)
        return (NULL);
    for (int i = 0; i < 5; i++)
        result[i] = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i] > result[j])
            {
                for (int k = 4; k > j; k--)
                    result[k] = result[k - 1];
                result[j] = arr[i];
                break;
            }
        }
    }
        return (result);
}

int     check_exist(int *big_5, int value)
{
    int     i;

    i = 0;
	while (i < 5)
	{
		if (big_5[i] == value)
			return (1);
		i++;
	}
	return (0);
}

void swap(int *xp, int *yp)
{
	int temp;

    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[], int n)
{
    int swapped;
	int	i;

	swapped = 1;
    while (swapped)
	{
        swapped = 0;
		i = 0;
        while (i < n - 1)
		{
            if (arr[i] > arr[i + 1])
			{
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
			i++;
        }
    }
}

int median(int arr[], int n)
{
    if (n % 2 == 0)
        return arr[n / 2 - 1];
    return arr[n / 2];
}
