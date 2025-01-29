/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:24:28 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/30 00:23:07 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	several_ra_or_revra(t_stack **stack_a, int dist_head_a)
{
	if (dist_head_a < 0)
	{
		while (dist_head_a != 0)
		{
			rotate(stack_a, stack_a, "ra\n", 1);
			dist_head_a++;
		}
	}
	else
	{
		while (dist_head_a != 0)
		{
			reverse_rotate(stack_a, stack_a, "rra\n", 1);
			dist_head_a--;
		}
	}
}

void	several_rb_or_revrb(t_stack **stack_b, int dist_head_b)
{
	if (dist_head_b < 0)
	{
		while (dist_head_b != -1)
		{
			rotate(stack_b, stack_b, "rb\n", 1);
			dist_head_b++;
		}
		if ((*stack_b)->final_index + 1 == (*stack_b)->next->final_index)
			swap(stack_b, stack_b, "sb\n", 1);
		else
			rotate(stack_b, stack_b, "rb\n", 1);
	}
	else
	{
		while (dist_head_b != 0)
		{
			reverse_rotate(stack_b, stack_b, "rrb\n", 1);
			dist_head_b--;
		}
	}
}

void	several_rr_or_rrr(t_stack **stack_a, t_stack **stack_b, int dist_head)
{
	if (dist_head <= 0)
	{
		while (dist_head != 0)
		{
			rotate(stack_a, stack_b, "rr\n", 1);
			dist_head++;
		}
	}
	else
	{
		while (dist_head != 0)
		{
			reverse_rotate(stack_a, stack_b, "rrr\n", 1);
			dist_head--;
		}
	}
}

void	execute_rules(t_stack **stack_a, t_stack **stack_b, int *rules_for_node)
{
	if (rules_for_node[3] == 1)
	{
		several_rr_or_rrr(stack_a, stack_b, rules_for_node[1]);
		several_ra_or_revra(stack_a, rules_for_node[2]);
	}
	if (rules_for_node[3] == -1)
	{
		several_rr_or_rrr(stack_a, stack_b, rules_for_node[2]);
		several_rb_or_revrb(stack_b, rules_for_node[1]);
	}
	if (rules_for_node[3] == 0)
	{
		several_rb_or_revrb(stack_b, rules_for_node[1]);
		several_ra_or_revra(stack_a, rules_for_node[2]);
	}
	push(stack_a, stack_b, "pa\n", 1);
}
