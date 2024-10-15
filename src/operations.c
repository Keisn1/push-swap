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
#include "libft.h"

t_stack *swap_stack(t_stack *head) {
	if (!head)
		return head;

	t_stack *second = head->next;
	if (!second)
		return head;
	head->next = second->next;
	second->next = head;
	return second;
}

t_state swap(t_state state, char s) {
	if (s == 'a')
		state.a = swap_stack(state.a);
	if (s == 'b')
		state.b = swap_stack(state.b);
	if (s == 's') {
		state.a = swap_stack(state.a);
		state.b = swap_stack(state.b);
	}
	return state;

}

t_state push_a(t_state state) {
	if (!state.b)
		return state;
	t_stack *top_a = state.b;
	state.b = top_a->next;
	top_a->next = state.a;
	state.a = top_a;
	return state;
}

t_state push_b(t_state state) {
	if (!state.a)
		return state;
	t_stack *top_b = state.a;
	state.a = top_b->next;
	top_b->next = state.b;
	state.b = top_b;
	return state;
}

t_stack *rot_stack(t_stack *stack) {
	if (!stack || !(stack->next))
		return stack;
	t_stack *last = ft_lstlast(stack);
	t_stack *first = stack;
	t_stack *second = first->next;
	last->next=first;
	first->next = NULL;
	stack = second;
	return stack;
}


t_state rotate(t_state state, char s) {
	if (s == 'a')
		state.a = rot_stack(state.a);
	if (s == 'b')
		state.b = rot_stack(state.b);
	if (s == 'r') {
		state.a = rot_stack(state.a);
		state.b = rot_stack(state.b);
	}
	return state;
}


t_stack *rev_rot_stack(t_stack *stack) {
	if (!stack || !(stack->next))
		return stack;

	t_stack *second_last = stack;
	while (second_last->next->next)
		second_last = second_last->next;

	t_stack *last = second_last->next;
	second_last->next = NULL;
	last->next = stack;
	return last;
}

t_state reverse_rotate(t_state state, char s) {
	if (s == 'a')
		state.a = rev_rot_stack(state.a);
	if (s == 'b')
		state.b = rev_rot_stack(state.b);
	if (s == 'r') {
		state.a = rev_rot_stack(state.a);
		state.b = rev_rot_stack(state.b);
	}
	return state;
}
