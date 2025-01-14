/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:48:30 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/14 22:15:15 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	number;
	struct s_stack	*next;
}	t_stack;

t_stack	*lstnew_alt(int number);
t_stack	*lstlast_alt(t_stack *lst);
void	lstclear_alt(t_stack **lst);
void	lstadd_front_alt(t_stack **lst, t_stack *new);
void	lstadd_back_alt(t_stack **lst, t_stack *new);
void	swap(t_stack **stack_a, t_stack **stack_b, char *sa_sb, int print_or_not);
void	push(t_stack **stack_a, t_stack **stack_b, char *pa_pb, int print_or_not);
void	rotate(t_stack **stack_a, t_stack **stack_b, char *ra_rb_rr, int print_or_not);
void	reverse_rotate(t_stack **stack_a, t_stack **stack_b, char *ra_rb_rr, int print_or_not);
void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);
void	check_errors_and_file_a(char **argv, t_stack **stack_a);


#endif