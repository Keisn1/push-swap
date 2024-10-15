#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "push_swap.h"

# ifdef __cplusplus

extern "C"
{
# endif

	/* swapping */
	t_stack *swap_stack(t_stack *head);
	t_state swap(t_state state, char s);

	/* pushing */
	t_state push_a(t_state state);
	t_state push_b(t_state state);

	/* rotating */
	t_stack *rot_stack(t_stack *stack);
	t_state rotate(t_state state, char s);

	/* reverse rotating */
	t_stack *rev_rot_stack(t_stack *stack);
	t_state reverse_rotate(t_state state, char s);

	/* sort top of stack */
	t_state sort_top_of_stack(t_state state, char stack);

# ifdef __cplusplus
}
# endif

#endif // OPERATIONS_H
