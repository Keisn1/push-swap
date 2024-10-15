#include "libft.h"
#include "operations.h"
#include "push_swap.h"
#include <unistd.h>

t_state sort_less_than_6(t_state state, int size) {
	if (size < 2)
		return state;
	if (size == 2)
		return sort_top_of_stack(state, 'a');
	if (size == 3)
		return sort_three_elements(state);
	if (size == 4)
		return sort_four_elements(state);
	if (size == 5)
		return sort_five_elements(state);
	return state;
}
void print_stack(t_stack *a) {
	while (a) {
		ft_putnbr_fd(*(int*)a->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		a = a->next;
	}
}

t_state partially_sort_with_five(t_state state, int size) {
	if (size < 6)
		return sort_less_than_6(state, size);

	state = sort_five_elements(state);
	size = size-5;
	print_stack(state.a);
	if (size < 6) {
		state = sort_less_than_6(state, size);
		while (size-- > 0)
			state = rotate(state, 'a');
	}

	return state;
}
