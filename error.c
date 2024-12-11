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

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

bool	is_valid_str(char *str)
{
	if (!(ft_isdigit(*str) || *str == '-' || *str == '+'))
		return (false);
	if ((*str == '+' || *str == '-') && (ft_strlen(str) < 2))
		return (false);
	str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

bool	check_valid_one_string(char *str)
{
	char	**strs;
	char	**head;

	strs = ft_split(str, ' ');
	head = strs;
	while (*head)
	{
		if (!is_valid_str(*head))
		{
			free_strs(strs);
			return (false);
		}
		head++;
	}
	free_strs(strs);
	return (true);
}

bool	check_valid_strs(int argc, char **argv)
{
	int	count;

	if (argc == 2)
		return (check_valid_one_string(argv[1]));
	count = 1;
	while (count < argc)
	{
		if (!is_valid_str(argv[count++]))
			return (false);
	}
	return (true);
}

int	error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	return (EXIT_FAILURE);
}

bool	check_no_duplicates(int *nbrs, int len)
{
	int	c1;
	int	c2;

	if (len > 1)
	{
		c1 = 0;
		while (c1 < len - 1)
		{
			c2 = c1 + 1;
			while (c2 < len)
			{
				if (nbrs[c1] == nbrs[c2++])
					return (false);
			}
			c1++;
		}
	}
	return (true);
}
