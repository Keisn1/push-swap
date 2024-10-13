/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfreyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:15/18 by kfreyer           #+#    #+#             */
/*   Updated: 2024/10/11 17:15:18 by kfreyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

typedef t_list t_stack;

typedef struct s_state {
	t_stack *a;
	t_stack *b;
} t_state;

# ifdef __cplusplus

extern "C"
{
# endif

	void	push_swap(int /* argc */, char* /* argv[] */);

# ifdef __cplusplus
}
# endif

#endif // PUSH_SWAP_H
