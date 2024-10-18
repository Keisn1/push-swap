#ifndef TEST_PUSH_SWAP_H
#define TEST_PUSH_SWAP_H

#include <vector>
#include "push_swap.h"
#include "operations.h"
#include <string>
#include "libft.h"

void print_stack(t_stack *a);
void assert_equal_stack(t_stack *got, t_stack *want);
void assert_equal_state(t_state got, t_state want);
void clear_stacks(t_state got, t_state want);
t_stack *create_stack(std::vector<int> nbrs);
int countNewlines(const std::string& text);

#endif // TEST_PUSH_SWAP_H
