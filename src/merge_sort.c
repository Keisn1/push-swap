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

t_state	merge_sort(t_state state, int size)
{
	int	count;
	int	size_of_chunk;
	int	rest;

	size_of_chunk = 5;
	rest = size % size_of_chunk;
	state = partially_sort_with_five(state, size);
	state = merge_two_chunks(state, size_of_chunk, false);

	print_stack(state.a);
	if ((size - 2*size_of_chunk) > rest) {
		count = 0;
		while (count++ < size_of_chunk) {
			state = rotate(state, 'a');
		}
	}

	count = 0;
	while (count++ < rest)
		state = rotate(state, 'a');


	state = merge_rest(state, size);
	return (state);
}
