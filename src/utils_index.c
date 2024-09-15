/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 23:07:40 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/07 17:11:36 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *node)
{
	if (!node)
		return (0);
	return (last_node(node)->index);
}

void	return_to_index(t_stack **node, int index)
{
	if (!*node)
		return ;
	go_to_first(node);
	while ((*node)->index != index)
		(*node) = (*node)->next;
}

int	find_index(t_stack *node, int nbr)
{
	if (!node)
		return (-1);
	go_to_first(&node);
	while ((node) && (node)->nbr != nbr)
		(node) = (node)->next;
	return (node->index);
}

int	find_index_smaller(t_stack *node)
{
	if (!node)
		return (-1);
	go_to_first(&node);
	while ((node) && (node)->nbr < (node)->next->nbr)
		(node) = (node)->next;
	return (node->index);
}
