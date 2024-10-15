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

/* maximum of 2*(length(state_a)-1) + 1 */
t_state insert_non_max(t_state state) {
	int count = 0;
	while (is_seq(state.a->content,state.b->content)) {
		state = rotate(state, 'a');
		count++;
	}
	state = push_a(state);
	while (count > 0) {
		state = reverse_rotate(state, 'a');
		count--;
	}
	return state;
}

/* t_state sort_five_elements(t_state state) { */
/* 	/\* 2 operations *\/ */
/* 	state = push_b(state); */
/* 	state = push_b(state); */

/* 	/\* plus 1 operation *\/ */
/* 	if (is_seq(state.b->content, state.b->next->content)) { */
/* 		state = swap(state, 'b'); */
/* 	} */

/* 	/\* plus maximum of 2 operations *\/ */
/* 	state = sort_three_elements(state); */

/* 	/\* plus 3 operations *\/ */
/* 	if (is_seq(state.a->next->next->content, state.b->content)) { */
/* 		state = push_a(state); */
/* 		state = rotate(state, 'a'); */
/* 		return insert_non_max(state); */
/* 	} */
/* 	state = insert_non_max(state); */
/* 	return insert_non_max(state); */
/* } */

t_state sort_five_elements(t_state state) {
	/* 2 operations */
	state = push_b(state);
	state = push_b(state);

	/* plus 1 operation */
	if (is_seq(state.b->content, state.b->next->content)) {
		state = swap(state, 'b');
	}

	/* plus maximum of 2 operations */
	state = sort_three_elements(state);

	/* plus 3 operations */
	if (is_seq(state.a->next->next->content, state.b->content)) {
		state = push_a(state);
		state = rotate(state, 'a');
		return insert_non_max(state);
	}
	state = insert_non_max(state);
	return insert_non_max(state);
}
