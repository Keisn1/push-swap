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

void	free_char_arr(char **arr, int len)
{
	int	count;

	count = 0;
	while (count < len)
		free(arr[count++]);
	free(arr);
}

int	*extract_nbrs(int argc, char **argv, int *len)
{
	char	**nbrs_str;
	char	**head;
	int		*nbrs;
	int		count;

	count = 0;
	if (argc == 2)
	{
		nbrs_str = ft_split(argv[1], ' ');
		*len = 0;
		head = nbrs_str;
		while (*(head++))
			(*len)++;
		nbrs = malloc(*len * sizeof(int));
		while (count++ < *len)
			nbrs[count - 1] = ft_atoi(nbrs_str[count - 1]);
		free_char_arr(nbrs_str, *len);
		return (nbrs);
	}
	*len = argc - 1;
	nbrs = malloc(*len * sizeof(int));
	while (count++ < *len)
		nbrs[count - 1] = ft_atoi(argv[count]);
	return (nbrs);
}
