#include "operations.h"
#include "push_swap.h"

/* t_limits_b update_limits(t_limits_b limits_b, int nbr) { */
/* 	if (limits_b.max_b < nbr) */
/* 		limits_b.max_b = nbr; */
/* 	if (nbr < limits_b.min_b) */
/* 		limits_b.min_b = nbr; */
/* 	return limits_b; */
/*  } */

/* t_state insert_sort(t_state state, int size) { */
/* 	/\* Step 1: Push 2 numbers to Stack *\/ */

/* 	push_b(state); */
/* 	t_limits_b limits_b = {.max_b= *(int*)state.b->content, .min_b = *(int*)state.b->content}; */

/* 	push_b(state); */
/* 	update_limits(limits_b, *(int*)state.b->content); */
/* 	return state; */
/* } */


int get_amount_ops(t_state state, int idx) {
	if (state.a) {

		if (idx) {

		}
	}
	return 2;
}
