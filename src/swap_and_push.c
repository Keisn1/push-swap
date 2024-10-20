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

#include "libft.h"
#include "operations.h"

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

t_state	swap(t_state state, char s)
{
	if (s == 'a')
		state.a = swap_stack(state.a);
	if (s == 'b')
		state.b = swap_stack(state.b);
	if (s == 's')
	{
		state.a = swap_stack(state.a);
		state.b = swap_stack(state.b);
	}
	ft_putchar_fd('s', STDOUT_FILENO);
	ft_putchar_fd(s, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	return (state);
}

t_state	push_a(t_state state)
{
	t_stack	*top_a;

	ft_putendl_fd("pa", STDOUT_FILENO);
	if (!state.b)
		return (state);
	top_a = state.b;
	state.b = top_a->next;
	top_a->next = state.a;
	state.a = top_a;
	state.size_a++;
	state.size_b--;
	return (state);
}

t_state	push_b(t_state state)
{
	t_stack	*top_b;

	ft_putendl_fd("pb", STDOUT_FILENO);
	if (!state.a)
		return (state);
	top_b = state.a;
	state.a = top_b->next;
	top_b->next = state.b;
	state.b = top_b;
	state.size_b++;
	state.size_a--;
	return (state);
}
