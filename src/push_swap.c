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

#include "push_swap.h"

t_stack	*create_stack(int argc, char *argv[])
{
	int		*x;
	t_stack	*stack;
	int		i;

	x = (int *)malloc(sizeof(int));
	*x = ft_atoi(argv[1]);
	stack = ft_lstnew(x);
	i = 2;
	while (i <= argc)
	{
		x = (int *)malloc(sizeof(int));
		*x = ft_atoi(argv[i]);
		ft_lstadd_back(&stack, ft_lstnew(x));
		i++;
	}
	return (stack);
}

void	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_state	state;

	a = create_stack(argc, argv);
	state = (t_state){a, NULL, 0, 0, 0, 0};
	state = insert_sort(state);
	ft_lstclear(&state.a, free);
}
