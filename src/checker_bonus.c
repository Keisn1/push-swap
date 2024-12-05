/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:40/10 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/05 07:40:10 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <unistd.h>

void	check_ordered(t_state state)
{
	if (is_ordered(state))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
}

bool	validate_op(const char *op)
{
	if (!ft_strncmp(op, "sa", ft_strlen(op)))
		return (true);
	else if (!ft_strncmp(op, "sb", 3))
		return (true);
	else if (!ft_strncmp(op, "ss", 3))
		return (true);
	else if (!ft_strncmp(op, "pa", 3))
		return (true);
	else if (!ft_strncmp(op, "pb", 3))
		return (true);
	else if (!ft_strncmp(op, "ra", 3))
		return (true);
	else if (!ft_strncmp(op, "rb", 3))
		return (true);
	else if (!ft_strncmp(op, "rr", 3))
		return (true);
	else if (!ft_strncmp(op, "rra", 3))
		return (true);
	else if (!ft_strncmp(op, "rrb", 3))
		return (true);
	else if (!ft_strncmp(op, "rrr", 3))
		return (true);
	return (false);
}

bool	validate_input(char **lines)
{
	char	**head;

	head = lines;
	while (*head)
	{
		if (!validate_op(*head))
			return (false);
		head++;
	}
	return (true);
}

char	*get_input_stdin(void)
{
	size_t	full_size;
	char	*input;
	char	*received;
	char	*tmp;

	full_size = 1;
	input = ft_get_empty_str(full_size);
	received = get_next_line(STDIN_FILENO, false);
	while (received)
	{
		full_size += ft_strlen(received);
		tmp = malloc(sizeof(char) * full_size);
		ft_strlcpy(tmp, input, full_size);
		free(input);
		input = tmp;
		tmp = NULL;
		if (ft_strlcat(input, received, full_size) >= full_size)
			return (NULL);
		free(received);
		received = get_next_line(STDIN_FILENO, false);
	}
	get_next_line(STDIN_FILENO, true);
	return (input);
}

t_state	do_ops(char **lines, t_state state)
{
	char	**head;
	char	*op;
	bool	print;

	head = lines;
	while (*head)
	{
		op = *head;
		head++;
		print = false;
		if (!ft_strncmp(op, "sa", 3))
			state = swap(state, 'a', print);
		else if (!ft_strncmp(op, "sb", 3))
			state = swap(state, 'b', print);
		else if (!ft_strncmp(op, "ss", 3))
		{
			state = swap(state, 'a', print);
			state = swap(state, 'b', print);
		}
		else if (!ft_strncmp(op, "pa", 3))
			state = push_a(state, print);
		else if (!ft_strncmp(op, "pb", 3))
			state = push_b(state, print);
		else if (!ft_strncmp(op, "ra", 3))
			state = rotate(state, 'a', print);
		else if (!ft_strncmp(op, "rb", 3))
			state = rotate(state, 'b', print);
		else if (!ft_strncmp(op, "rr", 3))
		{
			state = rotate(state, 'a', print);
			state = rotate(state, 'b', print);
		}
		else if (!ft_strncmp(op, "rra", 3))
			state = reverse_rotate(state, 'a', print);
		else if (!ft_strncmp(op, "rrb", 3))
			state = reverse_rotate(state, 'b', print);
		else if (!ft_strncmp(op, "rrr", 3))
		{
			state = reverse_rotate(state, 'a', print);
			state = reverse_rotate(state, 'b', print);
		}
	}
	return (state);
}
