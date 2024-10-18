#include <gtest/gtest.h>
#include "push_swap.h"
#include "test_push_swap.hpp"

struct MergeRestTestInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
    bool with_backing_up;
};


////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Rest
////////////////////////////////////////////////////////////////////////////////////////////////////

class MergeRestTest : public testing::TestWithParam<MergeRestTestInput> {};


TEST_P(MergeRestTest, MergeRest) {
    MergeRestTestInput param = GetParam();

    testing::internal::CaptureStdout();
    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL,0, 0, 0, 0};

    state = merge_rest(state, param.size, param.size%5);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    MergeRestTest,
    ::testing::Values(
        MergeRestTestInput{6, {1, 2, 4, 5, 6, 3}, {1, 2, 3, 4, 5, 6}, true},
        MergeRestTestInput{7, {1, 2, 4, 6, 7, 3, 5}, {1, 2, 3, 4, 5, 6, 7}, true},
        MergeRestTestInput{13, {0, 3, 4, 6, 8, 11, 13, 15, 18, 21, 2, 7, 17}, {0, 2, 3, 4, 6, 7, 8, 11, 13, 15, 17, 18, 21}, true},
        MergeRestTestInput{7, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7}, true}
        )
    );

////////////////////////////////////////////////////////////////////////////////////////////////////
// Merge Chunks
////////////////////////////////////////////////////////////////////////////////////////////////////

struct MergeChunkTestInput {
    int size_of_chunk;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
    bool with_backing_up;
};


class MergeChunksOfFive : public testing::TestWithParam<MergeChunkTestInput> {};


TEST_P(MergeChunksOfFive, MergingChunksOfFive) {
    MergeChunkTestInput param = GetParam();
    testing::internal::CaptureStdout();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0,0, 0};

    state = merge_two_chunks(state, param.size_of_chunk, param.with_backing_up);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    MergeChunksOfFive,
    ::testing::Values(
        MergeChunkTestInput{5, {1, 3, 5, 7, 9, 0,2,4,6,8, 12, 11, 10}, {0,1,2,3,4,5,6,7,8,9,12,11,10}, true},
        MergeChunkTestInput{5, {1, 3, 5, 7, 9, 0,2,4,6,8, 12, 11, 10}, {12, 11, 10,0,1,2,3,4,5,6,7,8,9}, false},
        MergeChunkTestInput{5, {0,1,2,3,4,5,6,7,8,9,12, 11, 10}, {0,1,2,3,4,5,6,7,8,9,12,11,10}, true},
        MergeChunkTestInput{5, {0,1,2,3,4,5,6,7,8,9,12, 11, 10}, {12,11,10,0,1,2,3,4,5,6,7,8,9}, false},
        MergeChunkTestInput{5, {5,6,7,8,9,0,1,2,3,4,12,11,10}, {0,1,2,3,4,5,6,7,8,9,12,11,10}, true},
        MergeChunkTestInput{3, {1,3,5, 0, 2, 4, 8,7,6}, {0,1,2,3,4,5,8,7,6}, true}
        )
    );
