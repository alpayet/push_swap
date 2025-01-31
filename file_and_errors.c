/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:10:05 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/31 02:58:12 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_errors(t_stack **stack_a, char **tab, int j)
{
	int	i;

	ft_putstr_fd("Error\n", 2);
	i = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	lstclear_alt(stack_a);
	exit(1);
}

static long	ft_atol_alt(char *nptr, t_stack **stack_a, char **tab, int j)
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
		process_errors(stack_a, tab, j);
	return (sign * n);
}

static void	fill_manag_duplicates(int nbr, t_stack **stack_a, char **tab, int j)
{
	t_stack	*temp;
	t_stack	*new_node;

	temp = *stack_a;
	while (temp)
	{
		if (nbr == temp->number)
			process_errors(stack_a, tab, j);
		temp = temp->next;
	}
	new_node = lstnew_alt(nbr);
	new_node->final_index = 0;
	if (new_node == NULL)
		process_errors(stack_a, tab, j);
	lstadd_back_alt(stack_a, new_node);
}

void	check_errors_and_file_a(char **argv, t_stack **stack_a)
{
	int		i;
	int		j;
	long	str_to_long;
	char	**tab;

	i = 0;
	while (argv[i])
	{
		tab = ft_split(argv[i], ' ');
		if (!tab)
			process_errors(stack_a, NULL, -1);
		j = 0;
		while (tab[j])
		{
			str_to_long = ft_atol_alt(tab[j], stack_a, tab, j);
			if ((str_to_long < INT_MIN || str_to_long > INT_MAX)
				|| (str_to_long == -1 && tab[j][2] != '\0'))
				process_errors(stack_a, tab, j);
			fill_manag_duplicates((int)str_to_long, stack_a, tab, j);
			free(tab[j]);
			j++;
		}
		free(tab);
		i++;
	}
}
