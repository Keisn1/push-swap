/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:36/17 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/19 13:36:17 by kfreyer          ###   ########.fr       */
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

t_state	rotate(t_state state, char s)
{
	if (s == 'a')
		state.a = rot_stack(state.a);
	if (s == 'b')
		state.b = rot_stack(state.b);
	if (s == 'r')
	{
		state.a = rot_stack(state.a);
		state.b = rot_stack(state.b);
	}
	ft_putchar_fd('r', STDOUT_FILENO);
	ft_putchar_fd(s, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (state);
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

t_state	reverse_rotate(t_state state, char s)
{
	if (s == 'a')
		state.a = rev_rot_stack(state.a);
	if (s == 'b')
		state.b = rev_rot_stack(state.b);
	if (s == 'r')
	{
		state.a = rev_rot_stack(state.a);
		state.b = rev_rot_stack(state.b);
	}
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(s, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (state);
}
