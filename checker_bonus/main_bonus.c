/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 06:53:13 by obouayed          #+#    #+#             */
/*   Updated: 2024/06/08 06:53:13 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	verification_and_initialisation(t_stack **a, char **av, int ac)
{
	if (av == NULL || verif_error_checker(av, 1, 1))
	{
		print_error();
		exit(1);
	}
	ft_create_stack(a, av, ac);
}

void	error(t_stack **a, t_stack **b, char *line)
{
	ft_putstr("Error\n");
	if (line)
		free(line);
	free_stack(a);
	free_stack(b);
	exit(1);
}

void	last_check_and_free(t_stack **a, t_stack **b, char *line)
{
	if (check_sort(*a) && !*b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	if (line)
		free(line);
	free_stack(a);
	free_stack(b);
}

void	command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "pb\n") == 0)
		ft_pb(a, b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_pa(a, b, 0);
	else if (ft_strcmp(line, "sa\n") == 0)
		ft_sa(a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb(b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss(a, b, 0);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra(a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb(b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr(a, b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra(a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rrb(b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr(a, b, 0);
	else
		error(a, b, line);
}

int	main(int ac, char**av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	b = NULL;
	if (ac == 1)
		return (0);
	verification_and_initialisation(&a, av, ac);
	line = get_next_line(STDIN_FILENO);
	if (!line && !(check_sort(a)))
		error(&a, &b, line);
	if (!line && check_sort(a))
	{
		last_check_and_free(&a, &b, line);
		return (0);
	}
	while (line)
	{
		command(line, &a, &b);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	last_check_and_free(&a, &b, line);
	return (0);
}
