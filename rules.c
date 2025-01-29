/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:17:07 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/30 00:17:26 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	putstr_or_exit(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_putstr_fd(str, 1) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		lstclear_alt(stack_a);
		lstclear_alt(stack_b);
		exit(1);
	}
}

void	swap(t_stack **stack_a, t_stack **stack_b, char *sa_sb,
		int print_or_not)
{
	t_stack	*temp;

	if (sa_sb[1] == 'a' && *stack_a != NULL && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next->next;
		lstadd_front_alt(stack_a, (*stack_a)->next);
		(*stack_a)->next->next = temp;
	}
	if (sa_sb[1] == 'b' && *stack_b != NULL && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->next->next;
		lstadd_front_alt(stack_b, (*stack_b)->next);
		(*stack_b)->next->next = temp;
	}
	if (print_or_not == 1)
		putstr_or_exit(stack_a, stack_b, sa_sb);
}

void	push(t_stack **stack_a, t_stack **stack_b, char *pa_pb,
		int print_or_not)
{
	t_stack	*temp;

	if (pa_pb[1] == 'a' && *stack_b != NULL)
	{
		temp = (*stack_b)->next;
		lstadd_front_alt(stack_a, *stack_b);
		*stack_b = temp;
	}
	if (pa_pb[1] == 'b' && *stack_a != NULL)
	{
		temp = (*stack_a)->next;
		lstadd_front_alt(stack_b, *stack_a);
		*stack_a = temp;
	}
	if (print_or_not == 1)
		putstr_or_exit(stack_a, stack_b, pa_pb);
}

void	rotate(t_stack **stack_a, t_stack **stack_b, char *ra_rb_rr,
		int print_or_not)
{
	t_stack	*temp;

	if ((ra_rb_rr[1] == 'a' || ra_rb_rr[1] == 'r') && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next;
		lstadd_back_alt(stack_a, *stack_a);
		(*stack_a)->next = NULL;
		*stack_a = temp;
	}
	if ((ra_rb_rr[1] == 'b' || ra_rb_rr[1] == 'r') && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->next;
		lstadd_back_alt(stack_b, *stack_b);
		(*stack_b)->next = NULL;
		*stack_b = temp;
	}
	if (print_or_not == 1)
		putstr_or_exit(stack_a, stack_b, ra_rb_rr);
}

void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *ra_rb_rr,
		int print_or_not)
{
	t_stack	*temp;
	t_stack	*first;

	if ((ra_rb_rr[2] == 'a' || ra_rb_rr[2] == 'r') && (*stack_a)->next != NULL)
	{
		first = *stack_a;
		temp = *stack_a;
		while (temp->next->next != NULL)
			temp = temp->next;
		lstadd_front_alt(&first, lstlast_alt(*stack_a));
		temp->next = NULL;
		*stack_a = first;
	}
	if ((ra_rb_rr[2] == 'b' || ra_rb_rr[2] == 'r') && (*stack_b)->next != NULL)
	{
		first = *stack_b;
		temp = *stack_b;
		while (temp->next->next != NULL)
			temp = temp->next;
		lstadd_front_alt(&first, lstlast_alt(*stack_b));
		temp->next = NULL;
		*stack_b = first;
	}
	if (print_or_not == 1)
		putstr_or_exit(stack_a, stack_b, ra_rb_rr);
}
