/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alpayet <alpayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:24:09 by alpayet           #+#    #+#             */
/*   Updated: 2025/01/26 22:21:47 by alpayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*lstnew_alt(int number)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

t_stack	*lstlast_alt(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstclear_alt(t_stack **lst)
{
	t_stack	*next_alt;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next_alt = (*lst)->next;
		free(*lst);
		*lst = next_alt;
	}
}

void	lstadd_front_alt(t_stack **lst, t_stack *new)
{
	if (new == NULL || lst == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	lstadd_back_alt(t_stack **lst, t_stack *new)
{
	if (new == NULL || lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lstlast_alt(*lst)->next = new;
}




