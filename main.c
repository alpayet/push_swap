/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:40:59 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/14 21:59:24 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	// t_stack	*buff_a;
	// t_stack	*buff_b;

	if (argc == 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	check_errors_and_file_a(argv + 1, &stack_a);
	// rotate(&stack_a, &stack_b, "rb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// push(&stack_a, &stack_b, "pb");
	// // rotate(&stack_a, &stack_b, "rb");
	// // rotate(&stack_a, &stack_b, "rb");
	// // push(&stack_a, &stack_b, "pb");
	// // reverse_rotate(&stack_a, &stack_b, "rrr");
	// // push(&stack_a, &stack_b, "pb");
	// buff_a = stack_a;
	// buff_b = stack_b;
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
	// push_almost_all_in_b(&stack_a, &stack_b);
	// buff_a = stack_a;
	// buff_b = stack_b;
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
	// printf("\n%d\n",ft_abs(distance_to_head(&stack_b, 2 + distance_to_head(&stack_a, 2))));
	//1 2 5 6 7 10 11 13 14 16 17 19 9 8 4 18 20 3 15 12
	turk_algorithm(&stack_a, &stack_b);
	lstclear_alt(&stack_a);
	lstclear_alt(&stack_b);
}