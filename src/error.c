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

bool check_no_duplicates(int *nbrs, int len) {
	if (len > 1) {
		int c1 = 0;
		while (c1 < len - 1) {
			int c2 = c1 + 1;
			while (c2 < len) {
				if (nbrs[c1] == nbrs[c2++])
					return false;
			}
			c1++;
		}
	}
	return true;
}
