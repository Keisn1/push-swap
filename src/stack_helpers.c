/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:41/05 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/19 13:41:05 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int get_idx_of_val_in_b(t_state state, int val) {
	t_stack *head = state.b;
	int count = 0;
	int inf = val;
	int inf_idx = -1;
	while (head) {
		int head_val = *(int*)(head->content);
		if (head_val < val && (inf == val || head_val > inf)) {
			inf = head_val;
			inf_idx = count;
		}
		head = head->next;
		count++;
	}

	if (inf_idx == -1)
		return 1 + find_idx_of_min(state);

	return inf_idx;
}
