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
	int	len;
	int	*nbrs;

	if (argc < 2)
		return (error());
	if (!check_valid_strs(argc, argv))
		return (error());

	nbrs = extract_nbrs(argc, argv, &len);
	if (!nbrs)
		return error();

	if (!check_no_duplicates(nbrs, len))
		return (error());
	push_swap(len, nbrs);
	free(nbrs);
	return (0);
}
