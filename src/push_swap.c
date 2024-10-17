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
#include "libft.h"
#include <unistd.h>

t_stack *create_stack(int argc, char* argv[]) {
	int *x = (int*)malloc(sizeof(int));
	*x = ft_atoi(argv[1]);
	t_stack *stack = ft_lstnew(x);
	for (int i = 2; i <= argc; i++) {
		x = (int*)malloc(sizeof(int));
		*x = ft_atoi(argv[i]);
		ft_lstadd_back(&stack, ft_lstnew(x));
	}
	return stack;
}

void	push_swap(int argc , char* argv[])
{

	t_stack *a = create_stack(argc, argv);
	t_state state = {a, NULL};
	/* print_stack(state.a); */
	state = merge_sort(state, argc);
	ft_lstclear(&state.a, free);
}
