/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 05:20:31 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/07 11:08:16 by mel-houd         ###   ########.fr       */
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

int		ft_check_intruder(char *str)
{
	int	i = 0;
	
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) != 0)
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

char	*ft_parser(char **av, int ac)
{
	int		i;
	int		sw = 0;
	char 	*full_args;

	i = 1;
	full_args = NULL;
	while (i < ac)
	{
		if (sw == 1)
			full_args = ft_strjoin(full_args, " ");
		sw = 1;
		full_args = ft_strjoin(full_args, av[i]);
		i++;
	}
	if (ft_check_intruder(full_args) == 1)
	{
		free(full_args);
		return (NULL);
	}
	return (full_args);
}

int		**ft_convert_av(char *full_args)
{
	int		size;
	int		**res;
	int		*data;
	int		i;
	char	**splited;

	splited = ft_split(full_args, ' ');
	if (!splited)
		return (NULL);
	size = 0;
	while (splited[size])
		size++;
	res = (int **)malloc(sizeof(int *) * 3);
	data = (int *)malloc(sizeof(int) * size);
	if (!res || !data)
	{
		free(full_args);
		ft_free_2d(splited);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		data[i] = ft_atoi(splited[i]);
		i++;
	}
	res[0] = data;
	res[1] = &size;
	res[2] = NULL;
	free(full_args);
	ft_free_2d(splited);
	return (res);
}

int		ft_check_dups(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
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
