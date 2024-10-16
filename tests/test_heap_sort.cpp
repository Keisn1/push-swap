#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct SiftDownTestParams {
    int size;
	int root;					// the node to be sifted down
    std::vector<int> stack_b;
    std::vector<int> want_stack;
};

class SiftDownTest : public testing::TestWithParam<SiftDownTestParams> {};

TEST_P(SiftDownTest, SiftDownTest) {
    SiftDownTestParams param = GetParam();

    t_stack *want_stack = create_stack(param.want_stack);
    t_state state = {NULL, create_stack(param.stack_b)};

    state = sift_down(state, param.root, param.size);

    assert_equal_stack(state.a, want_stack);

    ft_lstclear(&state.a,free);
    ft_lstclear(&state.b,free);
    ft_lstclear(&want_stack,free);
}

INSTANTIATE_TEST_SUITE_P(
    SiftDownTests,
    SiftDownTest,
    ::testing::Values(
        SiftDownTestParams{6, 2, {}, {}}
        // SiftDownTestParams{6, 2, {2,8,1,3,9,5}, {2, 8, 5, 3, 9, 1}}
        )
    );