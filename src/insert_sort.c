/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 02:12/55 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/22 02:12:55 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

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

int	get_val_at_idx(t_state state, int idx, char stack)
{
	int		count;
	t_stack	*head;

	count = 0;
	if (stack == 'a')
		head = state.a;
	else
		head = state.b;
	while (count++ < idx)
		head = head->next;
	return (*(int *)(head->content));
}

int	max_rots(t_rotations rots)
{
	if (rots.rots == -1)
		return (rots.rev_rots);
	return (rots.rots);
}

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

int	get_amount_ops(t_state state, int pos)
{
	int			pos_in_b;
	t_rotations	rots_in_a;
	t_rotations	rots_in_b;

	pos_in_b = get_pos_in_b(state, get_val_at_idx(state, pos, 'a'));
	rots_in_a = get_nbr_of_rots(state, pos, 'a');
	rots_in_b = get_nbr_of_rots(state, pos_in_b, 'b');
	return (max_rots(rots_in_a) + max_rots(rots_in_b) + 1);
}

int	get_min_amount_pos(t_state state)
{
	int		pos;
	int		min_amount;
	int		min_amount_pos;
	t_stack	*head;
	int		amount;

	pos = 0;
	min_amount = get_amount_ops(state, pos);
	min_amount_pos = 0;
	head = state.a;
	while (head)
	{
		amount = get_amount_ops(state, pos);
		if (amount < min_amount)
		{
			min_amount = amount;
			min_amount_pos = pos;
		}
		head = head->next;
		pos++;
	}
	return (min_amount_pos);
}

t_state	insert_new_val(t_state state)
{
	int			min_amount_pos;
	int			min_amount_val;
	int			pos_in_b;
	t_rotations	rots_a;
	t_rotations	rots_b;
	int			min_rev_rots;
	int			min_rots;

	min_amount_pos = get_min_amount_pos(state);
	min_amount_val = get_val_at_idx(state, min_amount_pos, 'a');
	pos_in_b = get_pos_in_b(state, min_amount_val);
	rots_a = get_nbr_of_rots(state, min_amount_pos, 'a');
	rots_b = get_nbr_of_rots(state, pos_in_b, 'b');
	if (rots_a.rots == -1 && rots_b.rots == -1)
	{
		min_rev_rots = rots_a.rev_rots;
		if (rots_a.rev_rots > rots_b.rev_rots)
			min_rev_rots = rots_b.rev_rots;
		state = reverse_rotate_n_times(state, min_rev_rots, 'r');
		if (rots_a.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_a.rev_rots
					- min_rev_rots, 'a');
		if (rots_b.rev_rots > min_rev_rots)
			state = reverse_rotate_n_times(state, rots_b.rev_rots
					- min_rev_rots, 'b');
	}
	else if (rots_a.rev_rots == -1 && rots_b.rev_rots == -1)
	{
		min_rots = rots_a.rots;
		if (rots_a.rots > rots_b.rots)
			min_rots = rots_b.rots;
		state = rotate_n_times(state, min_rots, 'r');
		if (rots_a.rots > min_rots)
			state = rotate_n_times(state, rots_a.rots - min_rots, 'a');
		if (rots_b.rots > min_rots)
			state = rotate_n_times(state, rots_b.rots - min_rots, 'b');
	}
	else
	{
		if (rots_a.rots == -1)
			state = reverse_rotate_n_times(state, rots_a.rev_rots, 'a');
		state = rotate_a_n_times(state, rots_a.rots);
		if (rots_b.rots == -1)
			state = reverse_rotate_n_times(state, rots_b.rev_rots, 'b');
		state = rotate_b_n_times(state, rots_b.rots);
	}
	return (push_b(state));
}

t_state	rotate_to_max_in_b(t_state state)
{
	int			max_idx;
	t_rotations	rots;

	max_idx = find_idx_of_max(state);
	rots = get_nbr_of_rots(state, max_idx, 'b');
	if (rots.rots == -1)
		return (reverse_rotate_n_times(state, rots.rev_rots, 'b'));
	return (rotate_b_n_times(state, rots.rots));
}

t_state	push_b_to_a(t_state state)
{
	while (state.b)
		state = push_a(state);
	return (state);
}

t_state	insert_sort(t_state state)
{
	if (state.size_a < 2)
		return (state);
	if (state.size_a == 2)
		return (sort_top_of_stack(state, 'a'));
	state = push_b(state);
	state = push_b(state);
	while (state.a)
		state = insert_new_val(state);
	state = rotate_to_max_in_b(state);
	return (push_b_to_a(state));
}
