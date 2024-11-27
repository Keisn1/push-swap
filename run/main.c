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
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc < 2) {
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}

	if (argc == 2) {
		char** nbrs_str = ft_split(argv[1], ' ');
		int len = 0;
		char** head = nbrs_str;
		while (*head) {
			len++;
			head++;
        }
		int* nbrs = malloc(len * sizeof(int));
		int count = 0;
		while (count < len) {
			nbrs[count] = ft_atoi(nbrs_str[count]);
			free(nbrs_str[count]);
			count++;
		}
		free(nbrs_str);

		push_swap(len, nbrs);
		free(nbrs);
		return (0);
	}

	int *nbrs = malloc((argc-1) * sizeof(int));
	int count = 0;
	while (count < argc-1) {
		nbrs[count] = ft_atoi(argv[count+1]);
		count++;
	}

	push_swap(argc - 1, nbrs);
	free(nbrs);
	return (0);
}
