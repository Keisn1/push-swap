/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 07:33/03 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/15 07:33:03 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_syntax_check(char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (-1);
	return (0);
}

int	check_range(char *str)
{
	long	res;

	res = ft_atoi_long(str);
	if (res > INT_MAX || res < INT_MIN)
		return (-1);
	return (0);
}

int	*extract_values(int length, char *str_vals[])
{
	int	*values;
	int	count;

	values = (int *)malloc(sizeof(int) * (length));
	if (!values)
		return (NULL);
	count = 0;
	while (count < length)
	{
		values[count] = ft_atoi(str_vals[count]);
		count++;
	}
	return (values);
}

int	check_for_doubles(int length, char *str_vals[])
{
	int	x;
	int	y;
	int	ret;
	int	*values;

	values = extract_values(length, str_vals);
	if (!values)
		return (-1);
	ret = 0;
	x = 0;
	while (x < (length - 1))
	{
		y = x + 1;
		while (y < length)
		{
			if (values[x] == values[y])
				ret = -1;
			y++;
		}
		x++;
	}
	free(values);
	return (ret);
}

int	check_errors(int argc, char *argv[])
{
	int		count;
	char	*str;

	count = 1;
	while (count < argc)
	{
		str = argv[count];
		if (atoi_syntax_check(str))
			return (-1);
		if (check_range(str))
			return (-1);
		count++;
	}
	if (check_for_doubles(argc - 1, argv + 1))
		return (-1);
	return (0);
}
