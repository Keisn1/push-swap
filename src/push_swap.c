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

t_stack	*create_stack(int len, int *nbrs)
{
	int		*x;
	t_stack	*stack;
	int		i;
	t_stack	*new;

	x = (int *)malloc(sizeof(int));
	if (!x)
		return (NULL);
	*x = nbrs[0];
	stack = ft_lstnew(x);
	i = 1;
	while (i < len)
	{
		x = (int *)malloc(sizeof(int));
		*x = nbrs[i];
		new = ft_lstnew(x);
		if (!new)
		{
			free(x);
			ft_lstclear(&stack, free);
			return (NULL);
		}
		ft_lstadd_back(&stack, new);
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
