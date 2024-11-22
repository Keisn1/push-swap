/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:16/58 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/13 09:16:58 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_stack	*rot_stack(t_stack *stack)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(stack->next))
		return (stack);
	last = ft_lstlast(stack);
	first = stack;
	second = first->next;
	last->next = first;
	first->next = NULL;
	stack = second;
	return (stack);
}


t_stack	*rev_rot_stack(t_stack *stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (!stack || !(stack->next))
		return (stack);
	second_last = stack;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = stack;
	return (last);
}




t_stack	*swap_stack(t_stack *head)
{
	t_stack	*second;

	if (!head)
		return (head);
	second = head->next;
	if (!second)
		return (head);
	head->next = second->next;
	second->next = head;
	return (second);
}


t_state	sort_top_of_stack(t_state state, char stack)
{
	if (stack == 'a')
		if (!leq(state.a->content, state.a->next->content))
			return swap(state, 'a');
	if (!leq(state.b->content, state.b->next->content))
		return swap(state, 'b');
	return state;
}
