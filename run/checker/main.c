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

	char** lines = NULL;
	char* line = get_next_line(STDIN_FILENO);
	all = ft_strdup(line);
	while (line) {
		free(line);
		line = get_next_line(STDIN_FILENO);
		ft_strlcat(, const char *src, size_t size)
	}
	t_stack *a = create_stack(len, nbrs);
	t_state state = (t_state){a, NULL, len, 0, 0, 0};

	if (is_ordered(state))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);

	ft_lstclear(&a, free);
	free(nbrs);
    return 0;
}
