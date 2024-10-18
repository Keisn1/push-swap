#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct StackOperationInput {
	std::string op;
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> want_a;
	std::vector<int> want_b;
};


class StackOperationTest : public testing::TestWithParam<StackOperationInput> {};

TEST_P(StackOperationTest, first_test) {
    StackOperationInput param = GetParam();

    testing::internal::CaptureStdout();
	t_state state = {create_stack(param.a), create_stack(param.b), (int)param.a.size(), (int)param.b.size(), 0, 0};
	int want_size_a = param.a.size();
	int want_size_b = param.b.size();
	if (param.op == "pa" && param.b.size()) {
		want_size_a++;
		want_size_b--;
	}
	if (param.op == "pb" && param.a.size()) {
		want_size_b++;
		want_size_a--;
	}

	t_state want_state = {create_stack(param.want_a),create_stack( param.want_b), want_size_a, want_size_b, 0, 0};

    if (param.op == "sa")
		state = swap(state, 'a');
    if (param.op == "sb")
		state = swap(state, 'b');
    if (param.op == "ss")
		state = swap(state, 's');
    if (param.op == "pa")
		state = push_a(state);
    if (param.op == "pb")
		state = push_b(state);
    if (param.op == "ra")
		state = rotate(state, 'a');
    if (param.op == "rb")
		state = rotate(state, 'b');
    if (param.op == "rr")
		state = rotate(state, 'r');
    if (param.op == "rra")
		state = reverse_rotate(state, 'a');
    if (param.op == "rrb")
		state = reverse_rotate(state, 'b');
    if (param.op == "rrr")
		state = reverse_rotate(state, 'r');

	testing::internal::GetCapturedStdout();
	assert_equal_state(state, want_state);
	clear_stacks(state,want_state);
}

INSTANTIATE_TEST_SUITE_P(
    StackOperationTests, StackOperationTest,
    ::testing::Values(
		// swapping
        // "swap_a"
        StackOperationInput{"sa", {1, 2}, {}, {2, 1}, {}},
        StackOperationInput{"sa", {1}, {}, {1}, {}},
        StackOperationInput{"sa", {}, {}, {}, {}},
        StackOperationInput{"sa", {1, 2, 3}, {}, {2, 1, 3}, {}},
        StackOperationInput{"sa", {1, 2, 3}, {5, 6}, {2, 1, 3}, {5, 6}},
        // "swap_b"
        StackOperationInput{"sb", {}, {}, {}, {}},
        StackOperationInput{"sb", {}, {1}, {}, {1}},
        StackOperationInput{"sb", {1, 2}, {3, 4}, {1, 2}, {4, 3}},
        StackOperationInput{"sb", {}, {3, 4}, {}, {4, 3}},
        StackOperationInput{"sb", {1, 2}, {3, 4, 5}, {1, 2}, {4, 3, 5}},
        // "swap_a and swap_b"
        StackOperationInput{"ss", {}, {}, {}, {}},
        StackOperationInput{"ss", {1, 2}, {3, 4}, {2, 1}, {4, 3}},
        StackOperationInput{"ss", {1, 2, 3}, {3, 4, 5}, {2, 1, 3}, {4, 3, 5}},

		// pushing
		// "push a"
        StackOperationInput{"pb",{}, {}, {}, {}},
        StackOperationInput{"pb",{1}, {}, {}, {1}},
        StackOperationInput{"pb",{1, 2}, {}, {2}, {1}},
        StackOperationInput{"pb",{1, 2, 3}, {5, 6}, {2, 3}, {1, 5, 6}},
		// // "push b"
        StackOperationInput{"pa",{}, {}, {}, {}},
        StackOperationInput{"pa",{}, {1}, {1}, {}},
        StackOperationInput{"pa",{},{1, 2}, {1}, {2}},
        StackOperationInput{"pa",{10, 11}, {12, 13, 14}, {12, 10, 11}, {13, 14}},

		// "rotation"
		// "rotate a"
        StackOperationInput{"ra",{}, {}, {}, {}},
        StackOperationInput{"ra",{1}, {}, {1}, {}},
        StackOperationInput{"ra",{1, 2}, {}, {2, 1}, {}},
        StackOperationInput{"ra",{1, 2, 3}, {}, {2, 3, 1}, {}},
        StackOperationInput{"ra",{1, 2, 3, 4, 5}, {}, {2, 3, 4, 5, 1}, {}},
		// "rotate b"
        StackOperationInput{"rb",{}, {},  {}, {}},
        StackOperationInput{"rb",{}, {1}, {}, {1} },
        StackOperationInput{"rb",{}, {1, 2}, {}, {2, 1} },
        StackOperationInput{"rb",{}, {1, 2, 3}, {}, {2, 3, 1} },
        StackOperationInput{"rb",{}, {1, 2, 3, 4, 5}, {},{2, 3, 4, 5, 1} },
		// "rotate both"
        StackOperationInput{"rr",{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {2, 3, 4, 5, 1},{2, 3, 4, 5, 1} },

		// "reverse rotation"
		// "rotate a"
        StackOperationInput{"rra",{}, {}, {}, {}},
        StackOperationInput{"rra",{1}, {}, {1}, {}},
        StackOperationInput{"rra",{1, 2}, {}, {2, 1}, {}},
        StackOperationInput{"rra",{1, 2, 3}, {}, {3, 1, 2}, {}},
        StackOperationInput{"rra",{1, 2, 3, 4, 5}, {}, {5, 1, 2, 3, 4}, {}},
		// // "rotate b"
        StackOperationInput{"rrb",{}, {},  {}, {}},
        StackOperationInput{"rrb",{}, {1},   {}, {1}},
        StackOperationInput{"rrb",{}, {1, 2},   {}, {2, 1}},
        StackOperationInput{"rrb",{}, {1, 2, 3},  {}, {3, 1, 2}},
        StackOperationInput{"rrb",{}, {1, 2, 3, 4, 5}, {}, {5, 1, 2, 3, 4}},
		// // "reverse rotate both"
        StackOperationInput{"rrr",{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {5, 1, 2, 3, 4},{5, 1, 2, 3, 4} }
        )
    );
