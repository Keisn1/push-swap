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

int	get_pos_of_entry_with_min_amount_of_ops(t_state state)
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
	int			pos_of_entry_with_min_amount_of_ops;
	int			val_of_entry_with_min_amount_of_ops;
	int			pos_in_b;
	t_rotations	rots_a;
	t_rotations	rots_b;
	int			min_rev_rots;
	int			min_rots;

	pos_of_entry_with_min_amount_of_ops = get_pos_of_entry_with_min_amount_of_ops(state);
	val_of_entry_with_min_amount_of_ops = get_val_at_pos(state, pos_of_entry_with_min_amount_of_ops, 'a');
	pos_in_b = get_pos_in_b(state, val_of_entry_with_min_amount_of_ops);
	rots_a = get_nbr_of_rots(state, pos_of_entry_with_min_amount_of_ops, 'a');
	rots_b = get_nbr_of_rots(state, pos_in_b, 'b');
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
	return (push_b(state));
}


t_state	insert_sort(t_state state)
{
	if (state.size_a < 2)
		return (state);
	if (state.size_a == 2)
		return (sort_top_of_stack(state, 'a'));
	state = push_b(state);
	state = push_b(state);
	while (state.a)
		state = insert_new_val(state);
	state = rotate_to_max_in_b(state);
	return (push_b_to_a(state));
}
