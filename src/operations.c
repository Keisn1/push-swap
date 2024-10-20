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
#include <stdio.h>
#include <unistd.h>

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
	if (s == 'a') {
		ft_putendl_fd("sa", STDOUT_FILENO);
		state.a = swap_stack(state.a);
	}
	if (s == 'b') {
		ft_putendl_fd("sb", STDOUT_FILENO);
		state.b = swap_stack(state.b);
        }
	if (s == 's') {
		ft_putendl_fd("ss", STDOUT_FILENO);
		state.a = swap_stack(state.a);
		state.b = swap_stack(state.b);
	}
	return state;

}

t_state push_a(t_state state) {
	ft_putendl_fd("pa", STDOUT_FILENO);
	if (!state.b)
		return state;
	t_stack *top_a = state.b;
	state.b = top_a->next;
	top_a->next = state.a;
	state.a = top_a;
	state.size_a++;
	state.size_b--;
	return state;
}

t_state push_b(t_state state) {
	ft_putendl_fd("pb", STDOUT_FILENO);
	if (!state.a)
		return state;
	t_stack *top_b = state.a;
	state.a = top_b->next;
	top_b->next = state.b;
	state.b = top_b;
	state.size_b++;
	state.size_a--;
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
	if (s == 'a') {
		ft_putendl_fd("ra", STDOUT_FILENO);
		state.a = rot_stack(state.a);
	}
	if (s == 'b') {
		ft_putendl_fd("rb", STDOUT_FILENO);
		state.b = rot_stack(state.b);
	}
	if (s == 'r') {
		ft_putendl_fd("rr", STDOUT_FILENO);
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
	if (s == 'a') {
		ft_putendl_fd("rra", STDOUT_FILENO);
		state.a = rev_rot_stack(state.a);
	}
	if (s == 'b') {
		ft_putendl_fd("rrb", STDOUT_FILENO);
		state.b = rev_rot_stack(state.b);
	}
		if (s == 'r') {
		ft_putendl_fd("rrr", STDOUT_FILENO);
		state.a = rev_rot_stack(state.a);
		state.b = rev_rot_stack(state.b);
	}
	return state;
}

t_state sort_a_ascending(t_state state) {
	if (!is_seq(state.a->content, state.a->next->content))
		state = swap(state, 'a');
	return state;
}

t_state sort_b_ascending(t_state state) {
	if (!is_seq(state.b->content, state.b->next->content))
		state = swap(state, 'b');
	return state;
}

t_state sort_top_of_stack(t_state state, char stack) {
	if (stack == 'a') {
		return sort_a_ascending(state);
	}
	return sort_b_ascending(state);
}

t_state rotate_n_times(t_state state, int n, char stack) {
	if (stack == 'a') {
		int count = 0;
		while (count++ < n)
			state = rotate(state, 'a');
		return state;
	}
	if (stack == 'b') {
		int count = 0;
		while (count++ < n)
			state = rotate(state, 'b');
		return state;
	}
	if (stack == 'r') {
		int count = 0;
		while (count++ < n)
			state = rotate(state, 'r');
		return state;
	}
	return state;
}

t_state rotate_a_n_times(t_state state, int n) {
	/* rotate to the beginning */
	int count = 0;
	while (count++ < n)
		state = rotate(state, 'a');
	return state;
}

t_state rotate_b_n_times(t_state state, int n) {
	/* rotate to the beginning */
	int count = 0;
	while (count++ < n)
		state = rotate(state, 'b');
	return state;
}


t_state reverse_rotate_n_times(t_state state, int n, char stack) {
	if (stack == 'a') {
		int count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'a');
		return state;
	}
	if (stack == 'b') {
		int count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'b');
		return state;
	}
	if (stack == 'r') {
		int count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'r');
		return state;
	}
	return state;
}


t_state reverse_rotate_a_n_times(t_state state, int n) {
	/* rotate to the beginning */
	int count = 0;
	while (count++ < n)
		state = reverse_rotate(state, 'a');
	return state;
}

t_state reverse_rotate_b_n_times(t_state state, int n) {
	/* rotate to the beginning */
	int count = 0;
	while (count++ < n)
		state = reverse_rotate(state, 'b');
	return state;
}
