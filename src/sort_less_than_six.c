#include "push_swap.h"
#include "operations.h"

t_state sort_top_of_stack_ascending(t_state state, char stack) {
	if (stack == 'a') {
		if (is_seq(state.a->next->content, state.a->content))
			return swap(state, 'a');
	} else if (stack == 'b') {
		if (is_seq( state.b->next->content, state.b->content))
			return swap(state, 'b');
	}
	return state;
}

/* total of 12 ops maximum */
/* would be less than 5 * log_2_5 = 5 * 2.3 = 11.5  */
t_state sort_five_elements(t_state state) {
	/* 2 operations */
	state = push_b(state);
	state = push_b(state);

	/* plus maximum of 2 operations */
	state = sort_three_elements(state);

	/* plus maximum of 1 operation */
	state = sort_top_of_stack_ascending(state, 'b');

	/* plus 5 rotations */
	/* plus 2 pushes */
	int count_rots = 0;
	while (count_rots < 5) {
		if (state.b && is_seq(state.b->content, state.a->content))
			state = push_a(state);
		if (state.b && state.b->next && count_rots == 3)
			state = push_a(state);
		if (state.b && count_rots == 4)
			state = push_a(state);
		state = rotate(state, 'a');
		count_rots++;
	}
	return state;
}

/* sorts the elements in a */
/* supposes that a has 4 elements */
/* maximum of 6 operations*/
t_state sort_four_elements(t_state state) {
	state = push_b(state);
	state = sort_three_elements(state);

	if (is_seq(state.a->next->next->content, state.b->content)) {
		state = push_a(state);
		state = rotate(state, 'a');
		return state;
	}

	int count = 0;
	while (is_seq(state.a->content, state.b->content)) {
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
/* supposes that a has 3 elements */
/* maximum of 2 operations*/
t_state sort_three_elements(t_state state) {
	void* first = state.a->content;
	void* second = state.a->next->content;
	void* third = state.a->next->next->content;;

	/* x_2 < x_1 < x_3 */
	if (is_seq(second, first) && is_seq(first, third))
		return swap(state, 'a');

	/* x_1 < x_3 < x_2 */
	if (is_seq(first, third) && is_seq(third, second)) {
		state = swap(state, 'a');
		return rotate(state, 'a');
	}

	/* x_3 < x_1 < x_2 */
	if (is_seq(third, second) && is_seq(first, second))
		return reverse_rotate(state, 'a');

	/* x_2 < x_3 < x_1 */
	if (is_seq(second, third) && is_seq(third, first))
		return rotate(state, 'a');

	/* x_3 < x_2 < x_1 */
	if (is_seq(third, second) && is_seq(second, first)) {
		state = rotate(state, 'a');
		return swap(state, 'a');
	}

	return state;
}
