#include <gtest/gtest.h>
#include "test_push_swap.hpp"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////////////////////////
// insert sort
////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////
// find least amount of operations

struct LeastAmountOfOperationTestParam {
    std::vector<int> stack_a;
    std::vector<int> stack_b;
	int idx;
	int want;
    int size_a;
    int size_b;
    int max_b;
	int min_b;
};

class LeastAmountTest : public testing::TestWithParam<LeastAmountOfOperationTestParam> {};

TEST_P(LeastAmountTest, LeastAmountTest) {
    LeastAmountOfOperationTestParam param = GetParam();

    t_state state = {create_stack(param.stack_a), create_stack(param.stack_b), param.size_a, param.size_b, param.max_b, param.min_b};

    testing::internal::CaptureStdout();
    int got = get_amount_ops(state, param.idx);
	testing::internal::GetCapturedStdout();

	EXPECT_EQ(got, param.want);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
}

INSTANTIATE_TEST_SUITE_P(
    LeastAmountTests,
    LeastAmountTest,
    ::testing::Values(
        LeastAmountOfOperationTestParam{{3}, {1, 2}, 0, 2, 1, 2, 2, 1},
        LeastAmountOfOperationTestParam{{3}, {2, 1}, 0, 1, 1, 2, 2, 1},
        LeastAmountOfOperationTestParam{{3}, {1, 0}, 0, 1, 1, 2, 1, 0},
        LeastAmountOfOperationTestParam{{3}, {2, 1, 6}, 0, 1, 1, 3, 6, 1},
        LeastAmountOfOperationTestParam{{4}, {2, 1}, 0, 1, 1, 2, 2, 1},
        LeastAmountOfOperationTestParam{{2}, {1, 3}, 0, 1, 1, 2, 3, 1},
        LeastAmountOfOperationTestParam{{2}, {4, 3, 1, 5}, 0, 3, 1, 4, 4, 1},
        LeastAmountOfOperationTestParam{{2}, {5, 4, 3, 1, 6}, 0, 3, 1, 5, 4, 1},
        LeastAmountOfOperationTestParam{{0, 2}, {5, 4, 3, 1, 6}, 1, 4, 2, 5, 4, 1},
        LeastAmountOfOperationTestParam{{0, 0, 0, 0 ,2, 0}, {5, 4, 3, 1, 6}, 4, 5, 6, 5, 4, 1},
        LeastAmountOfOperationTestParam{{0, 0, 0, 0 ,2, 0}, {3, 1, 6, 5, 4, }, 4, 4, 6, 5, 4, 1},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 9}, 0, 2, 5, 5, 9, -2},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 9}, 1, 2, 5, 5, 9, -2},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 9}, 2, 5, 5, 5, 9, -2},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 9}, 3, 4, 5, 5, 9, -2},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 9}, 4, 3, 4, 5, 9, -2},
        LeastAmountOfOperationTestParam{{4,7,-1, 10, 2}, {6, 3, 1, -2, 12, 9}, 2, 6, 5, 6, 12, -2},
        LeastAmountOfOperationTestParam{{1}, {2, 3}, 0, 2, 1, 2, 3, 2},
        LeastAmountOfOperationTestParam{{1}, {4, 3, 2, 7, 6, 5}, 0, 4, 1, 6, 7, 2},
        LeastAmountOfOperationTestParam{{1}, {6, 5, 4, 3, 2, 7}, 0, 2, 1, 6, 7, 2},
        LeastAmountOfOperationTestParam{{0, 3, 7}, {6, 5, 4, 2, 1, -2, -5}, 2, 2, 3, 7, 6, -5}
		)
	);

////////////////////////////////////////////////////////////////////////////////////////////////////
// insert new value


struct InsertNewValTestParams {
    std::vector<int> stack_a;
    std::vector<int> stack_b;
    std::vector<int> want_stack;
	int want_nbr_ops;
};

class InsertNewValTest : public testing::TestWithParam<InsertNewValTestParams> {};

TEST_P(InsertNewValTest, InsertNewValTest) {
    InsertNewValTestParams param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), create_stack(param.stack_b),  (int)param.stack_a.size(), (int)param.stack_b.size(), 0, 0};

    testing::internal::CaptureStdout();
    state = insert_new_val(state);
    std::string output = testing::internal::GetCapturedStdout();
	std::cout << output;

	int got_nbr_ops = countNewlines(output);

    assert_equal_stack(state.b, want_stack);
	EXPECT_EQ(got_nbr_ops, param.want_nbr_ops);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    InsertNewValTest,
    InsertNewValTest,
    ::testing::Values(
        InsertNewValTestParams{{3}, {2, 1}, {3, 2, 1}, 1},
        InsertNewValTestParams{{3}, {6, 5, 4, 2, 1}, {3, 2, 1, 6, 5, 4}, 3},
        InsertNewValTestParams{{3, 7}, {6, 5, 4, 2, 1}, {7, 6, 5, 4, 2, 1}, 2},
        InsertNewValTestParams{{0, 3, 7}, {6, 5, 4, 2, 1, -2, -5}, {7, 6, 5, 4, 2, 1, -2, -5}, 2}
		)
	);

////////////////////////////////////////////////////////////////////////////////////////////////////
// insert sort algorithm


struct InsertSortTestParam {
    std::vector<int> stack_a;
    std::vector<int> want_stack;
};

class InsertSortTest : public testing::TestWithParam<InsertSortTestParam> {};

TEST_P(InsertSortTest, InsertSortTest) {
    InsertSortTestParam param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {create_stack(param.stack_a), NULL,  (int)param.stack_a.size(), 0, 0, 0};

    testing::internal::CaptureStdout();
    state = insert_sort(state);
	testing::internal::GetCapturedStdout();

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    InsertSortTests,
    InsertSortTest,
    ::testing::Values(
        InsertSortTestParam{{}, {}},
        InsertSortTestParam{{1}, {1}},
        InsertSortTestParam{{2, 1}, {1, 2}},
        InsertSortTestParam{{1, 2, 3}, {1, 2, 3}},
        InsertSortTestParam{{2, 1, 3}, {1, 2, 3}},
        InsertSortTestParam{{3, 2, 1}, {1, 2, 3}}
		)
	);
