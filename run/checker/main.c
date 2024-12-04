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
#include "operations.h"
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		len;
	int		*nbrs;
	t_stack	*a;
	t_state	state;

	if (argc < 2)
		return (error());
	if (!check_valid_strs(argc, argv))
		return (error());
	nbrs = extract_nbrs(argc, argv, &len);
	if (!nbrs)
		return (error());
	if (!check_no_duplicates(nbrs, len))
	{
		free(nbrs);
		return (error());
	}

	a = create_stack(len, nbrs);
	state = (t_state){a, NULL, len, 0, 0, 0};

	char *old_line = get_next_line(STDIN_FILENO);
	char* next_line = get_next_line(STDIN_FILENO);

	size_t full_size = ft_strlen(old_line) + ft_strlen(next_line) + 1;
	char* line = malloc(sizeof(char) * full_size);
	line[0] = '\0';

	if (old_line) {
		if (ft_strlcat(line, old_line, full_size) >= full_size)
			/* truncation occured */
			ft_putendl_fd("truncation occured", STDOUT_FILENO);
	}
	free(old_line);

	if (next_line) {
		if (ft_strlcat(line, next_line, full_size) >= full_size)
			/* truncation occured */
			ft_putendl_fd("truncation occured", STDOUT_FILENO);
	}
		free(next_line);

	char** lines = ft_split(line, '\n');
	char** head = lines;
	while (*head) {
		free(line);
		line = *head;
		head++;
		if (!ft_strncmp(line, "sa", ft_strlen(line)))
			state = swap(state, 'a', false);
		else if (!ft_strncmp(line, "ra", ft_strlen(line)))
			state = rotate(state, 'a', false);
		else {
			free(line);
			free(lines);
			ft_lstclear(&state.a, free);
			free(nbrs);
			return error();
		}
	}

	free(line);
	free(lines);

	if (is_ordered(state))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);


	ft_lstclear(&state.a, free);
	free(nbrs);
	return (0);
}
