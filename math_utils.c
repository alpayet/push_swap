/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:08:15 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 22:38:39 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}
int	find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->number != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	max_in_stack(t_stack *stack)
{
	int	buff;

	buff = stack->number;
	while (stack)
	{
		if (stack->number > buff)
			buff = stack->number;
		stack = stack->next;
	}
	return (buff);
}
int	min_in_stack(t_stack *stack)
{
	int	buff;

	buff = stack->number;
	while (stack)
	{
		if (stack->number < buff)
			buff = stack->number;
		stack = stack->next;
	}
	return (buff);
}

int	imediate_successor(t_stack *stack, int nbr)
{
	long	buff;
	t_stack	*temp;

	buff = __LONG_MAX__;
	temp = stack;
	while (temp)
	{
		if (temp->number > nbr && temp->number <= buff)
			buff = temp->number;
		temp = temp->next;
	}
	if (buff == __LONG_MAX__)
		return (min_in_stack(stack));
	return (buff);
}



