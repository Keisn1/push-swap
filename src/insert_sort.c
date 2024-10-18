#include "operations.h"
#include "push_swap.h"
#include <stdio.h>

int find_idx_of_min(t_state state) {
	int count = 0;
	t_stack *head = state.b;
	int min_val = *(int*)(head->content);
	int min_idx = 0;
	while (head) {
		if (*(int*)(head->content) < min_val) {
			min_val = *(int*)(head->content);
			min_idx = count;
		}
		head = head->next;
		count++;
	}
	return min_idx;
}

int find_idx_of_max(t_state state) {
	int count = 0;
	t_stack *head = state.b;
	int max_val = *(int*)(head->content);
	int max_idx = 0;
	while (head) {
		if (*(int*)(head->content) > max_val) {
			max_val = *(int*)(head->content);
			max_idx = count;
		}
		head = head->next;
		count++;
	}
	return max_idx;
}

int get_pos_in_b(t_state state, int val) {
	t_stack *head = state.b;
	int count = 0;
	int inf = val;
	int inf_idx = -1;
	while (head) {
		int head_val = *(int*)(head->content);
		if (head_val < val && (inf == val || head_val > inf)) {
			inf = head_val;
			inf_idx = count;
		}
		head = head->next;
		count++;
	}

	if (inf_idx == -1)
		return 1 + find_idx_of_min(state);

	return inf_idx;
}

int get_val_at_idx(t_state state, int idx, char stack) {
	int count = 0;
	t_stack *head;
	if (stack == 'a')
		head = state.a;
	else
		head = state.b;
	while (count++ < idx)
		head = head->next;
	return *(int*)(head->content);
}

int get_nbr_of_rots(t_state state, int idx, char stack) {
	int size = state.size_a;
	if (stack == 'b')
		size = state.size_b;

	if ((size - idx) < idx)
		return size - idx;
	return idx;
}

int get_amount_ops(t_state state, int pos) {
	int pos_in_b = get_pos_in_b(state, get_val_at_idx(state, pos, 'a'));
	int rots_in_a = get_nbr_of_rots(state, pos, 'a');
	int rots_in_b = get_nbr_of_rots(state, pos_in_b, 'b');

	return rots_in_a + rots_in_b + 1;
}

/* int insert_new_val(t_state state, int val) { */


/* } */

t_state insert_sort(t_state state) {
	if (state.size_a < 2)
		return state;
	if (state.size_a == 2)
		return sort_top_of_stack(state, 'a');

	state = push_b(state);
	state = push_b(state);

	int pos_in_b = get_pos_in_b(state, *(int*)(state.a->content));
	int rotations = get_nbr_of_rots(state, pos_in_b, 'b');

	state = rotate_b_n_times(state, rotations);
	state = push_b(state);

	int max_idx = find_idx_of_max(state);
	rotations = get_nbr_of_rots(state, max_idx, 'b');

	state = rotate_b_n_times(state, rotations);
	while (state.b)
		state = push_a(state);
	return state;

}

