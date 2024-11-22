/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:51/34 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/22 02:51:34 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

t_rotations	get_nbr_of_rots(t_state state, int idx, char stack)
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

int	find_idx_of_min(t_state state)
{
	int		count;
	t_stack	*head;
	int		min_val;
	int		min_idx;

	count = 0;
	head = state.b;
	min_val = *(int *)(head->content);
	min_idx = 0;
	while (head)
	{
		if (*(int *)(head->content) < min_val)
		{
			min_val = *(int *)(head->content);
			min_idx = count;
		}
		head = head->next;
		count++;
	}
	return (min_idx);
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
	rots = get_nbr_of_rots(state, max_idx, 'b');
	if (rots.rots == -1)
		return (reverse_rotate_n_times(state, rots.rev_rots, 'b'));
	return (rotate_n_times(state, rots.rots, 'b'));
}

int	get_pos_in_b(t_state state, int val)
{
	t_stack	*head;
	int		count;
	int		inf;
	int		inf_idx;
	int		head_val;

	head = state.b;
	count = 0;
	inf = val;
	inf_idx = -1;
	while (head)
	{
		head_val = *(int *)(head->content);
		if (head_val < val && (inf == val || head_val > inf))
		{
			inf = head_val;
			inf_idx = count;
		}
		head = head->next;
		count++;
	}
	if (inf_idx == -1)
		return (1 + find_idx_of_min(state));
	return (inf_idx);
}
