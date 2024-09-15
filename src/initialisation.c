/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/25 11:33:02 by obouayed          #+#    #+#             */
/*   Updated: 2024/05/12 14:28:02 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_init(t_stack**a)
{
	t_stack	*current;
	t_stack	*next_node;

	print_error();
	current = *a;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*a = NULL;
}

void	ft_init_node(t_stack **node, char **list, int i)
{
	(*node)->nbr = ft_atoi(list[i]);
	(*node)->target_nbr = -1;
	(*node)->index = i;
	(*node)->next = NULL;
	(*node)->prev = NULL;
	(*node)->target_index = -1;
	(*node)->cost = -1;
	(*node)->target_cost = -1;
	(*node)->above_median = 0;
	(*node)->target_above_median = 0;
	(*node)->lostcost = 0;
}

void	ft_create_stack(t_stack **a, char **list, int ac)
{
	int		i;
	t_stack	*node;
	t_stack	*last;

	i = 1;
	*a = NULL;
	while (i < ac)
	{
		node = malloc(sizeof(t_stack));
		if (!node)
		{
			error_init(a);
			return ;
		}
		ft_init_node(&node, list, (i++));
		last = last_node(*a);
		if (!*a)
			*a = node;
		else
		{
			last->next = node;
			node->prev = last;
		}
	}
}
