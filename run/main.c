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
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		len;
	char	*str;
	int		*nbrs;

	if (argc < 2)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (0);
	}
	str = argv[1];
	while (*str)
	{
		if (!(ft_isdigit(*str) || (*str == ' ') || (*str == '-')
				|| (*str == '+')))
		{
			ft_putendl_fd("Error", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		str++;
	}
	nbrs = extract_nbrs(argc, argv, &len);
	push_swap(len, nbrs);
	free(nbrs);
	return (0);
}
