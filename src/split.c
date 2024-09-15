/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:55:47 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/22 20:09:24 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

char	*ft_strdup(char *src, char *charset, int *index)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_sizeword(src, charset, *index)
				+ 1));
	if (!str)
		return (NULL);
	while (src[*index] && !checkstr(charset, src[*index]))
	{
		str[i] = src[*index];
		i++;
		(*index)++;
	}
	str[i] = '\0';
	return (str);
}

void	free_split(char **tab, int i)
{
	while (i >= 1)
	{
		if (tab[i])
			free(tab[i]);
		i--;
	}
	free(tab);
}

char	**fill_tab(char *str, char *charset, char **tab, int *index)
{
	int	k;

	k = 0;
	while (str[k])
	{
		if (!checkstr(charset, str[k]))
		{
			tab[*index] = ft_strdup(str, charset, &k);
			if (!tab[*index])
			{
				free_split(tab, *index - 1);
				return (NULL);
			}
			else
				(*index)++;
		}
		else
			k++;
	}
	return (tab);
}

char	**ft_split(char *str, char *charset, char **av)
{
	char	**tab;
	int		i;

	if (!str || !charset || !av)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (ft_lenwords(str, charset) + 2));
	if (!tab)
		return (NULL);
	tab[0] = av[0];
	i = 1;
	tab = fill_tab(str, charset, tab, &i);
	if (!tab)
		return (NULL);
	tab[i] = NULL;
	return (tab);
}
