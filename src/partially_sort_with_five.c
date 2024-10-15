#include "operations.h"
#include "push_swap.h"

t_state partially_sort_with_five(t_state state, int size) {
	if (size < 2)
		return state;
	if (size == 2)
		return sort_top_of_stack(state, 'a');

	state = sort_five_elements(state);
	state = rotate(state, 'a');
	return state;
}
