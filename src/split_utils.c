/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 18:09:40 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/07 18:09:40 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkstr(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_lenwords(char *str, char *charset)
{
	int	i;
	int	compteur;
	int	word;

	i = 0;
	compteur = 0;
	word = 0;
	while (str[i])
	{
		if (!checkstr(charset, str[i]))
		{
			if (!word)
			{
				compteur++;
				word = 1;
			}
		}
		else
		{
			word = 0;
		}
		i++;
	}
	return (compteur);
}

int	ft_sizeword(char *str, char *charset, int k)
{
	int	size;

	size = 0;
	while (str[k] && !checkstr(charset, str[k]))
	{
		size++;
		k++;
	}
	return (size);
}
