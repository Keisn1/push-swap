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

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_putnbr_fd(*(int *)a->content, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		a = a->next;
	}
}

bool	leq(void *a, void *b)
{
	if (*(int *)a <= *(int *)b)
		return (true);
	return (false);
}
