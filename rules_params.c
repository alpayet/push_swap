/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:27:48 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 22:36:58 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_to_head(t_stack *stack, int index_nbr)
{
	int	index_last;

	if (index_nbr <= 0)
		return (0);
	index_last = stack_size(stack) - 1;
	if (index_nbr >= index_last)
		return (1);
	if (index_nbr < (float)index_last / 2 + 1)
		return (-index_nbr);
	return (index_last - index_nbr + 1);
}

static void fill_tab(int dist_nbr, int dist_successor, int rr_rrr_or_not, long *tab)
{
	tab[0] = ft_abs(dist_nbr) + ft_abs(dist_successor) + 1;
	tab[1] = dist_nbr;
	tab[2] = dist_successor;
	tab[3] = rr_rrr_or_not;
}

static void same_rules_to_head(int dist_nbr, int dist_successor, long *tab)
{
	if (dist_nbr == 0 || dist_successor == 0)
		return(fill_tab(dist_nbr, dist_successor, 0, tab));
	if (dist_nbr < 0)
	{
		if (dist_nbr < dist_successor)
			return(fill_tab(dist_nbr - dist_successor, dist_successor, -1, tab));
		return(fill_tab(dist_nbr, dist_successor - dist_nbr, 1, tab));
	}
	if (dist_nbr < dist_successor)
		return(fill_tab(dist_nbr, dist_successor - dist_nbr, 1, tab));
	return(fill_tab(dist_nbr - dist_successor, dist_successor, -1, tab));
}

static void rules_params(t_stack *stack_a, t_stack *stack_b, int nbr, long *tab)
{
	int	index_nbr;
	int	index_successor;
	int	dist_nbr;
	int	dist_successor;
	int	dist_after_rules;

	index_nbr = find_index(stack_b, nbr);
	index_successor = find_index(stack_a, imediate_successor(stack_a, nbr));
	dist_nbr = distance_to_head(stack_b, index_nbr);
	dist_successor = distance_to_head(stack_a, index_successor);
	dist_after_rules = distance_to_head(stack_a, index_successor + dist_nbr);
	if (dist_nbr * dist_successor >= 0)
		return(same_rules_to_head(dist_nbr, dist_successor, tab));
	if (dist_nbr < 0 && ft_abs(dist_successor) < ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_successor, 0, tab));
	if (dist_nbr < 0 && ft_abs(dist_successor) >= ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_after_rules, 1, tab));
	if (dist_nbr > 0 && ft_abs(dist_successor) < ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_successor, 0, tab));
	return(fill_tab(dist_nbr, dist_after_rules, 1, tab));
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	long	buff[5];
	long	list_of_rules[5];

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	buff[0] = __LONG_MAX__;
	while (temp)
	{
		rules_params(*stack_a, *stack_b, temp->number, list_of_rules);
		if (list_of_rules[0] < buff[0])
		{
			buff[0] = list_of_rules[0];
			buff[1] = list_of_rules[1];
			buff[2] = list_of_rules[2];
			buff[3] = list_of_rules[3];
		}
		temp = temp->next;
	}
	execute_rules(stack_a, stack_b, buff);
	push_back_to_a(stack_a, stack_b);
}
