/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:10/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 17:10:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

t_state	merge_two_chunks(t_state state, int size_of_chunk, bool with_backing_up)
{
	state = put_ascending_a_in_b_ascending(state, size_of_chunk);
	state = merge_ascending_b_into_ascending_a(state, size_of_chunk);
	if (with_backing_up)
		state = reverse_rotate_a_n_times(state, 2 * size_of_chunk);
	return (state);
}

t_state	merge_rest(t_state state, int size)
{
	int	rest;

	rest = size % 5;
	state = put_ascending_tail_of_a_in_b_ascending(state, rest);
	state = merge_ascending_b_into_ascending_a(state, size - rest);
	return (state);
}

t_state	merge_ascending_b_into_ascending_a(t_state state,
		int length_sorted_in_a)
{
	int	count;

	count = 0;
	while (state.b)
	{
		if (is_seq(state.b->content, state.a->content)
			|| count >= length_sorted_in_a)
		{
			state = push_a(state);
			state = rotate(state, 'a');
			continue ;
		}
		state = rotate(state, 'a');
		count++;
	}
	state = rotate_a_n_times(state, length_sorted_in_a - count);
	return (state);
}

t_state	put_ascending_a_in_b_ascending(t_state state, int size)
{
	int	count;

	count = 0;
	while (count++ < size)
	{
		state = push_b(state);
		state = rotate(state, 'b');
	}
	return (state);
}

t_state	put_ascending_tail_of_a_in_b_ascending(t_state state, int length_tail)
{
	int	count;

	count = 0;
	count = 0;
	while (count++ < length_tail)
	{
		state = reverse_rotate(state, 'a');
		state = push_b(state);
	}
	return (state);
}
