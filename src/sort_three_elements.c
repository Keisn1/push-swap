/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:47/40 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 15:47:40 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "push_swap.h"
#include <unistd.h>

/* maximum of 5 operations */
t_state sort_three_elements_with_tail(t_state state) {
	void* first = state.a->content;
	void* second = state.a->next->content;
	void* third = state.a->next->next->content;;

	/* x_2 < x_1 < x_3 */
	if (leq(second, first) && leq(first, third))
		return swap(state, 'a');

	/* x_1 < x_3 < x_2 */
	if (leq(first, third) && leq(third, second)) {
		state = rotate(state, 'a');
		state = swap(state, 'a');
		return reverse_rotate(state, 'a');
	}

	/* x_3 < x_1 < x_2 */
	if (leq(third, second) && leq(first, second)) {
		state = rotate(state, 'a');
		state = swap(state, 'a');
		state = reverse_rotate(state, 'a');
		return swap(state, 'a');
	}

	/* x_2 < x_3 < x_1 */
	if (leq(second, third) && leq(third, first)) {
		state = swap(state, 'a');
		state = rotate(state, 'a');
		state = swap(state, 'a');
		return reverse_rotate(state, 'a');
	}

	/* x_3 < x_2 < x_1 */
	if (leq(third, second) && leq(second, first)) {
		state = swap(state, 'a');
		state = rotate(state, 'a');
		state = swap(state, 'a');
		state = reverse_rotate(state, 'a');
		return swap(state, 'a');
	}

	return state;
}

/* sorts the elements in a */
/* supposes that a has 3 elements */
/* maximum of 2 operations*/
t_state sort_three_elements(t_state state) {
	void* first = state.a->content;
	void* second = state.a->next->content;
	void* third = state.a->next->next->content;;

	/* x_2 < x_1 < x_3 */
	if (leq(second, first) && leq(first, third))
		return swap(state, 'a');

	/* x_1 < x_3 < x_2 */
	if (leq(first, third) && leq(third, second)) {
		state = swap(state, 'a');
		return rotate(state, 'a');
	}

	/* x_3 < x_1 < x_2 */
	if (leq(third, second) && leq(first, second))
		return reverse_rotate(state, 'a');

	/* x_2 < x_3 < x_1 */
	if (leq(second, third) && leq(third, first))
		return rotate(state, 'a');

	/* x_3 < x_2 < x_1 */
	if (leq(third, second) && leq(second, first)) {
		state = rotate(state, 'a');
		return swap(state, 'a');
	}

	return state;
}


