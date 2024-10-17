#include <gtest/gtest.h>
#include "test_push_swap.hpp"

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

    int got = get_amount_ops(state, param.idx);

	EXPECT_EQ(got, param.want);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
}

INSTANTIATE_TEST_SUITE_P(
    LeastAmountTests,
    LeastAmountTest,
    ::testing::Values(
        LeastAmountOfOperationTestParam{{3,4,5}, {1, 2}, 0, 2, 3, 2, 2, 1}
        // LeastAmountOfOperationTestParam{{3,4,5}, {2, 1}, 0, 2, 3, 2, 2, 1}
		)
	);

////////////////////////////////////////////////////////////////////////////////////////////////////
// insert sort algorithm


// struct InsertSortTestParam {
//     int size;
//     std::vector<int> stack_a;
//     std::vector<int> want_stack;
// };

// class InsertSortTest : public testing::TestWithParam<InsertSortTestParam> {};

// TEST_P(InsertSortTest, InsertSortTest) {
//     InsertSortTestParam param = GetParam();

//     t_stack *want_stack = create_stack(param.want_stack);
//     t_state state = {create_stack(param.stack_a), NULL, 0, 0};

//     state = insert_sort(state, param.size);

//     assert_equal_stack(state.a, want_stack);

//     ft_lstclear(&state.a,free);
//     ft_lstclear(&state.b,free);
//     ft_lstclear(&want_stack,free);
// }

// INSTANTIATE_TEST_SUITE_P(
//     InsertSortTests,
//     InsertSortTest,
//     ::testing::Values(
//         InsertSortTestParam{9, {5,2,7,1,6,3,9,4,8}, {1,2,3,4,5,6,7,8,9}}
// 		)
// 	);
