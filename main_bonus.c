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

#include "checker_bonus.h"

void	free_artifacts(char **lines, int *nbrs, t_state state)
{
	char	**head;

	head = lines;
	while (*head)
	{
		free(*head);
		head++;
	}
	free(lines);
	ft_lstclear(&state.a, free);
	free(nbrs);
}

int	checker(int *nbrs, int len)
{
	t_stack	*a;
	t_state	state;
	char	*input;
	char	**lines;

	a = create_stack(len, nbrs);
	state = (t_state){a, NULL, len, 0, 0, 0};
	input = get_input_stdin();
	lines = ft_split(input, '\n');
	free(input);
	if (!validate_input(lines))
	{
		free_artifacts(lines, nbrs, state);
		return (error());
	}
	state = do_ops(lines, state);
	check_ordered(state);
	free_artifacts(lines, nbrs, state);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	len;
	int	*nbrs;

	if (argc < 2)
		return (0);
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
	return (checker(nbrs, len));
}
