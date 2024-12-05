/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:12/55 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/22 02:12:55 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

int	get_idx_min_amount_ops(t_state state)
{
	int		pos;
	int		min_amount_of_ops;
	int		min_amount_pos;
	t_stack	*head;
	int		amount;

	pos = 0;
	min_amount_of_ops = get_amount_ops(state, pos);
	min_amount_pos = 0;
	head = state.a;
	while (head)
	{
		amount = get_amount_ops(state, pos);
		if (amount < min_amount_of_ops)
		{
			min_amount_of_ops = amount;
			min_amount_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (min_amount_pos);
}

t_state	insert_new_val(t_state state)
{
	int			idx_min_amount_ops;
	int			val_min_amount_ops;
	t_rotations	rots_a;
	t_rotations	rots_b;

	idx_min_amount_ops = get_idx_min_amount_ops(state);
	val_min_amount_ops = get_val_at_idx(state, idx_min_amount_ops, 'a');
	rots_a = get_rotations(state, idx_min_amount_ops, 'a');
	rots_b = get_rotations(state, get_idx_in_b(state, val_min_amount_ops), 'b');
	if (rots_a.rots == -1 && rots_b.rots == -1)
		state = reverse_rotate_both(state, rots_a.rev_rots, rots_b.rev_rots);
	else if (rots_a.rev_rots == -1 && rots_b.rev_rots == -1)
		state = rotate_both(state, rots_a.rots, rots_b.rots);
	else
	{
		if (rots_a.rots == -1)
			state = reverse_rotate_n_times(state, rots_a.rev_rots, 'a');
		else
			state = rotate_n_times(state, rots_a.rots, 'a');
		if (rots_b.rots == -1)
			state = reverse_rotate_n_times(state, rots_b.rev_rots, 'b');
		else
			state = rotate_n_times(state, rots_b.rots, 'b');
	}
	return (push_b(state, true));
}

t_state	insert_sort(t_state state)
{
	if (is_ordered(state))
		return (state);
	if (state.size_a == 2)
		return (sort_top_of_stack(state, 'a'));
	if (state.size_a == 3)
		return (sort_three_elements(state));
	if (state.size_a == 4)
		return (sort_four_elements(state));
	if (state.size_a == 5)
		return (sort_five_elements(state));
	state = push_b(state, true);
	state = push_b(state, true);
	while (state.a)
		state = insert_new_val(state);
	state = rotate_to_max_in_b(state);
	return (push_b_to_a(state));
}
