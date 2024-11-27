#include <cstdio>
#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct PushSwapInput {
	int len;
	std::vector<int> nbrs;
	std::string want;
};

class PushSwapTest : public testing::TestWithParam<PushSwapInput> {};


TEST_P(PushSwapTest, first_test) {
	PushSwapInput param = GetParam();

	int* nbrs = (int*)malloc(sizeof(int) * param.len);
	int counter = 0;
	for (int nbr : param.nbrs) {
		nbrs[counter] = nbr;
		counter++;
	}
	testing::internal::CaptureStdout();
	push_swap(param.len, nbrs);

	std::string got = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(param.want.c_str(), got.c_str());

	free(nbrs);
}

INSTANTIATE_TEST_SUITE_P(
	PushSwapTests,
	PushSwapTest,
	::testing::Values(
		PushSwapInput{2, {1, 2 }, ""},
		PushSwapInput{3, {1, 2, 3}, ""},
		PushSwapInput{4, {1, 2, 3, 4}, ""},
		PushSwapInput{5, {1, 2, 3, 4, 5}, ""},
		PushSwapInput{6, {1, 2, 3, 4, 5, 6 }, ""}
		)
	);
