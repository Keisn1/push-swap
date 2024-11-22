/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:29/25 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 07:29:25 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

/* maximum 12 operations */
t_state sort_four_elements_with_tail(t_state state) {
	state = push_b(state);
	/* maximum 5 operations */
	state = sort_three_elements_with_tail(state);

	int count = 0;
	while (leq(state.a->content, state.b->content) && count < 3) {
		state = rotate(state, 'a');
		count++;
	}
	state = push_a(state);

	while (count>0) {
		state = reverse_rotate(state, 'a');
		count--;
	}
	return state;

}
/* sorts the elements in a */
/* supposes that a has 4 elements */
/* maximum of 6 operations*/
t_state sort_four_elements(t_state state) {
	state = push_b(state);
	state = sort_three_elements(state);

	if (leq(state.a->next->next->content, state.b->content)) {
		state = push_a(state);
		state = rotate(state, 'a');
		return state;
	}

	int count = 0;
	while (leq(state.a->content, state.b->content)) {
		state = rotate(state, 'a');
		count++;
	}
	state = push_a(state);

	while (count>0) {
		state = reverse_rotate(state, 'a');
		count--;
	}
	return state;
}
