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
	t_state merge_rest(t_state state, int size);

# ifdef __cplusplus
}
# endif

#endif // PUSH_SWAP_H
