#include <gtest/gtest.h>
#include "push_swap.h"



struct PushSwapInput {
	std::string input_a_stack;
};

class PushSwapTest : public testing::TestWithParam<PushSwapInput> {};

TEST_P(PushSwapTest, first_test) {
	PushSwapInput param = GetParam();

	// get push_swap output
    testing::internal::CaptureStdout();
	push_swap(param.input_a_stack.c_str());
    std::string push_swap_return = testing::internal::GetCapturedStdout();

	ASSERT_STREQ(param.input_a_stack.c_str(), push_swap_return.c_str());
}


INSTANTIATE_TEST_SUITE_P(
	PushSwapTests,
	PushSwapTest,
	::testing::Values(
		PushSwapInput{"1 2 3"}
		)
	);
