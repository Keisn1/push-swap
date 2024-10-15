/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:15/53 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 08:15:53 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

t_state sort_five_elements(t_state state) {
	/* 2 operations */
	state = push_b(state);
	state = push_b(state);

	/* plus maximum of 2 operations */
	state = sort_three_elements(state);

	/* plus maximum of 1 operation */
	state = sort_top_of_stack(state, 'b');

	/* plus 5 rotations */
	/* plus 2 swaps */
	int count_rots = 0;
	while (count_rots < 5) {
		if (state.b && is_seq(state.b->content, state.a->content))
			state = push_a(state);
		if (state.b && state.b->next && count_rots == 3)
			state = push_a(state);
		if (state.b && count_rots == 4)
			state = push_a(state);
		state = rotate(state, 'a');
		count_rots++;
	}
	/* total of 12 ops maximum */
	return state;
}
