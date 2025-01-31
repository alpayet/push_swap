/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:27:48 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/31 02:10:26 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_tab(int dist_in_a, int dist_in_b, int rr_rrr_or_not, int *tab)
{
	tab[0] = ft_abs(dist_in_a) + ft_abs(dist_in_b) + 1;
	tab[1] = dist_in_a;
	tab[2] = dist_in_b;
	tab[3] = rr_rrr_or_not;
}

static void	initialise_data(t_data *data, t_stack *stack_a, t_stack *stack_b,
		int nbr)
{
	data->index_nbr = find_index(stack_b, nbr);
	data->index_successor = find_index(stack_a, imediate_successor(stack_a,
				nbr));
	data->dist_nbr = distance_to_head(stack_b, data->index_nbr);
	data->dist_successor = distance_to_head(stack_a, data->index_successor);
	if (ft_abs(data->dist_nbr) <= ft_abs(data->dist_successor))
		data->dist_after_rules = distance_to_head(stack_a, data->index_successor
				+ data->dist_nbr);
	else
		data->dist_after_rules = distance_to_head(stack_b, data->index_nbr
				+ data->dist_successor);
}

static void	same_rules_to_head(int dist_successor, int dist_nbr, int *tab)
{
	if (dist_successor == 0 || dist_nbr == 0)
		return (fill_tab(dist_successor, dist_nbr, 0, tab));
	if (dist_nbr < 0)
	{
		if (dist_successor < dist_nbr)
			return (fill_tab(dist_successor - dist_nbr, dist_nbr, 1, tab));
		return (fill_tab(dist_successor, dist_nbr - dist_successor, -1, tab));
	}
	if (dist_successor < dist_nbr)
		return (fill_tab(dist_successor, dist_nbr - dist_successor, -1, tab));
	return (fill_tab(dist_successor - dist_nbr, dist_nbr, 1, tab));
}

static void	rules_params(t_stack *stack_a, t_stack *stack_b, int nbr, int *tab)
{
	t_data	data;

	initialise_data(&data, stack_a, stack_b, nbr);
	if (data.dist_successor * data.dist_nbr >= 0)
		return (same_rules_to_head(data.dist_successor, data.dist_nbr, tab));
	if (ft_abs(data.dist_nbr) <= ft_abs(data.dist_successor))
	{
		if (ft_abs(data.dist_successor) < ft_abs(data.dist_after_rules))
			return (fill_tab(data.dist_successor, data.dist_nbr, 0, tab));
		if (ft_abs(data.dist_successor) >= ft_abs(data.dist_after_rules))
			return (fill_tab(data.dist_after_rules, data.dist_nbr, 1, tab));
	}
	else
	{
		if (ft_abs(data.dist_nbr) < ft_abs(data.dist_after_rules))
			return (fill_tab(data.dist_successor, data.dist_nbr, 0, tab));
		if (ft_abs(data.dist_nbr) >= ft_abs(data.dist_after_rules))
			return (fill_tab(data.dist_successor, data.dist_after_rules, -1,
					tab));
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		buff[5];
	int		list_of_rules[5];

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	buff[0] = INT_MAX;
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
