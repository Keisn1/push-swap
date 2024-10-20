/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:40/22 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/20 09:40:22 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

int	get_amount_ops(t_state state, int idx)
{
	int			idx_in_b;
	t_rotations	rots_in_a;
	t_rotations	rots_in_b;

	idx_in_b = get_idx_of_val_in_b(state, get_val_at_idx(state, idx, 'a'));
	rots_in_a = get_nbr_of_rots(state, idx, 'a');
	rots_in_b = get_nbr_of_rots(state, idx_in_b, 'b');
	return (max_rots(rots_in_a) + max_rots(rots_in_b) + 1);
}

int	get_idx_with_least_amount_ops(t_state state)
{
	int		idx;
	int		min_amount;
	int		min_amount_pos;
	t_stack	*head;
	int		amount;

	idx = 0;
	min_amount = get_amount_ops(state, idx);
	min_amount_pos = 0;
	head = state.a;
	while (head)
	{
		amount = get_amount_ops(state, idx);
		if (amount < min_amount)
		{
			min_amount = amount;
			min_amount_pos = idx;
		}
		head = head->next;
		idx++;
	}
	return (min_amount_pos);
}

t_state	rotate_to_correct_positions(t_state state, t_rotations rots_a,
		t_rotations rots_b)
{
	int	min_rev_rots;
	int	min_rots;

	if (rots_a.rots == -1 && rots_b.rots == -1)
	{
		min_rev_rots = rots_a.rev_rots;
		if (rots_a.rev_rots > rots_b.rev_rots)
			min_rev_rots = rots_b.rev_rots;
		state = reverse_rotate_n_times(state, min_rev_rots, 'r');
		if (rots_a.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_a.rev_rots
					- min_rev_rots, 'a');
		if (rots_b.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_b.rev_rots
					- min_rev_rots, 'b');
	}
	else if (rots_a.rev_rots == -1 && rots_b.rev_rots == -1)
	{
		min_rots = rots_a.rots;
		if (rots_a.rots > rots_b.rots)
			min_rots = rots_b.rots;
		state = rotate_n_times(state, min_rots, 'r');
		if (rots_a.rots > min_rots)
			state = rotate_n_times(state, rots_a.rots - min_rots, 'a');
		if (rots_b.rots > min_rots)
			state = rotate_n_times(state, rots_b.rots - min_rots, 'b');
	}
	else
	{
		if (rots_a.rots == -1)
			state = reverse_rotate_n_times(state, rots_a.rev_rots, 'a');
		state = rotate_n_times(state, rots_a.rots, 'a');
		if (rots_b.rots == -1)
			state = reverse_rotate_n_times(state, rots_b.rev_rots, 'b');
		state = rotate_n_times(state, rots_b.rots, 'b');
	}
	return (state);
}

t_state	insert_new_val(t_state state)
{
	int			idx_with_least_amount_ops;
	int			val_with_least_amount_ops;
	int			correct_idx_in_b;
	t_rotations	rots_a;
	t_rotations	rots_b;

	idx_with_least_amount_ops = get_idx_with_least_amount_ops(state);
	val_with_least_amount_ops = get_val_at_idx(state, idx_with_least_amount_ops,
			'a');
	correct_idx_in_b = get_idx_of_val_in_b(state, val_with_least_amount_ops);
	rots_a = get_nbr_of_rots(state, idx_with_least_amount_ops, 'a');
	rots_b = get_nbr_of_rots(state, correct_idx_in_b, 'b');
	state = rotate_to_correct_positions(state, rots_a, rots_b);
	return (push_b(state));
}

t_state	rotate_to_max_in_b(t_state state)
{
	int			max_idx;
	t_rotations	rots;

	max_idx = find_idx_of_max(state);
	rots = get_nbr_of_rots(state, max_idx, 'b');
	if (rots.rots == -1)
		return (reverse_rotate_n_times(state, rots.rev_rots, 'b'));
	return (rotate_n_times(state, rots.rots, 'b'));
}

t_state	insert_sort(t_state state)
{
	if (state.size_a < 2)
		return (state);
	if (state.size_a == 2)
		return (sort_top_of_stack_ascending(state, 'a'));
	state = push_b(state);
	state = push_b(state);
	while (state.a)
		state = insert_new_val(state);
	state = rotate_to_max_in_b(state);
	return (push_b_to_a(state));
}
