/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 09:29/49 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/20 09:29:49 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

int	max_rots(t_rotations rots)
{
	if (rots.rots == -1)
		return (rots.rev_rots);
	return (rots.rots);
}

t_rotations	get_nbr_of_rots(t_state state, int idx, char stack)
{
	int			size;
	t_rotations	rots;

	size = state.size_a;
	if (stack == 'b')
		size = state.size_b;
	rots = (t_rotations){-1, -1};
	if ((size - idx) < idx)
		rots.rev_rots = size - idx;
	else
		rots.rots = idx;
	return (rots);
}
