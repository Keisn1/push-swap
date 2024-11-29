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

# include "libft.h"
# include <unistd.h>

typedef t_list	t_stack;

typedef struct s_state
{
	t_stack		*a;
	t_stack		*b;
	int			size_a;
	int			size_b;
	int			max_b;
	int			min_b;
}				t_state;

typedef struct s_rotations
{
	int			rots;
	int			rev_rots;
}				t_rotations;

bool			leq(void *a, void *b);
void			push_swap(int len, int *nbrs);
t_state			sort_three_elements(t_state state);
t_state			sort_three_elements_with_tail(t_state state);
t_state			sort_four_elements(t_state state);
t_state			sort_four_elements_with_tail(t_state state);
t_state			sort_five_elements(t_state state);
t_state			sort_five_elements_with_tail(t_state state,
					bool with_backing_up);
t_state			partially_sort_with_five(t_state state, int size);

/* insert_sort */
t_state			insert_sort(t_state state);
t_state			insert_new_val(t_state state);
int				get_amount_ops(t_state state, int idx);
t_rotations		get_rotations(t_state state, int idx, char stack);
int				get_idx_in_b(t_state state, int val);
t_state			rotate_to_max_in_b(t_state state);
int				get_val_at_idx(t_state state, int idx, char stack);

/* helpers */
void			print_stack(t_stack *a);
int				*extract_nbrs(int argc, char **argv, int *len);

#endif // PUSH_SWAP_H
