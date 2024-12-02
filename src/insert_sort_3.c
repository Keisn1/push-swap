/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:55/29 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/22 02:55:29 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

int	max_rots(t_rotations rots)
{
	if (rots.rots == -1)
		return (rots.rev_rots);
	return (rots.rots);
}

int	get_amount_ops(t_state state, int pos)
{
	int			pos_in_b;
	t_rotations	rots_in_a;
	t_rotations	rots_in_b;

	pos_in_b = get_idx_in_b(state, get_val_at_idx(state, pos, 'a'));
	rots_in_a = get_rotations(state, pos, 'a');
	rots_in_b = get_rotations(state, pos_in_b, 'b');
	return (max_rots(rots_in_a) + max_rots(rots_in_b) + 1);
}

t_rotations	get_rotations(t_state state, int idx, char stack)
{
	int			size;
	t_rotations	rots;

	size = state.size_a;
	if (stack == 'b')
		size = state.size_b;
	rots = (t_rotations){-1, -1};
	if ((size - idx) < idx)
		rots.rev_rots = size - idx;
	else
		rots.rots = idx;
	return (rots);
}

int	find_idx_of_max(t_state state)
{
	int		count;
	t_stack	*head;
	int		max_val;
	int		max_idx;

	count = 0;
	head = state.b;
	max_val = *(int *)(head->content);
	max_idx = 0;
	while (head)
	{
		if (*(int *)(head->content) > max_val)
		{
			max_val = *(int *)(head->content);
			max_idx = count;
		}
		head = head->next;
		count++;
	}
	return (max_idx);
}

t_state	rotate_to_max_in_b(t_state state)
{
	int			max_idx;
	t_rotations	rots;

	max_idx = find_idx_of_max(state);
	rots = get_rotations(state, max_idx, 'b');
	if (rots.rots == -1)
		return (reverse_rotate_n_times(state, rots.rev_rots, 'b'));
	return (rotate_n_times(state, rots.rots, 'b'));
}
