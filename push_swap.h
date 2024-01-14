/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:24:12 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/12 02:47:30 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			cheap;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*items;
	int		size;
	int		top;
}				t_stack;

int		*make_array(t_stack *head);
int		*find_3_largest(int *arr, int size);
int		check_exist(int *big_3, int value);
void	init_stacks(t_stack *a, t_stack *b, int size, int *data);
void	free_stack(t_stack *stack);
t_node	*t_node_new(int value);
t_node	*t_node_last(t_node *lst);
void	t_node_add_back(t_node **lst, t_node *new);
void	t_node_add_front(t_node **lst, t_node *new);
void	sort_stack(t_stack *a, t_stack *b);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	init_turk(t_stack *a, t_stack *b, int *big_3);
void	clear_target(t_stack *a, t_stack *b);
void	turk_algo(t_stack *a, t_stack *b);
void	calculate_target(t_stack **a_p, t_stack **b_p, int *big_3);
void	index_cost(t_stack **a_p, t_stack **b_p);
void	calculate_cost_action(t_stack **a_p, t_stack **b_p, int *big_3);
void	movement_of_nodes(t_stack *a, t_stack *b);
void	algo_in(t_stack *a, t_stack *b, int *big_3);
void	finish_touch_in(t_stack *b);
int		*get_big_3(t_stack *a);
void	bubble_sort(int *arr, int n);
void	swap(int *xp, int *yp);
t_node	*get_smallest(t_stack *stack);
t_node	*get_biggest(t_stack *stack);
t_node	*check_no_target(t_stack *a, int *big_3);
int		*find_min(t_node *head);
void	push_min(t_stack *a, t_stack *b);
void	print_stack(t_stack *stack);
char	*ft_parser(char **av, int ac);
int		ft_check_intruder(char *str);
void	push_swap(int ***data_ar);
int		**ft_convert_av(char *full_args);
void	ft_free_2d(char **av);
int		ft_check_dups(int *data, int size);
int		ft_check_sorted(int	*data, int size);
int		get_size(char **splited);
int		**allocate_memory(int size);
int		fill_data(char **splited, int *data, int size);
void	move_a(t_stack *a, t_node *cheap_node);
void	move_b(t_stack *a, t_stack *b, t_node *cheap_node, t_node *target);
t_node	*get_cheap_node(t_stack *a);
int		check_digits(char *arg);
int		moded_ft_strlen(char *str);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

void	p_rb(t_stack *b);
void	p_ra(t_stack *a);
void	p_rrb(t_stack *b);
void	p_rra(t_stack *a);

#endif