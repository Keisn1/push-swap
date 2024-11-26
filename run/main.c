/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 18:54/54 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/11 18:54:54 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc < 2) {
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}

	if (argc == 2) {
		if (ft_strlen(argv[1]) > 3) {
			int nbrs[3] = {ft_atoi(argv[1]),  ft_atoi(argv[1]+1), ft_atoi(argv[1] + 3)};
			push_swap(3, nbrs);
			return (0);
		}
		int nbrs[2] = {2, 1};
		push_swap(2, nbrs);
		return (0);
	}

	int *nbrs = malloc
	push_swap(argc - 1, argv+1);
	return (0);
}
