/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:29/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/20 09:29:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

t_state	sort_top_of_stack_ascending(t_state state, char stack)
{
	if (stack == 'a')
	{
		if (is_seq(state.a->next->content, state.a->content))
			return (swap(state, 'a'));
	}
	else if (stack == 'b')
	{
		if (is_seq(state.b->next->content, state.b->content))
			return (swap(state, 'b'));
	}
	return (state);
}

/* total of 12 ops maximum */
/* would be less than 5 * log_2_5 = 5 * 2.3 = 11.5  */
t_state	sort_five_elements(t_state state)
{
	int	count_rots;

	state = push_b(state);
	state = push_b(state);
	state = sort_three_elements(state);
	state = sort_top_of_stack_ascending(state, 'b');
	count_rots = 0;
	while (count_rots < 5)
	{
		if (state.b && is_seq(state.b->content, state.a->content))
			state = push_a(state);
		if (state.b && state.b->next && count_rots == 3)
			state = push_a(state);
		if (state.b && count_rots == 4)
			state = push_a(state);
		state = rotate(state, 'a');
		count_rots++;
	}
	return (state);
}

/* sorts the elements in a */
/* supposes that a has 4 elements */
/* maximum of 6 operations*/
t_state	sort_four_elements(t_state state)
{
	int	count;

	state = push_b(state);
	state = sort_three_elements(state);
	if (is_seq(state.a->next->next->content, state.b->content))
	{
		state = push_a(state);
		state = rotate(state, 'a');
		return (state);
	}
	count = 0;
	while (is_seq(state.a->content, state.b->content))
	{
		state = rotate(state, 'a');
		count++;
	}
	state = push_a(state);
	while (count > 0)
	{
		state = reverse_rotate(state, 'a');
		count--;
	}
	return (state);
}

/* sorts the elements in a */
/* supposes that a has 3 elements */
/* maximum of 2 operations*/
t_state	sort_three_elements(t_state state)
{
	void	*first;
	void	*second;
	void	*third;

	first = state.a->content;
	second = state.a->next->content;
	third = state.a->next->next->content;
	if (is_seq(second, first) && is_seq(first, third))
		return (swap(state, 'a'));
	if (is_seq(first, third) && is_seq(third, second))
	{
		state = swap(state, 'a');
		return (rotate(state, 'a'));
	}
	if (is_seq(third, second) && is_seq(first, second))
		return (reverse_rotate(state, 'a'));
	if (is_seq(second, third) && is_seq(third, first))
		return (rotate(state, 'a'));
	if (is_seq(third, second) && is_seq(second, first))
	{
		state = rotate(state, 'a');
		return (swap(state, 'a'));
	}
	return (state);
}
