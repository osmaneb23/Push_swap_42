/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:18:10 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/08 20:32:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, int print)
{
	int	temp;
	int	index;

	if (!*a)
		return ;
	index = (*a)->index;
	go_to_first(a);
	if (!(*a)->next)
		return ;
	temp = (*a)->nbr;
	(*a)->nbr = (*a)->next->nbr;
	(*a)->next->nbr = temp;
	if (print)
		ft_putstr("sa\n");
	return_to_index(a, index);
}

void	ft_sb(t_stack **b, int print)
{
	int	temp;
	int	index;

	if (!*b)
		return ;
	index = (*b)->index;
	go_to_first(b);
	if (!(*b)->next)
		return ;
	temp = (*b)->nbr;
	(*b)->nbr = (*b)->next->nbr;
	(*b)->next->nbr = temp;
	if (print)
		ft_putstr("sb\n");
	return_to_index(b, index);
}

void	ft_pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*node;

	if (!*b)
		return ;
	node = (*b);
	if ((*b)->next)
	{
		(*b) = (*b)->next;
		(*b)->prev = NULL;
		ft_updatenode(b);
	}
	else
		(*b) = NULL;
	node->next = (*a);
	(*a)->prev = node;
	(*a) = (*a)->prev;
	ft_updatenode(a);
	if (print)
		ft_putstr("pa\n");
}

void	ft_pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*node;

	if (!*a)
		return ;
	node = (*a);
	(*a) = (*a)->next;
	(*a)->prev = NULL;
	ft_updatenode(a);
	if (!*b)
	{
		(*b) = node;
		(*b)->next = NULL;
	}
	else
	{
		node->next = (*b);
		(*b)->prev = node;
		(*b) = (*b)->prev;
		ft_updatenode(b);
	}
	if (print)
		ft_putstr("pb\n");
}
