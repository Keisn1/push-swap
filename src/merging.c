/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:10/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 17:10:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"
#include <stdio.h>

t_state merge_chunk_of_five(t_state state, int size, bool with_backing_up) {
	int count = 0;
	while (count++ < 5) {
		state = push_b(state);
		state = rotate(state, 'b');
	}

	count = 0;

	while (state.b) {
		printf("here");

		if (is_seq(state.b->content, state.a->content) || count >= 5) {
			state = push_a(state);
			state = rotate(state, 'a');
			continue;
		}
		state = rotate(state, 'a');
		count++;
	}

	print_stack(state.a);
	count = 0;
	if (with_backing_up) {
		while (count++ < 10) {
			state = reverse_rotate(state, 'a');
		}
	}

	if (with_backing_up) {

	}
	if (size) {
	}
	return state;
}


t_state merge_rest(t_state state, int size) {

	int rest = size % 5;
	int count = 0;
	while (count++ < rest) {
		state = reverse_rotate(state, 'a');
		state = push_b(state);
	}

	count = 0;
	while (count < size) {
		if (state.b && (is_seq(state.b->content, state.a->content) || (count >= size-rest))) {
			state = push_a(state);
			state = rotate(state, 'a');
			count++;
			continue;
		}
		state = rotate(state, 'a');
		count++;
	}

	return state;
}

