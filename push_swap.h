/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:48:30 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 22:45:05 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdint.h>
# include <unistd.h>

typedef struct s_stack
{
	int	number;
	int	final_index;
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
void	check_errors_and_file_a(char **argv, t_stack **stack_a);
int	stack_size(t_stack *stack);
void	turk_algorithm(t_stack **stack_a, t_stack **stack_b);
void	several_ra_or_revra(t_stack **stack_a, int dist_head_a);
void	execute_rules(t_stack **stack_a, t_stack **stack_b, long *rules_for_node);
int	distance_to_head(t_stack *stack, int index_nbr);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);
int	ft_abs(int nbr);
int	find_index(t_stack *stack, int nbr);
int	min_in_stack(t_stack *stack);
int	max_in_stack(t_stack *stack);
int	imediate_successor(t_stack *stack, int nbr);


#endif
