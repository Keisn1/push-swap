#include <gtest/gtest.h>
#include "push_swap.h"

TEST(push_swap_test, first_test) {
	// get push_swap output
    testing::internal::CaptureStdout();
	push_swap();
    std::string push_swap_return = testing::internal::GetCapturedStdout();

	ASSERT_STREQ("Hello", push_swap_return.c_str());
}
