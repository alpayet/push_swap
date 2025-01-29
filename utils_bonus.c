/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:08:04 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/30 00:49:35 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_and_file_rules(t_stack **stack_a, t_list **rules)
{
	char	*str;
	t_list	*new_node;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		new_node = ft_lstnew(str);
		if (new_node == NULL)
		{
			ft_lstclear(rules, free);
			lstclear_alt(stack_a);
		}
		ft_lstadd_back(rules, new_node);
	}
}

static void	bad_format(char *str, t_stack **stack_a, t_list **rules)
{
	if (ft_strncmp(str, "sa\n", 4) != 0 && ft_strncmp(str, "sb\n", 4) != 0
		&& ft_strncmp(str, "ss\n", 4) != 0 && ft_strncmp(str, "pa\n", 4) != 0
		&& ft_strncmp(str, "pb\n", 4) != 0 && ft_strncmp(str, "rb\n", 4) != 0
		&& ft_strncmp(str, "ra\n", 4) != 0 && ft_strncmp(str, "rr\n", 4) != 0
		&& ft_strncmp(str, "rra\n", 5) != 0 && ft_strncmp(str, "rrb\n", 5) != 0
		&& ft_strncmp(str, "rrr\n", 5) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_lstclear(rules, free);
		lstclear_alt(stack_a);
		exit(1);
	}
}

static void	do_rules(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strncmp(str, "sa\n", 4) == 0)
		swap(stack_a, stack_a, "sa\n", 0);
	if (ft_strncmp(str, "sb\n", 4) == 0)
		swap(stack_b, stack_b, "sb\n", 0);
	if (ft_strncmp(str, "ss\n", 4) == 0)
		swap(stack_a, stack_b, "ss\n", 0);
	if (ft_strncmp(str, "pa\n", 4) == 0)
		push(stack_a, stack_b, "pa\n", 0);
	if (ft_strncmp(str, "pb\n", 4) == 0)
		push(stack_a, stack_b, "pb\n", 0);
	if (ft_strncmp(str, "ra\n", 4) == 0)
		rotate(stack_a, stack_a, "ra\n", 0);
	if (ft_strncmp(str, "rb\n", 4) == 0)
		rotate(stack_b, stack_b, "rb\n", 0);
	if (ft_strncmp(str, "rr\n", 4) == 0)
		rotate(stack_a, stack_b, "rr\n", 0);
	if (ft_strncmp(str, "rra\n", 5) == 0)
		reverse_rotate(stack_a, stack_a, "rra\n", 0);
	if (ft_strncmp(str, "rrb\n", 5) == 0)
		reverse_rotate(stack_b, stack_b, "rrb\n", 0);
	if (ft_strncmp(str, "rrr\n", 5) == 0)
		reverse_rotate(stack_a, stack_b, "rrr\n", 0);
}

void	check_format_rules(t_stack **stack_a, t_stack **stack_b, t_list **rules)
{
	t_list	*temp;
	char	*str;

	temp = *rules;
	while (temp)
	{
		str = (char *)temp->content;
		bad_format(str, stack_a, rules);
		do_rules(stack_a, stack_b, str);
		temp = temp->next;
	}
}

void	is_sorted_bonus(t_stack *stack_a, t_stack *stack_b)
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
