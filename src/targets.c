/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:55:24 by obouayed          #+#    #+#             */
/*   Updated: 2024/05/24 23:49:51 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_lowertarget(t_stack **a, t_stack **b)
{
	int	target_nbr;
	int	target_index;

	target_nbr = INT_MIN;
	target_index = -1;
	go_to_first(b);
	while (*b)
	{
		if ((*b)->nbr < (*a)->nbr && (*b)->nbr >= target_nbr)
		{
			target_nbr = (*b)->nbr;
			target_index = (*b)->index;
		}
		if ((*b)->next)
			*b = (*b)->next;
		else
			break ;
	}
	if (target_index == -1)
		find_maxnbr(b, &target_index, &target_nbr);
	go_to_first(b);
	(*a)->target_index = target_index;
	(*a)->target_nbr = target_nbr;
}

void	find_biggertarget(t_stack **a, t_stack **b)
{
	int	target_nbr;
	int	target_index;

	target_nbr = INT_MAX;
	target_index = -1;
	go_to_first(a);
	while (*a)
	{
		if ((*a)->nbr > (*b)->nbr && (*a)->nbr <= target_nbr)
		{
			target_nbr = (*a)->nbr;
			target_index = (*a)->index;
		}
		if ((*a)->next)
			*a = (*a)->next;
		else
			break ;
	}
	if (target_index == -1)
		find_minnbr(a, &target_index, &target_nbr);
	go_to_first(a);
	(*b)->target_index = target_index;
	(*b)->target_nbr = target_nbr;
}

void	find_maxnbr(t_stack **b, int *target_index, int *target_nbr)
{
	go_to_first(b);
	while (*b)
	{
		if (*target_nbr < (*b)->nbr)
		{
			*target_nbr = (*b)->nbr;
			*target_index = (*b)->index;
		}
		if ((*b)->next)
			*b = (*b)->next;
		else
			break ;
	}
}

void	find_minnbr(t_stack **a, int *target_index, int *target_nbr)
{
	go_to_first(a);
	while (*a)
	{
		if (*target_nbr > (*a)->nbr)
		{
			*target_nbr = (*a)->nbr;
			*target_index = (*a)->index;
		}
		if ((*a)->next)
			*a = (*a)->next;
		else
			break ;
	}
}
