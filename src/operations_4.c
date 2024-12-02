/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:02/39 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/02 09:02:39 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

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
