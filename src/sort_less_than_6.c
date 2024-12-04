/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:15/53 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 08:15:53 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "push_swap.h"

/* total of 12 ops maximum */
/* would be less than 5 * log_2_5 = 5 * 2.3 = 11.5  */
t_state	sort_five_elements(t_state state)
{
	int	count_rots;

	state = push_b(state);
	state = push_b(state);
	state = sort_three_elements(state);
	state = sort_top_of_stack(state, 'b');
	count_rots = 0;
	while (count_rots < 5)
	{
		if (state.b && leq(state.b->content, state.a->content))
			state = push_a(state);
		if (state.b && state.b->next && count_rots == 3)
			state = push_a(state);
		if (state.b && count_rots == 4)
			state = push_a(state);
		state = rotate(state, 'a', true);
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
	if (leq(state.a->next->next->content, state.b->content))
	{
		state = push_a(state);
		state = rotate(state, 'a', true);
		return (state);
	}
	count = 0;
	while (leq(state.a->content, state.b->content))
	{
		state = rotate(state, 'a', true);
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
	if (leq(second, first) && leq(first, third))
		return (swap(state, 'a', true));
	if (leq(first, third) && leq(third, second))
	{
		state = swap(state, 'a', true);
		return (rotate(state, 'a', true));
	}
	if (leq(third, second) && leq(first, second))
		return (reverse_rotate(state, 'a'));
	if (leq(second, third) && leq(third, first))
		return (rotate(state, 'a', true));
	if (leq(third, second) && leq(second, first))
	{
		state = rotate(state, 'a', true);
		return (swap(state, 'a', true));
	}
	return (state);
}
