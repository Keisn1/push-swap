#include <gtest/gtest.h>
#include "libft.h"
#include "test_push_swap.hpp"

struct AlgorithmTestInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
};

class SortThreeElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(SortThreeElementsTest, ThreeElementStack) {
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
    SortThreeElementsTest,
    ::testing::Values(
        AlgorithmTestInput{3, {1, 2, 3}, {1, 2, 3}},
        AlgorithmTestInput{3, {1, 3, 2}, {1, 2, 3}},
        AlgorithmTestInput{3, {2, 1, 3}, {1, 2, 3}},
        AlgorithmTestInput{3, {2, 3, 1}, {1, 2, 3}},
        AlgorithmTestInput{3, {3, 1, 2}, {1, 2, 3}},
        AlgorithmTestInput{3, {3, 2, 1}, {1, 2, 3}}
        )
    );


class SortFourElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(SortFourElementsTest, FourElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = sort_four_elements(state);

    assert_equal_stack(state.a, want_stack);
    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortFourElementsTest,
    ::testing::Values(
        AlgorithmTestInput{4, {1, 2, 3, 4}, {1, 2, 3, 4}},
        AlgorithmTestInput{4, {1, 3, 2, 4}, {1, 2, 3, 4}},
        AlgorithmTestInput{4, {2, 1, 3, 4}, {1, 2, 3, 4}},
        AlgorithmTestInput{4, {3, 1, 4, 2}, {1, 2, 3, 4}},
        AlgorithmTestInput{4, {4, 1, 3, 2}, {1, 2, 3, 4}}
        )
    );

class SortFiveElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(SortFiveElementsTest, FiveElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = sort_five_elements(state);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortFiveElementsTest,
    ::testing::Values(
        AlgorithmTestInput{5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {1, 2, 4, 3, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {2, 1, 4, 3, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {1, 3, 4, 2, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {1, 4, 3, 2, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {1, 5, 3, 2, 4}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {2, 3, 1, 4, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {2, 4, 1, 3, 5}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {2, 5, 1, 3, 4}, {1, 2, 3, 4, 5}},
        AlgorithmTestInput{5, {4, 5, 1, 3, 2}, {1, 2, 3, 4, 5}}
        )
    );
