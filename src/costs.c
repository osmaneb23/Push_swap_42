/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:29:12 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/22 20:10:20 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_cost(t_stack **a)
{
	go_to_first(a);
	while (*a)
	{
		(*a)->lostcost = 0;
		if ((*a)->cost > 0 && (*a)->target_cost > 0)
		{
			if (((*a)->above_median == 1 && (*a)->target_above_median == 1)
				|| ((*a)->above_median == 0 && (*a)->target_above_median == 0))
			{
				if ((*a)->cost >= (*a)->target_cost)
				{
					(*a)->cost -= (*a)->target_cost;
					(*a)->lostcost = 1;
				}
				else
					(*a)->target_cost -= (*a)->cost;
			}
		}
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			break ;
	}
	go_to_first(a);
}

void	find_median(t_stack *node, int *median_node)
{
	if (len_stack(node) % 2)
		*median_node = ((len_stack(node) / 2) + 1);
	else
		*median_node = (len_stack(node) / 2);
}

void	find_median_and_assign_cost(t_stack **a, t_stack **b)
{
	int	median_a;
	int	median_b;

	(*a)->above_median = 0;
	(*a)->target_above_median = 0;
	find_median(*a, &median_a);
	if ((*a)->index <= median_a)
	{
		(*a)->above_median = 1;
		(*a)->cost = (*a)->index - 1;
	}
	else
		(*a)->cost = len_stack(*a) - (*a)->index + 1;
	find_median(*b, &median_b);
	return_to_index(b, (*a)->target_index);
	if ((*b)->index <= median_b)
	{
		(*a)->target_above_median = 1;
		(*a)->target_cost = (*b)->index - 1;
	}
	else
		(*a)->target_cost = len_stack(*b) - (*b)->index + 1;
}
