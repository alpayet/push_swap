/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:23:26 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 23:07:49 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
#include "push_swap.h"
#include "libft/get_next_line/get_next_line.h"

void	read_and_file_rules(t_stack **stack_a, t_list **rules);
void	check_format_rules(t_stack **stack_a, t_stack **stack_b, t_list **rules);
void	is_sorted(t_stack *stack_a, t_stack *stack_b);

#endif
