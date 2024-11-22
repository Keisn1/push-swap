/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:14/26 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/16 20:14:26 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

int	get_content_by_idx(t_stack *head, int idx)
{
	int	count;

	count = 0;
	while (count++ < idx)
	{
		head = head->next;
	}
	return (*(int *)head->content);
}

void	update_child(int *child_idx, int *child, int size, t_stack *head)
{
	int	right_child;

	if ((*child_idx + 1) < size)
	{
		right_child = get_content_by_idx(head, (*child_idx) + 1);
		if (*child < right_child)
		{
			*child_idx = (*child_idx) + 1;
			*child = right_child;
		}
	}
}

t_state	sift_operation(t_state state, int child_idx)
{
	state = push_a(state);
	state = rotate_b_n_times(state, child_idx - 1);
	state = push_a(state);
	state = swap(state, 'a');
	state = push_b(state);
	state = reverse_rotate_b_n_times(state, child_idx - 1);
	state = push_b(state);
	return (state);
}

t_state	sift_down(t_state state, int root, int size)
{
	int	left_child_idx;
	int	left_child;
	int	child_idx;
	int	child;

	if (size <= 1)
		return (state);
	left_child_idx = 2 * root + 1;
	if (left_child_idx >= size)
	{
		return (state);
	}
	left_child = get_content_by_idx(state.b, left_child_idx);
	child_idx = left_child_idx;
	child = left_child;
	update_child(&child_idx, &child, size, state.b);
	if (leq(state.b->content, &child))
		state = sift_operation(state, child_idx);
	return (state);
}
