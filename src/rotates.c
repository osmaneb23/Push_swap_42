/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:53:21 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/22 20:09:14 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_rotates_and_push(t_stack **a, t_stack **b)
{
	while ((*a)->cost != 0)
	{
		if ((*a)->above_median)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
		(*a)->cost--;
	}
	while ((*a)->target_cost != 0)
	{
		if ((*a)->target_above_median)
			ft_rb(b, 1);
		else
			ft_rrb(b, 1);
		(*a)->target_cost--;
	}
	go_to_first(a);
	go_to_first(b);
	ft_pb(a, b, 1);
}

void	double_rotates(t_stack **a, t_stack **b)
{
	int	i;
	int	j;

	return_to_index(a, find_cheapest(a));
	i = (*a)->nbr;
	j = (*a)->target_nbr;
	while (find_index(*a, i) != 1 && find_index(*b, j) != 1)
	{
		if (((*a)->above_median && (*a)->target_above_median == 0)
			|| ((*a)->above_median == 0 && (*a)->target_above_median))
			break ;
		if ((*a)->above_median && (*a)->target_above_median)
			ft_rr(a, b, 1);
		if ((*a)->above_median == 0 && (*a)->target_above_median == 0)
			ft_rrr(a, b, 1);
		if ((*a)->lostcost)
			(*a)->target_cost--;
		else
			(*a)->cost--;
	}
	simple_rotates_and_push(a, b);
}
