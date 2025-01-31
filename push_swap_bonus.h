/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 22:23:26 by alpayet           #+#    #+#             */
/*   Updated: 2025/02/01 00:14:57 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include "libft/get_next_line/get_next_line.h"
# include "push_swap.h"

void	read_and_file_rules(t_stack **stack_a, t_list **rules);
void	check_format_rules(t_stack **stack_a, t_stack **stack_b,
			t_list **rules);

#endif
