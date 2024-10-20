/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:15/18 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/11 17:15:18 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

typedef t_list t_stack;

typedef struct s_state {
	t_stack *a;
	t_stack *b;
	int size_a;
	int size_b;
	int max_b;
	int min_b;
} t_state;

# ifdef __cplusplus

extern "C"
{
# endif

	bool is_seq(void *a, void *b);
	void	push_swap(int argc , char* argv[]);
	t_state sort_three_elements(t_state state);
	t_state sort_three_elements_with_tail(t_state state);
	t_state sort_four_elements(t_state state);
	t_state sort_four_elements_with_tail(t_state state);
	t_state sort_five_elements(t_state state);
	t_state sort_five_elements_with_tail(t_state state, bool with_backing_up);
	t_state partially_sort_with_five(t_state state, int size);

	/* merge sort */
	t_state merge_rest(t_state state, int size, int size_of_rest);
	t_state merge_two_chunks(t_state state, int size_of_chunk, bool with_backing_up);

	t_state put_ascending_a_in_b_ascending(t_state state, int size);
	t_state put_ascending_tail_of_a_in_b_ascending(t_state state, int length_tail);
	t_state merge_ascending_b_into_ascending_a(t_state state, int length_sorted_in_a);
    t_state merge_sort(t_state state, int size);

	/* insert_sort */
    t_state insert_sort(t_state state);
	t_state insert_new_val(t_state state);
    int get_amount_ops(t_state state, int idx);

	/* heap_sort */
	t_state sift_down(t_state state, int root, int size);

	/* helpers */
	void print_stack(t_stack *a);

# ifdef __cplusplus
}
# endif

#endif // PUSH_SWAP_H
