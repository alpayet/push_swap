/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:08:15 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/23 19:13:12 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	stack_size(t_stack *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_abs(int	number)
{
	if (number < 0)
		return (-number);
	return (number);
}
int	find_index(t_stack **stack_a_b, int nbr)
{
	int	i;
	t_stack	*temp;

	temp = *stack_a_b;
	i = 0;
	while (temp->number != nbr)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
int	find_index_last(t_stack **stack_a_b)
{
	int	index_last;
	t_stack	*temp;

	temp = *stack_a_b;
	index_last = -1;
	while (temp)
	{
		index_last++;
		temp = temp->next;
	}
	return (index_last);
}

int	max_in_stackb(t_stack **stack_b)
{
	int	buff;
	t_stack	*stack_b_temp;

	buff = (*stack_b)->number;
	stack_b_temp = *stack_b;
	while (stack_b_temp)
	{
		if (stack_b_temp->number > buff)
			buff = stack_b_temp->number;
		stack_b_temp = stack_b_temp->next;
	}
	return (buff);
}
int	min_in_stacka(t_stack **stack_a)
{
	int	buff;
	t_stack	*stack_a_temp;

	buff = (*stack_a)->number;
	stack_a_temp = *stack_a;
	while (stack_a_temp)
	{
		if (stack_a_temp->number < buff)
			buff = stack_a_temp->number;
		stack_a_temp = stack_a_temp->next;
	}
	return (buff);
}

int	max_below_in_stackb(t_stack **stack_b, int nbr)
{
	long 	buff;
	t_stack	*stack_b_temp;

	buff = LONG_MIN;
	stack_b_temp = *stack_b;
	while (stack_b_temp)
	{
		if (stack_b_temp->number < nbr && stack_b_temp->number >= buff)
			buff = stack_b_temp->number;
		stack_b_temp = stack_b_temp->next;
	}
	if (buff == LONG_MIN)
		return (max_in_stackb(stack_b));
	return (buff);
}

int	min_above_in_stacka(t_stack **stack_a, int nbr)
{
	long	buff;
	t_stack	*stack_a_temp;

	buff = LONG_MAX;
	stack_a_temp = *stack_a;
	while (stack_a_temp)
	{
		if (stack_a_temp->number > nbr && stack_a_temp->number <= buff)
			buff = stack_a_temp->number;
		stack_a_temp = stack_a_temp->next;
	}
	if (buff == LONG_MAX)
		return (min_in_stacka(stack_a));
	return (buff);
}

int	distance_to_head(t_stack **stack_a_b, int index_nbr)
{
	int	index_last;

	if (index_nbr <= 0)
		return (0);
	index_last = find_index_last(stack_a_b);
	if (index_nbr >= index_last)
		return (1);
	if (index_nbr < (float)index_last / 2 + 1)
		return (-index_nbr);
	return (index_last - index_nbr + 1);
}

void fill_tab(int dist_nbr, int dist_min_above_nbr, int rr_rrr_or_not, int *tab)
{
	tab[0] = ft_abs(dist_nbr) + ft_abs(dist_min_above_nbr) + 1;
	tab[1] = dist_nbr;
	tab[2] = dist_min_above_nbr;
	tab[3] = rr_rrr_or_not;
}

void same_rules_to_head(int dist_nbr, int dist_min_above_nbr, int *tab)
{
	if (dist_nbr == 0 || dist_min_above_nbr == 0)
		return(fill_tab(dist_nbr, dist_min_above_nbr, 0, tab));
	if (dist_nbr < 0)
	{
		if (dist_nbr < dist_min_above_nbr)
			return(fill_tab(dist_nbr - dist_min_above_nbr, dist_min_above_nbr, -1, tab));
		return(fill_tab(dist_nbr, dist_min_above_nbr - dist_nbr, 1, tab));
	}
	if (dist_nbr < dist_min_above_nbr)
		return(fill_tab(dist_nbr, dist_min_above_nbr - dist_nbr, 1, tab));
	return(fill_tab(dist_nbr - dist_min_above_nbr, dist_min_above_nbr, -1, tab));
}
void rules_params(t_stack **stack_a, t_stack **stack_b, int nbr, int *tab)
{
	int	index_nbr;
	int	index_min_above;
	int	dist_nbr;
	int	dist_min_above_nbr;
	int	dist_after_rules;

	index_nbr = find_index(stack_b, nbr);
	index_min_above = find_index(stack_a, min_above_in_stacka(stack_a, nbr));
	dist_nbr = distance_to_head(stack_b, index_nbr);
	dist_min_above_nbr = distance_to_head(stack_a, index_min_above);
	dist_after_rules = distance_to_head(stack_a, index_min_above + dist_nbr);
	tab[4] = index_min_above;
	if (dist_nbr * dist_min_above_nbr >= 0)
		return(same_rules_to_head(dist_nbr, dist_min_above_nbr, tab));
	if (dist_nbr < 0 && ft_abs(dist_min_above_nbr) < ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_min_above_nbr, 0, tab));
	if (dist_nbr < 0 && ft_abs(dist_min_above_nbr) >= ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_after_rules, 1, tab));
	if (dist_nbr > 0 && ft_abs(dist_min_above_nbr) < ft_abs(dist_after_rules))
		return(fill_tab(dist_nbr, dist_min_above_nbr, 0, tab));
	return(fill_tab(dist_nbr, dist_after_rules, 1, tab));
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

void	several_ra_or_revra(t_stack **stack_a, int dist_head_a)
{
	if (dist_head_a < 0)
	{
		while (dist_head_a != 0)
		{
			rotate(stack_a, stack_a, "ra\n", 1);
			dist_head_a++;
		}
		// if ((*stack_a)->number == min_above_in_stacka(stack_a, (*stack_a)->next->number)
		// 	&& max_below_in_stackb(stack_b, (*stack_a)->number) > (*stack_a)->next->number
		// 	swap(stack_a, stack_a, "sa\n");
		// else
		// 	rotate(stack_a, stack_a, "ra\n");
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
	if (dist_head_b <= 0)
	{
		while (dist_head_b != 0)
		{
			rotate(stack_b, stack_b, "rb\n", 1);
			dist_head_b++;
		}
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

#include <stdio.h>

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int	buff[5];
	int	list_of_rules[5];
	// t_stack	*buff_a;
	// t_stack	*buff_b;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	buff[0] = 2147483647;
	while (temp)
	{
		rules_params(stack_a, stack_b, temp->number, list_of_rules);
		// printf("list %d ,%d ,%d ,%d ,%d\n", list_of_rules[0], list_of_rules[1],list_of_rules[2],list_of_rules[3],list_of_rules[4]);
		if (list_of_rules[0] < buff[0])
		{
			buff[0] = list_of_rules[0];
			buff[1] = list_of_rules[1];
			buff[2] = list_of_rules[2];
			buff[3] = list_of_rules[3];
			buff[4] = list_of_rules[4];
		}
		temp = temp->next;
	}
	// printf("buff %d ,%d ,%d ,%d ,%d\n", buff[0], buff[1],buff[2],buff[3],buff[4]);
	execute_rules(stack_a, stack_b, buff);
	// buff_a = *stack_a;
	// buff_b = *stack_b;
	// while (buff_a)
	// {
	// 	printf("a:%d\n", buff_a->number);
	// 	buff_a = buff_a->next;
	// }
	// while (buff_b)
	// {
	// 	printf("b:%d\n", buff_b->number);
	// 	buff_b = buff_b->next;
	// }
	push_back_to_a(stack_a, stack_b);
}
void	sort_three_element(t_stack **stack_a)
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

// void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	index_min_above;
// 	int	dist_min_above_nbr;

// 	if (*stack_b == NULL)
// 		return ;
// 	index_min_above = find_index(stack_a, min_above_in_stacka(stack_a, (*stack_b)->number));
// 	dist_min_above_nbr = distance_to_head(stack_a, index_min_above);
// 	several_ra_or_revra(stack_a, dist_min_above_nbr);
// 	push(stack_a, stack_b, "pa\n", 1);
// 	push_back_to_a(stack_a, stack_b);
// }
void	sort_three_or_less(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		exit(0);
	if ((*stack_a)->next->next == NULL)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			swap(stack_a, stack_a, "sa\n", 1);
		exit(0);
	}
	if ((*stack_a)->next->next->next == NULL)
	{
		sort_three_element(stack_a);
		exit(0);
	}
}
void	quick_sort_alt(t_stack **stack_a, t_stack **stack_b)
{
	int	stacka_size;
	int	final_index_max;
	
	stacka_size = stack_size(*stack_a);
	final_index_max = stack_size(*stack_a) - 1;
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
void	turk_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	min_or_max;
	int	index;
	int	dist;
	// t_stack	*buff_a;
	// t_stack	*buff_b;

	sort_three_or_less(stack_a);
	quick_sort_alt(stack_a, stack_b);
	sort_three_element(stack_a);
	// buff_a = *stack_a;
	// buff_b = *stack_b;
	// while (buff_a)
	// {
	// 	printf("a:%d\n", buff_a->number);
	// 	buff_a = buff_a->next;
	// }
	// while (buff_b)
	// {
	// 	printf("b:%d\n", buff_b->number);
	// 	buff_b = buff_b->next;
	// }
	push_back_to_a(stack_a, stack_b);
	// // push(stack_a, stack_b, "pb\n", 1);
	// // if ((*stack_a)->next->next->next->next != NULL)
 	// // 	push(stack_a, stack_b, "pb\n", 1);
	// // push_almost_all_in_b(stack_a, stack_b);
	// // min_or_max = max_in_stackb(stack_b);
	// // index = find_index(stack_b, min_or_max);
	// // dist = distance_to_head(stack_b, index);
	// // several_rb_or_revrb(stack_b, dist);
	min_or_max = min_in_stacka(stack_a);
	index = find_index(stack_a, min_or_max);
	dist = distance_to_head(stack_a, index);
	several_ra_or_revra(stack_a, dist);
}
