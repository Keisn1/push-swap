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
			state = reverse_rotate(state, 'a');
		return state;
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'b');
		return state;
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'r');
		return state;
	}
	return state;
}

t_state	reverse_rotate_a_n_times(t_state state, int n)
{
	int	count;

	/* rotate to the beginning */
	count = 0;
	while (count++ < n)
		state = reverse_rotate(state, 'a');
	return state;
}

t_state	reverse_rotate_b_n_times(t_state state, int n)
{
	int	count;

	/* rotate to the beginning */
	count = 0;
	while (count++ < n)
		state = reverse_rotate(state, 'b');
	return state;
}

t_state	rotate_n_times(t_state state, int n, char stack)
{
	int	count;

	if (stack == 'a')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'a');
		return state;
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'b');
		return state;
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'r');
		return state;
	}
	return state;
}

t_state	rotate_a_n_times(t_state state, int n)
{
	int	count;

	/* rotate to the beginning */
	count = 0;
	while (count++ < n)
		state = rotate(state, 'a');
	return state;
}

t_state	rotate_b_n_times(t_state state, int n)
{
	int	count;

	/* rotate to the beginning */
	count = 0;
	while (count++ < n)
		state = rotate(state, 'b');
	return state;
}
