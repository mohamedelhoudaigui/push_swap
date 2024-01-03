/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-houd <mel-houd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:23:59 by mel-houd          #+#    #+#             */
/*   Updated: 2024/01/03 08:27:18 by mel-houd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*t_node_new(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*t_node_last(t_node *lst)
{
	t_node	*p;

	if (!lst)
		return (NULL);
	p = lst;
	while (p->next != NULL)
		p = p->next;
	return (p);
}

void t_node_add_back(t_node **lst, t_node *new)
{
    t_node *tmp;

    if (lst && new)
    {
        if (*lst == NULL)
        {
            *lst = new;
			new->next = NULL;
            new->prev = NULL; // Set prev to NULL for the first node
        }
        else
        {
            tmp = t_node_last(*lst);
            tmp->next = new;
            new->prev = tmp; // Set the previous node for the new node
        }
    }
}

void	print_t_node(t_node *list)
{
	if (!list)
		return ;
	while (list)
	{
		ft_printf("%d", list->value);
		list = list->next;
	}
}

void	t_node_add_front(t_node **lst, t_node *new)
{
	t_node	*lst_p;

	if (lst == NULL)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		lst_p = *lst;
		new->next = lst_p;
		lst_p->prev = new;
		*lst = new;
	}
}
