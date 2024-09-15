/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:42:51 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/22 20:51:41 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	while_verif(char **list, int i, int j, int h)
{
	while (list[i][j])
	{
		if ((list[i][j] < '0' || list[i][j] > '9') && list[i][j] != '-'
			&& list[i][j] != '+')
			return (1);
		j++;
	}
	if (ft_longcmp(ft_atoi(list[h]), ft_atoi(list[i])) == 0 && i != h)
		return (1);
	return (0);
}

int	verif_error(char **list)
{
	int	i;
	int	j;
	int	h;

	h = 1;
	while (list[h])
	{
		i = 1;
		while (list[i])
		{
			j = 0;
			if (while_verif(list, i, j, h))
				return (1);
			i++;
		}
		h++;
	}
	if (ft_atoi(list[1]) > INT_MAX || ft_atoi(list[1]) < INT_MIN)
		return (1);
	return (0);
}

int	verif_error_checker(char **list, int i, int h)
{
	if (verif_error(list))
		return (1);
	if (list[i] == NULL)
		return (1);
	if (ft_longcmp(ft_atoi(list[i]), INT_MAX) == 0
		|| ft_longcmp(ft_atoi(list[h]), INT_MIN) == 0)
		return (1);
	return (0);
}
