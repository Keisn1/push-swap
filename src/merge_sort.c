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

#include "libft.h"
#include "operations.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>


t_state	merge_chunk_into_it_with_tail(t_state state, int length_sorted_in_a, int size_of_chunk, int rest)
{
	state = put_ascending_a_in_b_ascending(state, size_of_chunk);
	state = rotate_a_n_times(state, rest);
	state = merge_ascending_b_into_ascending_a(state, length_sorted_in_a);
	return (state);
}

t_state	merge_sort(t_state state, int size)
{
	int	size_of_chunk;
	int	size_of_rest;

	size_of_chunk = 5;
	size_of_rest = size % size_of_chunk;
	state = partially_sort_with_five(state, size);

	int end_idx = 0;
	while (((2*size_of_chunk)) <= size) {
		end_idx = 0;
		while ((size - end_idx) >= 2*size_of_chunk) {
			state = merge_two_chunks(state, size_of_chunk, false);
			end_idx += 2*size_of_chunk;
		}
		size_of_chunk *= 2;
		if ((2*size_of_chunk) < size) {
			state = rotate_a_n_times(state, size-end_idx);
		}
	}

	while ((size - end_idx) > size_of_rest) {
		while ((size - end_idx) < size_of_chunk /2) {
			size_of_chunk /= 2;
		}
		state = merge_chunk_into_it_with_tail(state, end_idx, size_of_chunk/2, size-end_idx-(size_of_chunk/2));
		end_idx += (size_of_chunk/2);
		size_of_chunk /= 2;
	}

	state = rotate_a_n_times(state, size_of_rest);
	state = merge_rest(state, size, size_of_rest);
	return state;
}
