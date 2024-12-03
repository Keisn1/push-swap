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
#include "push_swap.h"
#include <unistd.h>

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

	char* line = get_next_line(STDIN_FILENO);
	if (!ft_strncmp (line, "sa ", 3)) {
		free(line);
		free(nbrs);
		return (error());
	}

	t_stack *a = create_stack(len, nbrs);
	t_state state = (t_state){a, NULL, len, 0, 0, 0};
	if (is_ordered(state))
		if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "ra", 2))
			ft_putendl_fd("KO", STDOUT_FILENO);
		else
			ft_putendl_fd("OK", STDOUT_FILENO);
	else
		if (!ft_strncmp(line, "sa", 2) || !ft_strncmp(line, "ra", 2))
			ft_putendl_fd("OK", STDOUT_FILENO);
		else
			ft_putendl_fd("KO", STDOUT_FILENO);


	free(line);
	ft_lstclear(&a, free);
	free(nbrs);
    return 0;
}
