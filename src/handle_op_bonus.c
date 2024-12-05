/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_op_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:35/14 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/05 08:35:14 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

t_state	handle_swap(const char *op, t_state state)
{
	if (op[1] == 'a')
		state = swap(state, 'a', false);
	if (op[1] == 'b')
		state = swap(state, 'b', false);
	if (op[1] == 's')
	{
		state = swap(state, 'a', false);
		state = swap(state, 'b', false);
	}
	return (state);
}

t_state	handle_push(const char *op, t_state state)
{
	if (op[1] == 'a')
		state = push_a(state, false);
	if (op[1] == 'b')
		state = push_b(state, false);
	return (state);
}

t_state	handle_reverse_rotate(const char *op, t_state state)
{
	if (op[2] == 'a')
		state = reverse_rotate(state, 'a', false);
	if (op[2] == 'b')
		state = reverse_rotate(state, 'b', false);
	if (op[2] == 'r')
	{
		state = reverse_rotate(state, 'a', false);
		state = reverse_rotate(state, 'b', false);
	}
	return (state);
}

t_state	handle_rotate(const char *op, t_state state)
{
	if (op[1] == 'a')
		state = rotate(state, 'a', false);
	if (op[1] == 'b')
		state = rotate(state, 'b', false);
	if (op[1] == 'r')
	{
		state = rotate(state, 'a', false);
		state = rotate(state, 'b', false);
	}
	return (state);
}

t_state	do_ops(char **lines, t_state state)
{
	char	**head;
	char	*op;

	head = lines;
	while (*head)
	{
		op = *head;
		head++;
		if (op[0] == 's')
			state = handle_swap(op, state);
		if (op[0] == 'p')
			state = handle_push(op, state);
		if (op[0] == 'r')
		{
			if (ft_strlen(op) == 2)
				state = handle_rotate(op, state);
			else
				state = handle_reverse_rotate(op, state);
		}
	}
	return (state);
}
