/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:40:59 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 22:33:45 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	t_stack	*temp1;
	t_stack	*temp2;
	int	final_index_max;
	
	temp1 = stack;
	final_index_max = stack_size(stack) - 1;
	while (temp1)
	{
		temp2 = stack;
		while (temp2)
		{
			if (temp1->number < temp2->number)
				(temp1->final_index)++;
			temp2 = temp2->next;
		}
		temp1->final_index = final_index_max - temp1->final_index;
		temp1 = temp1->next;
	}
}

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
	data_final_index(stack_a);
	//quick_sort_alt(&stack_a, &stack_b);
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
	// 	printf("a:%d\n", buff_a->final_index);
	// 	buff_a = buff_a->next;
	// }
	// while (buff_b)
	// {
	// 	printf("b:%d\n", buff_b->final_index);
	// 	buff_b = buff_b->next;
	// }
	// 	buff_a = stack_a;
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
	lstclear_alt(&stack_a);
	lstclear_alt(&stack_b);
}
