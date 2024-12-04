/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:02/16 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/22 02:02:16 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "push_swap.h"

/* swapping */
t_stack	*swap_stack(t_stack *head);
t_state	swap(t_state state, char s, bool print);

/* pushing */
t_state	push_a(t_state state);
t_state	push_b(t_state state);
t_state	push_b_to_a(t_state state);

/* rotating */
t_stack	*rot_stack(t_stack *stack);
t_state	rotate(t_state state, char s, bool print);
t_state	rotate_a_n_times(t_state state, int n);
t_state	rotate_b_n_times(t_state state, int n);
t_state	rotate_n_times(t_state state, int n, char stack);
t_state	reverse_rotate_both(t_state state, int rev_rots_a, int rev_rots_b);
t_state	rotate_both(t_state state, int rots_a, int rots_b);

/* reverse rotating */
t_stack	*rev_rot_stack(t_stack *stack);
t_state	reverse_rotate(t_state state, char s, bool print);
t_state	reverse_rotate_a_n_times(t_state state, int n);
t_state	reverse_rotate_b_n_times(t_state state, int n);
t_state	reverse_rotate_n_times(t_state state, int n, char stack);

/* sort top of stack */
t_state	sort_top_of_stack(t_state state, char stack);

#endif // OPERATIONS_H
