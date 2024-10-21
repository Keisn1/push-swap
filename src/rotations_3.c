/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:29/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/20 09:29:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	max_rots(t_rotations rots)
{
	if (rots.rots == -1)
		return (rots.rev_rots);
	return (rots.rots);
}

t_rotations	get_nbr_of_rots(t_state state, int idx, char stack)
{
	int			size;
	t_rotations	rots;

	size = state.size_a;
	if (stack == 'b')
		size = state.size_b;
	rots = (t_rotations){-1, -1};
	if ((size - idx) < idx)
		rots.rev_rots = size - idx;
	else
		rots.rots = idx;
	return (rots);
}

t_state	rotate_both(t_state state, int rots_a, int rots_b)
{
	int	min_rots;

	min_rots = rots_a;
	if (rots_a > rots_b)
		min_rots = rots_b;
	state = rotate_n_times(state, min_rots, 'r');
	if (rots_a > min_rots)
		state = rotate_n_times(state, rots_a - min_rots, 'a');
	if (rots_b > min_rots)
		state = rotate_n_times(state, rots_b - min_rots, 'b');
	return (state);
}

t_state	reverse_rotate_both(t_state state, int rev_rots_a, int rev_rots_b)
{
	int	min_rev_rots;

	min_rev_rots = rev_rots_a;
	if (rev_rots_a > rev_rots_b)
		min_rev_rots = rev_rots_b;
	state = reverse_rotate_n_times(state, min_rev_rots, 'r');
	if (rev_rots_a > min_rev_rots)
		state = reverse_rotate_n_times(state, rev_rots_a - min_rev_rots, 'a');
	if (rev_rots_b > min_rev_rots)
		state = reverse_rotate_n_times(state, rev_rots_b - min_rev_rots, 'b');
	return (state);
}

t_state	rotate_to_correct_positions(t_state state, t_rotations rots_a,
		t_rotations rots_b)
{
	if (rots_a.rots == -1 && rots_b.rots == -1)
		state = reverse_rotate_both(state, rots_a.rev_rots, rots_b.rev_rots);
	else if (rots_a.rev_rots == -1 && rots_b.rev_rots == -1)
		state = rotate_both(state, rots_a.rots, rots_b.rots);
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
