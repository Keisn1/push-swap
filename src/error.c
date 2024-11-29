/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:50/28 by kfreyer           #+#    #+#             */
/*   Updated: 2024/11/29 15:50:28 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_char(char c)
{
	return (ft_isdigit(c) || c == ' ' || c == '-' || c == '+');
}

bool	check_valid_strs(int argc, char **argv)
{
	char	*str;
	int		count;

	count = 1;
	while (count < argc)
	{
		str = argv[count++];
		while (*str)
			if (!is_valid_char(*(str++)))
				return (false);
	}
	return (true);
}

int	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}
