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
	rots_in_a = get_nbr_of_rots(state, pos, 'a');
	rots_in_b = get_nbr_of_rots(state, pos_in_b, 'b');
	return (max_rots(rots_in_a) + max_rots(rots_in_b) + 1);
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
