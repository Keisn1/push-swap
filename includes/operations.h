#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "push_swap.h"

# ifdef __cplusplus

extern "C"
{
# endif

	/* swapping */
	t_state	swap_a(t_state state);
	t_state swap_b(t_state state);
	t_state swap(t_state state, char s);

	/* pushing */
	t_state push_a(t_state state);
	t_state push_b(t_state state);

	/* rotating */
	t_state rotate(t_state state, char s);

	/* reverse rotating */
	t_state reverse_rotate(t_state state, char s);
# ifdef __cplusplus
}
# endif

#endif // OPERATIONS_H
