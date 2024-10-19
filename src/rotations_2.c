/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:36/14 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/19 13:36:14 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

t_state	rotate_n_times(t_state state, int n, char stack)
{
	int	count;

	if (stack == 'a')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'a');
		return (state);
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'b');
		return (state);
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = rotate(state, 'r');
		return (state);
	}
	return (state);
}

t_state	reverse_rotate_n_times(t_state state, int n, char stack)
{
	int	count;

	if (stack == 'a')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'a');
		return (state);
	}
	if (stack == 'b')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'b');
		return (state);
	}
	if (stack == 'r')
	{
		count = 0;
		while (count++ < n)
			state = reverse_rotate(state, 'r');
		return (state);
	}
	return (state);
}
