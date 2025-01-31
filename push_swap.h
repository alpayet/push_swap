/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:48:30 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/31 20:53:09 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				final_index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				index_nbr;
	int				index_successor;
	int				dist_nbr;
	int				dist_successor;
	int				dist_after_rules;
}					t_data;

t_stack				*stack_new(int number);
t_stack				*stack_last(t_stack *lst);
void				stack_clear(t_stack **lst);
void				stack_addfront(t_stack **lst, t_stack *new);
void				stack_addback(t_stack **lst, t_stack *new);
void				swap(t_stack **stack_a, t_stack **stack_b, char *sa_sb,
						int print_or_not);
void				push(t_stack **stack_a, t_stack **stack_b, char *pa_pb,
						int print_or_not);
void				rotate(t_stack **stack_a, t_stack **stack_b, char *ra_rb_rr,
						int print_or_not);
void				reverse_rotate(t_stack **stack_a, t_stack **stack_b,
						char *ra_rb_rr, int print_or_not);
void				check_errors_and_file_a(char **argv, t_stack **stack_a);
int					stack_size(t_stack *stack);
void				turk_algorithm(t_stack **stack_a, t_stack **stack_b);
void				several_ra_or_revra(t_stack **stack_a, int dist_head_a);
void				execute_rules(t_stack **stack_a, t_stack **stack_b,
						int *rules_for_node);
int					distance_to_head(t_stack *stack, int index_nbr);
void				push_back_to_a(t_stack **stack_a, t_stack **stack_b);
int					ft_abs(int nbr);
int					find_index(t_stack *stack, int nbr);
int					min_in_stack(t_stack *stack);
int					max_in_stack(t_stack *stack);
int					imediate_successor(t_stack *stack, int nbr);

#endif
