/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:20:31 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/06 07:40:22 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_2d(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

int	ft_check_intruder(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i]
			!= '-' && str[i] != '+')
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i + 1] < '0' || str[i + 1] > '9')
				return (1);
		}
		i++;
	}
	i = 0;
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*concatenate_arguments(char **av, int ac)
{
	int		i;
	char	*full_args;
	char	*tmp;

	i = 1;
	full_args = NULL;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			return (NULL);
		tmp = full_args;
		full_args = ft_strjoin(tmp, av[i]);
		free(tmp);
		if (i < ac - 1)
		{
			tmp = full_args;
			full_args = ft_strjoin(tmp, " ");
			free(tmp);
		}
		i++;
	}
	return (full_args);
}

char	*ft_parser(char **av, int ac)
{
	char	*full_args;

	full_args = concatenate_arguments(av, ac);
	if (full_args == NULL || ft_check_intruder(full_args) == 1)
	{
		free(full_args);
		return (NULL);
	}
	return (full_args);
}

int	ft_check_dups(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
