#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct AlgorithmTestInput {
    int size;
    std::vector<int> stack_a;
    std::vector<int> want_stack;
    bool with_backing_up;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// 3 Elements
////////////////////////////////////////////////////////////////////////////////////////////////////

class SortThreeElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};

TEST_P(SortThreeElementsTest, ThreeElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0, 0, 0};

    state = sort_three_elements(state);

    assert_equal_stack(state.a, want_stack);
    ft_lstclear(&(state.a),free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortThreeElementsTest,
    ::testing::Values(
        AlgorithmTestInput{3, {1, 2, 3}, {1, 2, 3}, true},
        AlgorithmTestInput{3, {1, 3, 2}, {1, 2, 3}, true},
        AlgorithmTestInput{3, {2, 1, 3}, {1, 2, 3}, true},
        AlgorithmTestInput{3, {2, 3, 1}, {1, 2, 3}, true},
        AlgorithmTestInput{3, {3, 1, 2}, {1, 2, 3}, true},
        AlgorithmTestInput{3, {3, 2, 1}, {1, 2, 3}, true}
        )
    );

class SortThreeElementsWithTailTest : public testing::TestWithParam<AlgorithmTestInput> {};

TEST_P(SortThreeElementsWithTailTest, MoreThanThreeElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0,0, 0};

    state = sort_three_elements_with_tail(state);

    assert_equal_stack(state.a, want_stack);
    ft_lstclear(&state.a,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortThreeElementsWithTailTest,
    ::testing::Values(
        AlgorithmTestInput{5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {1, 3, 2, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 1, 3, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 3, 1, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {3, 1, 2, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {3, 2, 1, 4, 5}, {1, 2, 3, 4, 5}, true}
        )
    );

////////////////////////////////////////////////////////////////////////////////////////////////////
// 4 Elements
////////////////////////////////////////////////////////////////////////////////////////////////////

class SortFourElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(SortFourElementsTest, FourElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0,0, 0};

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
        AlgorithmTestInput{4, {1, 2, 3, 4}, {1, 2, 3, 4}, true},
        AlgorithmTestInput{4, {1, 3, 2, 4}, {1, 2, 3, 4}, true},
        AlgorithmTestInput{4, {2, 1, 3, 4}, {1, 2, 3, 4}, true},
        AlgorithmTestInput{4, {3, 1, 4, 2}, {1, 2, 3, 4}, true},
        AlgorithmTestInput{4, {4, 1, 3, 2}, {1, 2, 3, 4}, true}
        )
    );

class SortFourElementsWithTailTest : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(SortFourElementsWithTailTest, FourElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0, 0, 0};

    state = sort_four_elements_with_tail(state);

    assert_equal_stack(state.a, want_stack);
    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortFourElementsWithTailTest,
    ::testing::Values(
        AlgorithmTestInput{6, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {1, 3, 2, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {2, 1, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {3, 1, 4, 2, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {4, 1, 3, 2, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {6, 1, 3, 2, 4, 5}, {1, 2, 3, 6, 4, 5}, true}
        )
    );

////////////////////////////////////////////////////////////////////////////////////////////////////
// 5 Elements
////////////////////////////////////////////////////////////////////////////////////////////////////
class SortFiveElementsTest : public testing::TestWithParam<AlgorithmTestInput> {};

TEST_P(SortFiveElementsTest, FiveElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0, 0, 0};

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
        AlgorithmTestInput{5, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {1, 2, 4, 3, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 1, 4, 3, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {1, 3, 4, 2, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {1, 4, 3, 2, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {1, 5, 3, 2, 4}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 3, 1, 4, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 4, 1, 3, 5}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {2, 5, 1, 3, 4}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{5, {4, 5, 1, 3, 2}, {1, 2, 3, 4, 5}, true}
        )
    );

class SortFiveElementsWithTailTest : public testing::TestWithParam<AlgorithmTestInput> {};

TEST_P(SortFiveElementsWithTailTest, FiveElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0, 0, 0};

    state = sort_five_elements_with_tail(state, param.with_backing_up);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    SortFiveElementsWithTailTest,
    ::testing::Values(
        AlgorithmTestInput{7, {1, 2, 3, 4, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {1, 2, 4, 3, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {2, 1, 4, 3, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {1, 3, 4, 2, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {1, 4, 3, 2, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {1, 5, 3, 2, 4, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {2, 3, 1, 4, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {2, 4, 1, 3, 5, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {2, 5, 1, 3, 4, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false},
        AlgorithmTestInput{7, {4, 5, 1, 3, 2, 6, 7}, {6, 7, 1, 2, 3, 4, 5}, false}
        )
    );

////////////////////////////////////////////////////////////////////////////////////////////////////
// Partially sorting
////////////////////////////////////////////////////////////////////////////////////////////////////

class PartiallySortWithFive : public testing::TestWithParam<AlgorithmTestInput> {};


TEST_P(PartiallySortWithFive, FiveElementStack) {
    AlgorithmTestInput param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL, 0, 0, 0, 0};

    state = partially_sort_with_five(state, param.size);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    AlgorithmTests,
    PartiallySortWithFive,
    ::testing::Values(
        AlgorithmTestInput{6, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{6, {2, 1, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}, true},
        AlgorithmTestInput{0, {}, {}, true},
        AlgorithmTestInput{1, {1}, {1}, true},
        AlgorithmTestInput{2, {1, 2}, {1, 2}, true},
        AlgorithmTestInput{3, {3, 2, 1}, {1, 2, 3}, true},
        AlgorithmTestInput{4, {3, 4, 2, 1}, {1, 2, 3, 4}, true},
        AlgorithmTestInput{5, {1, 4, 2, 5, 3}, {1, 2, 3, 4, 5}, true},
        AlgorithmTestInput{7, {2, 6, 4, 3, 7, 5, 1}, {2, 3, 4, 6, 7, 1, 5}, true},
        AlgorithmTestInput{8, {4,2,5,6,8,0,9,7}, {2, 4, 5, 6, 8, 0, 7, 9 }, true},
        AlgorithmTestInput{9, {4,2,5,6,8,0,9,7, 1}, {2, 4, 5, 6, 8, 0, 1, 7, 9 }, true},
        AlgorithmTestInput{10, {4,2,5,6,8,0,9,7, 3, 1}, {2, 4, 5, 6, 8, 0, 1, 3, 7, 9 }, true},
        AlgorithmTestInput{11, {4,2,5,6,8,0,9,7, 3, 1, 11}, {2, 4, 5, 6, 8, 0, 1, 3, 7, 9, 11}, true},
        AlgorithmTestInput{16, {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10, 15}, {0, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, true},
        AlgorithmTestInput{17, {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10, 16, 15}, {0, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 }, true},
        AlgorithmTestInput{18, {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10, 17, 16, 15}, {0, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17}, true},
        AlgorithmTestInput{19, {4, 3, 2, 1, 0, 9, 8, 7, 6, 5, 14, 13, 12, 11, 10, 18, 17, 16, 15}, {0, 1, 2, 3, 4,5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}, true},
        AlgorithmTestInput{13, {1,3,5,7,9,0,2,4,6,8,12,11,10}, {1,3,5,7,9,0,2,4,6,8,10,11,12}, true}
        )
    );

