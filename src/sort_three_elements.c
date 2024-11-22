/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:47/40 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 15:47:40 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

/* maximum of 5 operations */
t_state	sort_three_elements_with_tail(t_state state)
{
	void	*first;
	void	*second;
	void	*third;

	first = state.a->content;
	second = state.a->next->content;
	third = state.a->next->next->content;
	if (leq(second, first) && leq(first, third))
		return (swap(state, 'a'));
	if (leq(first, third) && leq(third, second))
	{
		state = rotate(state, 'a');
		state = swap(state, 'a');
		return (reverse_rotate(state, 'a'));
	}
	if (leq(third, second) && leq(first, second))
	{
		state = rotate(state, 'a');
		state = swap(state, 'a');
		state = reverse_rotate(state, 'a');
		return (swap(state, 'a'));
	}
	if (leq(second, third) && leq(third, first))
	{
		state = swap(state, 'a');
		state = rotate(state, 'a');
		state = swap(state, 'a');
		return (reverse_rotate(state, 'a'));
	}
	if (leq(third, second) && leq(second, first))
	{
		state = swap(state, 'a');
		state = rotate(state, 'a');
		state = swap(state, 'a');
		state = reverse_rotate(state, 'a');
		return (swap(state, 'a'));
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
	if (leq(second, first) && leq(first, third))
		return (swap(state, 'a'));
	if (leq(first, third) && leq(third, second))
	{
		state = swap(state, 'a');
		return (rotate(state, 'a'));
	}
	if (leq(third, second) && leq(first, second))
		return (reverse_rotate(state, 'a'));
	if (leq(second, third) && leq(third, first))
		return (rotate(state, 'a'));
	if (leq(third, second) && leq(second, first))
	{
		state = rotate(state, 'a');
		return (swap(state, 'a'));
	}
	return (state);
}
