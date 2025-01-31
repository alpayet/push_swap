/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:18:23 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/31 20:44:05 by alpayet          ###   ########.fr       */
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

static void	sort_two_or_less(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		exit(0);
	if ((*stack_a)->next->next == NULL)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			swap(stack_a, stack_a, "sa\n", 1);
		exit(0);
	}
}

static void	quick_sort_alt(t_stack **stack_a, t_stack **stack_b)
{
	int	stacka_size;
	int	final_index_max;

	stacka_size = stack_size(*stack_a);
	final_index_max = stacka_size - 1;
	while (stacka_size && (*stack_a)->next->next->next != NULL)
	{
		if ((*stack_a)->final_index <= (float)final_index_max / 2)
			push(stack_a, stack_b, "pb\n", 1);
		else
			rotate(stack_a, stack_b, "ra\n", 1);
		stacka_size--;
	}
	while ((*stack_a)->next->next->next != NULL)
		push(stack_a, stack_b, "pb\n", 1);
}

static void	sort_three_element(t_stack **stack_a)
{
	if ((*stack_a)->number < (*stack_a)->next->next->number
		&& (*stack_a)->next->next->number < (*stack_a)->next->number)
	{
		swap(stack_a, stack_a, "sa\n", 1);
		rotate(stack_a, stack_a, "ra\n", 1);
	}
	if ((*stack_a)->next->number < (*stack_a)->number
		&& (*stack_a)->number < (*stack_a)->next->next->number)
		swap(stack_a, stack_a, "sa\n", 1);
	if ((*stack_a)->next->next->number < (*stack_a)->number
		&& (*stack_a)->number < (*stack_a)->next->number)
		reverse_rotate(stack_a, stack_a, "rra\n", 1);
	if ((*stack_a)->next->number < (*stack_a)->next->next->number
		&& (*stack_a)->next->next->number < (*stack_a)->number)
		rotate(stack_a, stack_a, "ra\n", 1);
	if ((*stack_a)->next->next->number < (*stack_a)->next->number
		&& (*stack_a)->next->number < (*stack_a)->number)
	{
		swap(stack_a, stack_a, "sa\n", 1);
		reverse_rotate(stack_a, stack_a, "rra\n", 1);
	}
}

void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	index_min;
	int	dist_min;

	sort_two_or_less(stack_a);
	quick_sort_alt(stack_a, stack_b);
	sort_three_element(stack_a);
	push_back_to_a(stack_a, stack_b);
	min = min_in_stack(*stack_a);
	index_min = find_index(*stack_a, min);
	dist_min = distance_to_head(*stack_a, index_min);
	several_ra_or_revra(stack_a, dist_min);
}
