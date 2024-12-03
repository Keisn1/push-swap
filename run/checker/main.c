/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:08/56 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/02 15:08:56 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "push_swap.h"

int main(int argc, char *argv[]) {
	int len;
	int* nbrs;

	if (argc < 2)
		return error();
	if (!check_valid_strs(argc, argv))
		return (error());
	nbrs = extract_nbrs(argc, argv, &len);
	if (!nbrs)
		return (error());
	if (!check_no_duplicates(nbrs, len)) {
		free(nbrs);
		return (error());
        }
	free(nbrs);
    return 0;
}
