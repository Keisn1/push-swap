#include <gtest/gtest.h>
#include "libft.h"
#include "test_push_swap.hpp"

struct AlgorithmTestInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
};

class AlgorithmTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(AlgorithmTest, ThreeElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = sort_three_elements(state);

    assert_equal_stack(state.a, want_stack);
    ft_lstclear(&state.a,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    AlgorithmTest,
    ::testing::Values(
        AlgorithmTestInput{3, {1, 2, 3}, {1, 2, 3}},
        AlgorithmTestInput{3, {1, 3, 2}, {1, 2, 3}},
        AlgorithmTestInput{3, {2, 1, 3}, {1, 2, 3}},
        AlgorithmTestInput{3, {2, 3, 1}, {1, 2, 3}},
        AlgorithmTestInput{3, {3, 1, 2}, {1, 2, 3}},
        AlgorithmTestInput{3, {3, 2, 1}, {1, 2, 3}}
        )
    );
