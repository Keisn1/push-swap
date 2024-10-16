#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct MergeSortInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Rest
////////////////////////////////////////////////////////////////////////////////////////////////////

class MergeSortTest : public testing::TestWithParam<MergeSortInput> {};

TEST_P(MergeSortTest, MergeSortTest) {
    MergeSortInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = merge_sort(state, param.size);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    MergeSortTests,
    MergeSortTest,
    ::testing::Values(
        MergeSortInput{13, {1,3,5,7,9,0,2,4,6,8,12,11,10}, {0,1,2,3,4,5,6,7,8,9,10,11,12}},
        MergeSortInput{12, {1,3,5,7,9,0,2,4,6,8,12,11}, {0,1,2,3,4,5,6,7,8,9, 11,12}},
        MergeSortInput{12, {9,7,5,3,1,8,6,4,2,0,12,11}, {0,1,2,3,4,5,6,7,8,9, 11,12}},
        MergeSortInput{16, {9,7,5,3,1,8,6,4,2,0,19,17,15,13,11,18}, {0,1,2,3,4,5,6,7,8,9,11,13,15,17,18,19}},
        MergeSortInput{16, {9,7,5,3,1,19,17,15,13,11,8,6,4,2,0,18}, {0,1,2,3,4,5,6,7,8,9,11,13,15,17,18,19}}
        )
    );
