/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:21/42 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/02 11:21:42 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_char_arr(char **arr, int len)
{
	int	count;

	count = 0;
	while (count < len)
		free(arr[count++]);
	free(arr);
}

bool	x_equals_s1(int x, char *s1)
{
	char	*sym_str;

	if (*s1 == '+')
		s1++;
	sym_str = ft_itoa(x);
	if (ft_strncmp(s1, sym_str, ft_strlen(s1)))
	{
		free(sym_str);
		return (false);
	}
	free(sym_str);
	return (true);
}

int	*extract_nbrs_strings(int argc, char **argv, int *len)
{
	int	*nbrs;
	int	count;

	count = 0;
	*len = argc - 1;
	nbrs = malloc(*len * sizeof(int));
	while (count++ < *len)
	{
		nbrs[count - 1] = ft_atoi(argv[count]);
		if (!x_equals_s1(nbrs[count - 1], argv[count]))
		{
			free(nbrs);
			*len = 0;
			return (NULL);
		}
	}
	return (nbrs);
}

int	*extract_nbrs_1_string(char **argv, int *len)
{
	char	**nbrs_str;
	char	**head;
	int		*nbrs;
	int		count;

	count = 0;
	*len = 0;
	nbrs_str = ft_split(argv[1], ' ');
	head = nbrs_str;
	while (*(head++))
		(*len)++;
	nbrs = malloc(*len * sizeof(int));
	while (count++ < *len)
	{
		nbrs[count - 1] = ft_atoi(nbrs_str[count - 1]);
		if (!x_equals_s1(nbrs[count - 1], nbrs_str[count - 1]))
		{
			free(nbrs);
			free_char_arr(nbrs_str, *len);
			*len = 0;
			return (NULL);
		}
	}
	free_char_arr(nbrs_str, *len);
	return (nbrs);
}

int	*extract_nbrs(int argc, char **argv, int *len)
{
	if (argc == 2)
		return (extract_nbrs_1_string(argv, len));
	return (extract_nbrs_strings(argc, argv, len));
}
