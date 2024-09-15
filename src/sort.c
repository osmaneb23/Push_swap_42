/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:42:02 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/09 06:05:10 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *a)
{
	int	i;

	i = a->nbr;
	while (a && a->next)
	{
		a = a->next;
		if (i > a->nbr)
			return (0);
		i = a->nbr;
	}
	return (1);
}

void	ft_easysort(t_stack **a, int nbr)
{
	if (nbr == 1)
		return ;
	go_to_first(a);
	if (nbr == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a, 1);
	}
	if (nbr == 3)
	{
		if ((*a)->next->nbr > (*a)->next->next->nbr
			&& (*a)->next->nbr > (*a)->nbr)
			ft_rra(a, 1);
		go_to_first(a);
		if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
			ft_ra(a, 1);
		go_to_first(a);
		if ((*a)->nbr > (*a)->next->nbr)
			ft_sa(a, 1);
	}
}

void	final_sort(t_stack **a, t_stack **b)
{
	int	median_a;

	median_a = 0;
	while (*b)
	{
		find_biggertarget(a, b);
		find_median(*a, &median_a);
		while (find_index(*a, (*b)->target_nbr) != 1)
		{
			if ((*b)->target_index <= median_a)
				ft_ra(a, 1);
			else
				ft_rra(a, 1);
		}
		go_to_first(a);
		go_to_first(b);
		ft_pa(a, b, 1);
	}
	while (!check_sort(*a))
	{
		if (find_index_smaller(*a) <= len_stack(*a) / 2)
			ft_ra(a, 1);
		else
			ft_rra(a, 1);
	}
}

int	find_cheapest(t_stack **a)
{
	int	cheapest_cost_total;
	int	cheapest_index;

	cheapest_cost_total = INT_MAX;
	cheapest_index = -1;
	update_cost(a);
	while (*a)
	{
		if (cheapest_cost_total > ((*a)->cost + (*a)->target_cost))
		{
			cheapest_cost_total = ((*a)->cost + (*a)->target_cost);
			cheapest_index = (*a)->index;
		}
		if ((*a)->next != NULL)
			*a = (*a)->next;
		else
			break ;
	}
	return (cheapest_index);
}

void	pushswap(t_stack **a, t_stack **b)
{
	while (len_stack(*a) > 3 && len_stack(*b) != 2)
		ft_pb(a, b, 1);
	while (len_stack(*a) > 3)
	{
		while (*a)
		{
			find_lowertarget(a, b);
			find_median_and_assign_cost(a, b);
			if ((*a)->next != NULL)
				*a = (*a)->next;
			else
				break ;
		}
		double_rotates(a, b);
	}
	ft_easysort(a, 3);
	final_sort(a, b);
}
