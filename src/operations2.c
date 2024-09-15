/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:18:24 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/05 14:54:03 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, int print)
{
	t_stack	*node;
	int		temp;
	int		index;

	if (!*a)
		return ;
	index = (*a)->index;
	go_to_first(a);
	if (!(*a)->next)
		return ;
	node = (*a);
	while (node->next)
	{
		temp = node->nbr;
		node->nbr = node->next->nbr;
		node->next->nbr = temp;
		node = node->next;
	}
	if (print)
		ft_putstr("ra\n");
	return_to_index(a, index);
}

void	ft_rb(t_stack **b, int print)
{
	t_stack	*node;
	int		temp;
	int		index;

	if (!*b)
		return ;
	index = (*b)->index;
	go_to_first(b);
	if (!(*b)->next)
		return ;
	node = (*b);
	while (node->next)
	{
		temp = node->nbr;
		node->nbr = node->next->nbr;
		node->next->nbr = temp;
		node = node->next;
	}
	if (print)
		ft_putstr("rb\n");
	return_to_index(b, index);
}

void	ft_rra(t_stack **a, int print)
{
	t_stack	*last;
	int		temp;
	int		index;

	if (!*a)
		return ;
	index = (*a)->index;
	go_to_first(a);
	if (!(*a)->next)
		return ;
	last = last_node(*a);
	while (last->prev)
	{
		temp = last->nbr;
		last->nbr = last->prev->nbr;
		last->prev->nbr = temp;
		last = last->prev;
	}
	if (print)
		ft_putstr("rra\n");
	return_to_index(a, index);
}

void	ft_rrb(t_stack **b, int print)
{
	t_stack	*last;
	int		temp;
	int		index;

	if (!b)
		return ;
	index = (*b)->index;
	go_to_first(b);
	if (!(*b)->next)
		return ;
	last = last_node(*b);
	while (last->prev)
	{
		temp = last->nbr;
		last->nbr = last->prev->nbr;
		last->prev->nbr = temp;
		last = last->prev;
	}
	if (print)
		ft_putstr("rrb\n");
	return_to_index(b, index);
}
