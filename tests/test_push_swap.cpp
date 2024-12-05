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

//////////////////////////////
// Extract Numbers test
//////////////////////////////

struct ExtractNbrsParam {
	int argc;
	std::vector<std::string> argv;
	int want_len;
	std::vector<int> want;
};

class ExtractNbrsTest : public testing::TestWithParam<ExtractNbrsParam> {};

TEST_P(ExtractNbrsTest, first_test) {
	ExtractNbrsParam param = GetParam();

	char** argv = create_str_arr(param.argv);
	int got_len;

	int* got = extract_nbrs(param.argc, argv, &got_len);

	EXPECT_EQ(param.want_len, got_len);
	if (param.want_len == 0)
		EXPECT_EQ(got, nullptr);
	else
		for (unsigned long i = 0; i < param.want.size(); i++)
			EXPECT_EQ(param.want[i], got[i]);
	free(got);

	for (unsigned long i = 0; i < param.argv.size(); i++)
		free(argv[i]);
	free(argv);
}


INSTANTIATE_TEST_SUITE_P(
    ExtractNbrsTest, ExtractNbrsTest,
    ::testing::Values(
        ExtractNbrsParam{3, {"push_swap", "1", "2"}, 2, {1, 2}},
        ExtractNbrsParam{4, {"push_swap", "1", "2", "3"}, 3, {1, 2, 3}},
        ExtractNbrsParam{2, {"push_swap", "1 2"}, 2, {1, 2}},
        ExtractNbrsParam{2, {"push_swap", "1"}, 1, {1}},
        ExtractNbrsParam{
            2, {"push_swap", "-2 -3 -10 2123"}, 4, {-2, -3, -10, 2123}},
        ExtractNbrsParam{4, {"push_swap", "-1", "-2", "-3"}, 3, {-1, -2, -3}},
        ExtractNbrsParam{3, {"push_swap", "1", "123981273192378"}, 0, {}},
        ExtractNbrsParam{2, {"push_swap", "1 123981273192378"}, 0, {}}
));
