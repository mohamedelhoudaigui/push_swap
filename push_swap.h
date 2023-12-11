/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:24:12 by mel-houd          #+#    #+#             */
/*   Updated: 2023/12/10 04:22:10 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct
{
	int top;
	int *items;
}   stack;

void    print_stack(stack *stack);
void	sort(stack *a, stack *b);
void	sort_3(stack *a);
void	sort_45(stack *a, stack *b, int variation);
void	sort_array(int	*arr, int size);
int		get_index(int *table, int size, int value);
int		*find_min(int *data, int size);
char	*ft_parser(char **av, int ac);
int		ft_check_intruder(char *str);
void	push_swap(int *data, int size);
int		**ft_convert_av(char *full_args);
void	ft_free_2d(char **av);
int		ft_check_dups(int *data, int size);
int		ft_check_sorted(int	*data, int size);

void	sa(stack *a);
void	sb(stack *b);
void    ss(stack *a, stack *b);
void    pa(stack *a, stack *b);
void    pb(stack *a, stack *b);
void    ra(stack *a);
void    rb(stack *b);
void	rr(stack *a, stack *b);
void	rra(stack *a);
void	rrb(stack *b);
void	rrr(stack *a, stack *b);

#endif