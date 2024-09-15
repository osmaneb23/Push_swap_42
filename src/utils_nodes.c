/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:04:08 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/07 17:13:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_to_first(t_stack **node)
{
	if (!*node)
		return ;
	while ((*node)->prev != NULL)
		(*node) = (*node)->prev;
}

t_stack	*last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}

void	ft_updatenode(t_stack **stack)
{
	int	i;

	i = 1;
	go_to_first(stack);
	if ((*stack)->next)
	{
		while ((*stack)->next)
		{
			(*stack)->index = i;
			i++;
			(*stack) = (*stack)->next;
		}
		if ((*stack))
			(*stack)->index = i;
	}
	go_to_first(stack);
}
