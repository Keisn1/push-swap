/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:50/11 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/16 10:50:11 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"
#include <stdio.h>

t_state	merge_chunk_into_it_with_tail(t_state state, int length_sorted_in_a)
{
	int count = 0;
	while (state.b)
	{
		if (is_seq(state.b->content, state.a->content) || count >= length_sorted_in_a)
		{
			state = push_a(state);
			state = rotate(state, 'a');
			continue ;
		}
		state = rotate(state, 'a');
		count++;
	}
	while (count++<length_sorted_in_a) {
		state = rotate(state, 'a');
	}
	return (state);
}

t_state	merge_sort(t_state state, int size)
{
	int	count;
	int	size_of_chunk;
	int	rest;

	size_of_chunk = 5;
	rest = size % size_of_chunk;
	state = partially_sort_with_five(state, size);
	state = merge_two_chunks(state, size_of_chunk, false);

	if ((size - 2*size_of_chunk) > rest) {
		/* push the last chunk to b in ascending order*/
		count = 0;
		while (count++ < size_of_chunk) {
			state = push_b(state);
			state = rotate(state, 'b');
		}
		/* rotate to the beginning */
		count = 0;
		while (count++ < rest) {
			state = rotate(state, 'a');
		}
		state = merge_chunk_into_it_with_tail(state, 2*size_of_chunk);
	}
	/* print_stack(state.b); */

	count = 0;
	while (count++ < rest)
		state = rotate(state, 'a');


	state = merge_rest(state, size);
	return (state);
}

