/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:40:59 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/31 01:26:01 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->number > stack_a->next->number)
			return ;
		stack_a = stack_a->next;
	}
	exit(0);
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

static void	data_final_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*control;
	int		final_index_max;

	current = stack;
	final_index_max = stack_size(stack) - 1;
	while (current)
	{
		control = stack;
		while (control)
		{
			if (current->number < control->number)
				(current->final_index)++;
			control = control->next;
		}
		current->final_index = final_index_max - current->final_index;
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	check_errors_and_file_a(argv + 1, &stack_a);
	data_final_index(stack_a);
	is_sorted(stack_a);
	turk_algorithm(&stack_a, &stack_b);
	lstclear_alt(&stack_a);
}
