/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: obouayed <obouayed@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/03/26 16:18:59 by obouayed          #+#    #+#             */
/*   Updated: 2024/03/26 16:18:59 by obouayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				target_nbr;
	int				cost;
	int				target_cost;
	int				index;
	int				target_index;
	int				above_median;
	int				target_above_median;
	int				lostcost;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

int		verif_error(char **list);
long	ft_atoi(const char *nptr);
long	ft_longcmp(long s1, long s2);
void	print_error(void);
void	ft_create_stack(t_stack **a, char **list, int ac);
void	ft_init_node(t_stack **node, char **list, int i);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	ft_updatenode(t_stack **stack);
void	ft_putstr(char *str);
t_stack	*last_node(t_stack *node);
void	ft_easysort(t_stack **a, int nbr);
void	pushswap(t_stack **a, t_stack **b);
int		check_sort(t_stack *a);
int		len_stack(t_stack *a);
void	go_to_first(t_stack **node);
void	return_to_index(t_stack **node, int index);
void	find_maxnbr(t_stack **b, int *target_index, int *target_nbr);
int		find_index(t_stack *node, int nbr);
void	simple_rotates_and_push(t_stack **a, t_stack **b);
void	double_rotates(t_stack **a, t_stack **b);
int		find_cheapest(t_stack **a);
void	update_cost(t_stack **a);
void	find_lowertarget(t_stack **a, t_stack **b);
void	find_median_and_assign_cost(t_stack **a, t_stack **b);
void	find_biggertarget(t_stack **a, t_stack **b);
void	find_minnbr(t_stack **b, int *target_index, int *target_nbr);
void	find_median(t_stack *node, int *median_node);
int		find_index_smaller(t_stack *node);
char	**ft_split(char *str, char *charset, char **av);
int		ft_lenwords(char *str, char *charset);
int		checkstr(char *sep, char c);
int		checkstr(char *sep, char c);
int		ft_sizeword(char *str, char *charset, int k);
int		ft_lenwords(char *str, char *charset);
void	free_stack(t_stack **a);
void	free_av(char **av);
int		ft_strcmp(const char*s1, const char *s2);
int		verif_error_checker(char **list, int i, int h);

#endif