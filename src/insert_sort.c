#include "operations.h"
#include "push_swap.h"

typedef struct s_rotations {
	int rots;
	int rev_rots;
} t_rotations;



int max_rots(t_rotations rots) {
	if (rots.rots == -1)
		return rots.rev_rots;
	return rots.rots;
}

t_rotations get_nbr_of_rots(t_state state, int idx, char stack) {
	int size = state.size_a;
	if (stack == 'b')
		size = state.size_b;

	t_rotations rots = {-1, -1};

	if ((size - idx) < idx)
		rots.rev_rots = size - idx;
	else
		rots.rots = idx;
	return rots;
}

int get_amount_ops(t_state state, int pos) {
	int pos_in_b = get_idx_of_val_in_b(state, get_val_at_idx(state, pos, 'a'));
	t_rotations rots_in_a = get_nbr_of_rots(state, pos, 'a');
	t_rotations rots_in_b = get_nbr_of_rots(state, pos_in_b, 'b');

	return max_rots(rots_in_a) + max_rots(rots_in_b) + 1;
}

int get_min_amount_pos(t_state state) {
	int pos = 0;
	int min_amount = get_amount_ops(state, pos);
	int min_amount_pos = 0;
	t_stack *head = state.a;
	while (head) {
		int amount = get_amount_ops(state, pos);
		if (amount < min_amount) {
			min_amount = amount;
			min_amount_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return min_amount_pos;
}

t_state insert_new_val(t_state state) {
	int min_amount_pos = get_min_amount_pos(state);
	int min_amount_val = get_val_at_idx(state, min_amount_pos, 'a');
	int pos_in_b = get_idx_of_val_in_b(state, min_amount_val);

	t_rotations rots_a = get_nbr_of_rots(state, min_amount_pos, 'a');
	t_rotations rots_b = get_nbr_of_rots(state, pos_in_b, 'b');

	if (rots_a.rots == -1 && rots_b.rots == -1) {
		int min_rev_rots = rots_a.rev_rots;
		if (rots_a.rev_rots > rots_b.rev_rots)
			min_rev_rots = rots_b.rev_rots;

		state = reverse_rotate_n_times(state, min_rev_rots, 'r');

		if (rots_a.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_a.rev_rots - min_rev_rots, 'a');
		if (rots_b.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_b.rev_rots - min_rev_rots, 'b');
	} else if (rots_a.rev_rots == -1 && rots_b.rev_rots == -1) {
		int min_rots = rots_a.rots;
		if (rots_a.rots > rots_b.rots)
			min_rots = rots_b.rots;
		state = rotate_n_times(state, min_rots, 'r');
		if (rots_a.rots > min_rots)
			state = rotate_n_times(state, rots_a.rots - min_rots, 'a');
		if (rots_b.rots > min_rots)
			state = rotate_n_times(state, rots_b.rots - min_rots, 'b');
	} else {
		if (rots_a.rots == -1)
			state = reverse_rotate_n_times(state, rots_a.rev_rots, 'a');
		state = rotate_n_times(state, rots_a.rots, 'a');
		if (rots_b.rots == -1)
			state = reverse_rotate_n_times(state, rots_b.rev_rots, 'b');
		state = rotate_n_times(state, rots_b.rots, 'b');
	}

	return push_b(state);
}

t_state rotate_to_max_in_b(t_state state) {
	int max_idx = find_idx_of_max(state);
	t_rotations rots = get_nbr_of_rots(state, max_idx, 'b');
	if (rots.rots == -1)
		return reverse_rotate_n_times(state, rots.rev_rots, 'b');
	return rotate_n_times(state, rots.rots, 'b');
}


t_state insert_sort(t_state state) {
	if (state.size_a < 2)
		return state;
	if (state.size_a == 2)
		return sort_top_of_stack_ascending(state, 'a');

	state = push_b(state);
	state = push_b(state);

	while (state.a)
		state = insert_new_val(state);

	state = rotate_to_max_in_b(state);

	return push_b_to_a(state);

}

