/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 09:16/58 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/13 09:16:58 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_state	reverse_rotate_n_times(t_state state, int n, char stack)
{
	int	count;

	if (stack == 'a')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'a', true);
		return (state);
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'b', true);
		return (state);
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'r', true);
		return (state);
	}
	return (state);
}

t_state	rotate_n_times(t_state state, int n, char stack)
{
	int	count;

	if (stack == 'a')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'a', true);
		return (state);
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'b', true);
		return (state);
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'r', true);
		return (state);
	}
	return (state);
}

t_state	push_b_to_a(t_state state)
{
	while (state.b)
		state = push_a(state, true);
	return (state);
}
