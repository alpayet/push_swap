/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:18:05 by alpayet           #+#    #+#             */
/*   Updated: 2025/02/01 00:14:53 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	is_sorted_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b != NULL)
	{
		ft_putstr_fd("KO\n", 1);
		return ;
	}
	while (stack_a->next)
	{
		if (stack_a->number > stack_a->next->number)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		stack_a = stack_a->next;
	}
	ft_putstr_fd("OK\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*rules;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	check_errors_and_file_a(argv + 1, &stack_a);
	rules = NULL;
	read_and_file_rules(&stack_a, &rules);
	check_format_rules(&stack_a, &stack_b, &rules);
	is_sorted_bonus(stack_a, stack_b);
	ft_lstclear(&rules, free);
	stack_clear(&stack_a);
	stack_clear(&stack_b);
}
