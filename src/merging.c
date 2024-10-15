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

t_state merge_rest(t_state state, int size) {

	int rest = size % 5;
	while (rest-- > 0) {
		state = reverse_rotate(state, 'a');
		state = push_b(state);
	}
	int count = 0;
	while (count++ < size) {
		if (state.b && is_seq(state.b->content, state.a->content)) {
			state = push_a(state);
		}
		state = rotate(state, 'a');
	}

	return state;
}
