/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:35/43 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/05 08:35:43 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

bool	validate_swap(const char *op)
{
	if (ft_strlen(op) != 2)
		return (false);
	if (op[0] != 's')
		return (false);
	if (op[1] == 'a' || op[1] == 'b' || op[1] == 's')
		return (true);
	return (false);
}

bool	validate_reverse_rotate(const char *op)
{
	if (ft_strlen(op) != 3)
		return (false);
	if (op[0] != 'r' || op[1] != 'r')
		return (false);
	if (op[2] == 'a' || op[2] == 'b' || op[2] == 'r')
		return (true);
	return (false);
}

bool	validate_rotate(const char *op)
{
	if (ft_strlen(op) != 2)
		return (false);
	if (op[0] != 'r')
		return (false);
	if (op[1] == 'a' || op[1] == 'b' || op[1] == 'r')
		return (true);
	return (false);
}

bool	validate_push(const char *op)
{
	if (ft_strlen(op) != 2)
		return (false);
	if (op[0] != 'p')
		return (false);
	if (op[1] == 'a' || op[1] == 'b')
		return (true);
	return (false);
}

bool	validate_op(const char *op)
{
	if (ft_strlen(op) > 3 || ft_strlen(op) < 2)
		return (false);
	if (op[0] == 's')
		return (validate_swap(op));
	if (op[0] == 'p')
		return (validate_push(op));
	if (op[0] == 'r')
	{
		if (ft_strlen(op) == 2)
			return (validate_rotate(op));
		return (validate_reverse_rotate(op));
	}
	return (false);
}
