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
#include <unistd.h>

char	*get_input_stdin(void)
{
	size_t	full_size;
	char	*input;
	char	*received;
	char	*tmp;

	full_size = 1;
	input = ft_get_empty_str(full_size);
	received = get_next_line(STDIN_FILENO, false);
	while (received)
	{
		full_size += ft_strlen(received);
		tmp = malloc(sizeof(char) * full_size);
		ft_strlcpy(tmp, input, full_size);
		free(input);
		input = tmp;
		tmp = NULL;
		if (ft_strlcat(input, received, full_size) >= full_size)
			/* truncation occured */
			ft_putendl_fd("truncation occured", STDOUT_FILENO);
		free(received);
		received = get_next_line(STDIN_FILENO, false);
	}
	get_next_line(STDIN_FILENO, true);
	return (input);
}

int	main(int argc, char *argv[])
{
	int		len;
	int		*nbrs;
	t_stack	*a;
	t_state	state;
	char	*input;
	char	**lines;
	char	**head;

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
	input = get_input_stdin();

	lines = ft_split(input, '\n');
	head = lines;
	while (*head)
	{
		free(input);
		input = *head;
		head++;
		if (!ft_strncmp(input, "sa", ft_strlen(input)))
			state = swap(state, 'a', false);
		else if (!ft_strncmp(input, "ra", ft_strlen(input)))
			state = rotate(state, 'a', false);
		else if (!ft_strncmp(input, "rra", ft_strlen(input)))
			state = reverse_rotate(state, 'a', false);
		else
		{
			free(input);
			free(lines);
			ft_lstclear(&state.a, free);
			free(nbrs);
			return (error());
		}
	}
	free(input);
	free(lines);
	if (is_ordered(state))
		ft_putendl_fd("OK", STDOUT_FILENO);
	else
		ft_putendl_fd("KO", STDOUT_FILENO);
	ft_lstclear(&state.a, free);
	free(nbrs);
	return (0);
}
