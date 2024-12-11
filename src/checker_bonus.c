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
#include "libft.h"

void	check_ordered(t_state state)
{
	if (is_ordered(state) && state.size_b == 0)
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
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
