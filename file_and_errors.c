/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:10:05 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/14 22:34:25 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_errors(t_stack **stack_a)
{
	ft_putstr_fd("Error\n", 2);
	lstclear_alt(stack_a);
	exit(1);
}

static long	ft_atol_alt(const char *nptr, t_stack **stack_a)
{
	int		sign;
	long	n;

	n = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (n > (10 * n + *nptr - '0'))
			return (-1);
		n = 10 * n + *nptr - '0';
		nptr++;
	}
	if (*nptr != '\0')
		process_errors(stack_a);
	return (sign * n);
}

static void	fill_manag_duplicates(int nbr, t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*new_node;

	temp = *stack_a;
	while (temp)
	{
		if (nbr == temp->number)
			process_errors(stack_a);
		temp = temp->next;
	}
	new_node = lstnew_alt(nbr);
	if (new_node == NULL)
		process_errors(stack_a);
	lstadd_back_alt(stack_a, new_node);
}

void	check_errors_and_file_a(char **argv, t_stack **stack_a)
{
	int	i;
	long	str_to_long;

	i = 0;
	while (argv[i])
	{
		//gestion des erreurs free les mallocs
		str_to_long = ft_atol_alt(argv[i], stack_a);
		if ((str_to_long < -2147483648 || str_to_long > 2147483647)
			|| (str_to_long == -1 && argv[i][2] != '\0'))
			process_errors(stack_a);
		fill_manag_duplicates((int)str_to_long, stack_a);
		i++;
	}
}
