/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 10:01/55 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/20 10:01:55 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft.h"

typedef t_list	t_stack;

typedef struct s_state
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;
	int			size_b;
}				t_state;

typedef struct s_rotations
{
	int			rots;
	int			rev_rots;
}				t_rotations;

# ifdef __cplusplus

extern "C"
{
# endif

/* swapping */
t_stack * swap_stack(t_stack * head);
t_state			swap(t_state state, char s);

/* pushing */
t_state			push_a(t_state state);
t_state			push_b(t_state state);

/* rotating */
t_stack			*rot_stack(t_stack *stack);
t_state			rotate(t_state state, char s);
t_state			rotate_n_times(t_state state, int n, char stack);

/* reverse rotating */
t_stack			*rev_rot_stack(t_stack *stack);
t_state			reverse_rotate(t_state state, char s);
t_state			reverse_rotate_n_times(t_state state, int n, char stack);

/* sort top of stack */
t_state			sort_top_of_stack_ascending(t_state state, char stack);

/* rotation helper */
int				max_rots(t_rotations rots);
t_rotations		get_nbr_of_rots(t_state state, int idx, char stack);
t_state			rotate_both(t_state state, int rots_a, int rots_b);
t_state			reverse_rotate_both(t_state state, int rev_rots_a,
					int rev_rots_b);
t_state			rotate_to_correct_positions(t_state state, t_rotations rots_a,
					t_rotations rots_b);

#  ifdef __cplusplus

}
#  endif

# endif // OPERATIONS_H
