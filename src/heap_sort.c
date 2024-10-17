/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:14/26 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/16 20:14:26 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"
#include <stdio.h>

int get_content_by_idx(t_stack *head, int idx) {
	int count = 0;
	while (count++ < idx) {
		head = head->next;
	}
	return *(int*)head->content;
}

void update_child(int *child_idx, int *child, int size, t_stack *head) {
	if ((*child_idx + 1) < size) {
		int right_child = get_content_by_idx(head, (*child_idx)+1);
		if (*child < right_child) {
			*child_idx = (*child_idx) + 1;
			*child = right_child;
		}
	}
}

t_state sift_down(t_state state, int root, int size) {
	if (size <= 1)
		return state;

	int left_child_idx = 2*root + 1;
	if (left_child_idx >= size) {
		return state;
	}

	int left_child = get_content_by_idx(state.b, left_child_idx);
	int child_idx = left_child_idx;
	int child = left_child;
	update_child(&child_idx, &child, size, state.b);

	if (is_seq(state.b->content, &child)) {
		state = push_a(state);
		state = rotate_b_n_times(state, child_idx-1);
		state = push_a(state);
		state = swap(state, 'a');
		state = push_b(state);
		state = reverse_rotate_b_n_times(state, child_idx-1);
		state = push_b(state);
	}

	return state;
}
