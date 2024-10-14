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

void	push_swap(int argc , char* argv[])
{
	/* int count = 1; */
	if (argc) {

	}
	int first = ft_atoi(argv[1]);
	int second = ft_atoi(argv[2]);
	if (first > second) {
		ft_putendl_fd("sa", STDOUT_FILENO);
	}
	return;
	/* int *x; */
	/* x = (int*)malloc(sizeof(int)); */
	/* *x = ft_atoi(argv[count]); */
	/* t_stack *a = ft_lstnew(x); */
	/* while (count < argc) { */
	/* 	ft_putendl_fd(argv[count], STDOUT_FILENO); */
	/* 	count++; */
		/* x = (int*)malloc(sizeof(int)); */
		/* *x = ft_atoi(argv[count]); */
		/* ft_lstadd_back(&a, ft_lstnew(x)); */
		/* count++; */
	/* } */
	/* if (*(int*)a->content > *(int*)a->next->content) { */
	/* 	ft_putendl_fd("sa", STDOUT_FILENO); */
	/* } */
}
