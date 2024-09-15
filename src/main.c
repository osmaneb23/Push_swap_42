/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/26 16:19:23 by obouayed          #+#    #+#             */
/*   Updated: 2024/05/12 15:00:51 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(int ac, char **av, t_stack **a, t_stack **b)
{
	*b = NULL;
	if (av == NULL || verif_error(av))
	{
		print_error();
		exit(1);
	}
	ft_create_stack(a, av, ac);
	if (!check_sort(*a))
	{
		if (ac <= 4)
			ft_easysort(a, (ac - 1));
		else
			pushswap(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	if (ac == 1)
		return (0);
	if (av[2] == NULL && ft_lenwords(av[1], " ") > 1)
	{
		ac = ft_lenwords(av[1], " ") + 1;
		av = ft_split(av[1], " ", av);
		i = 1;
		if (av == NULL || verif_error(av))
		{
			free_av(av);
			print_error();
			return (1);
		}
	}
	initialize_stacks(ac, av, &a, &b);
	free_stack(&a);
	free_stack(&b);
	if (i == 1)
		free_av(av);
	return (0);
}
