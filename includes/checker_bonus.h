/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 07:39/46 by kfreyer           #+#    #+#             */
/*   Updated: 2024/12/05 07:39:46 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "operations.h"
# include "push_swap.h"

void	check_ordered(t_state state);
bool	validate_op(const char *op);
bool	validate_input(char **lines);
char	*get_input_stdin(void);
t_state	do_ops(char **lines, t_state state);

#endif // CHECKER_BONUS_H
