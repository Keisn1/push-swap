/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:06/50 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/11 18:06:50 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

t_stack	*create_stack(int len, int *nbrs)
{
	int		*x;
	t_stack	*stack;
	int		i;

	x = (int *)malloc(sizeof(int));
	*x = nbrs[0];
	stack = ft_lstnew(x);
	i = 1;
	while (i < len)
	{
		x = (int *)malloc(sizeof(int));
		*x = nbrs[i];
		ft_lstadd_back(&stack, ft_lstnew(x));
		i++;
	}
	return (stack);
}

void	push_swap(int len, int *nbrs)
{
	t_stack	*a;
	t_state	state;

	a = create_stack(len, nbrs);
	state = (t_state){a, NULL, len, 0, 0, 0};
	state = insert_sort(state);
	ft_lstclear(&state.a, free);
}
