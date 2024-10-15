#include <gtest/gtest.h>
#include "libft.h"
#include "test_push_swap.hpp"

struct AlgorithmTestInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
    bool with_backing_up;
};


////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Rest
////////////////////////////////////////////////////////////////////////////////////////////////////

class MergeRestTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(MergeRestTest, MergeRest) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = merge_rest(state, param.size);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    MergeRestTest,
    ::testing::Values(
        AlgorithmTestInput{6, {1, 2, 4, 5, 6, 3}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{7, {1, 2, 4, 6, 7, 3, 5}, {1, 2, 3, 4, 5, 6, 7}, true},
        AlgorithmTestInput{13, {0, 3, 4, 6, 8, 11, 13, 15, 18, 21, 2, 7, 17}, {0, 2, 3, 4, 6, 7, 8, 11, 13, 15, 17, 18, 21}, true},
        AlgorithmTestInput{7, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7}, true}
        )
    );

////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Chunks of five
////////////////////////////////////////////////////////////////////////////////////////////////////

class MergeChunksOfFive : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(MergeChunksOfFive, MergingChunksOfFive) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL};

    state = merge_chunk_of_five(state, param.size, param.with_backing_up);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    MergeChunksOfFive,
    ::testing::Values(
        AlgorithmTestInput{13, {1, 3, 5, 7, 9, 0,2,4,6,8, 12, 11, 10}, {0,1,2,3,4,5,6,7,8,9,12,11,10}, true}
        )
    );
