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

t_state	back_up(t_state state, int times)
{
	int	count;

	count = 0;
	while (count++ < times)
		state = reverse_rotate(state, 'a');
	return (state);
}

t_state	merge_two_chunks(t_state state, int size_of_chunk, bool with_backing_up)
{
	int	count;

	count = 0;
	while (count++ < size_of_chunk)
	{
		state = push_b(state);
		state = rotate(state, 'b');
	}
	count = 0;
	while (state.b)
	{
		if (is_seq(state.b->content, state.a->content)
			|| count >= size_of_chunk)
		{
			state = push_a(state);
			state = rotate(state, 'a');
			continue ;
		}
		state = rotate(state, 'a');
		count++;
	}
	while (count++ < size_of_chunk)
		state = rotate(state, 'a');
	if (with_backing_up)
		state = back_up(state, 2 * size_of_chunk);
	return (state);
}

t_state	merge_rest(t_state state, int size)
{
	int	rest;
	int	count;

	rest = size % 5;
	count = 0;
	while (count++ < rest)
	{
		state = reverse_rotate(state, 'a');
		state = push_b(state);
	}
	count = 0;
	while (count < size)
	{
		if (state.b && (is_seq(state.b->content, state.a->content)
				|| (count >= size - rest)))
		{
			state = push_a(state);
			state = rotate(state, 'a');
			count++;
			continue ;
		}
		state = rotate(state, 'a');
		count++;
	}
	return (state);
}
