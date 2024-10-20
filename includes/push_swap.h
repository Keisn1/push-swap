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

# include "operations.h"

# ifdef __cplusplus

extern "C"
{
# endif


	void	push_swap(int argc , char* argv[]);

	/* sort less than 6 */
	t_state sort_three_elements(t_state state);
	t_state sort_four_elements(t_state state);
	t_state sort_five_elements(t_state state);

	/* insert_sort */
    t_state insert_sort(t_state state);
	t_state insert_new_val(t_state state);
    int get_amount_ops(t_state state, int idx);

	/* helpers */
	int get_val_at_idx(t_state state, int idx, char stack);
	bool is_seq(void *a, void *b);
	t_state push_b_to_a(t_state state);
	int find_idx_of_max(t_state state);
	int find_idx_of_min(t_state state);
	int get_idx_of_val_in_b(t_state state, int val);
	void print_stack(t_stack *a);

# ifdef __cplusplus
}
# endif

#endif // PUSH_SWAP_H
