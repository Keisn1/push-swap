#include <cstdio>
#include <gtest/gtest.h>
#include "test_push_swap.hpp"

struct PushSwapInput {
    int argc;
    std::vector<std::string> argv;
    std::string want_return;
};

class PushSwapTest : public testing::TestWithParam<PushSwapInput> {};


TEST_P(PushSwapTest, first_test) {
    PushSwapInput param = GetParam();

    // get push_swap output
    char** argv = (char**)malloc(sizeof(char*) * param.argc);
    int counter = 0;
    for (std::string str : param.argv) {
        argv[counter] = ft_strdup(str.c_str());
        counter++;
    }
    testing::internal::CaptureStdout();
    push_swap(param.argc, argv);
    std::string push_swap_return = testing::internal::GetCapturedStdout();

    EXPECT_STREQ(param.want_return.c_str(), push_swap_return.c_str());

    int count = 0;
    while (count < param.argc) {
        free(argv[count++]);
    }
    free(argv);
}

INSTANTIATE_TEST_SUITE_P(
    PushSwapTests,
    PushSwapTest,
    ::testing::Values(
        PushSwapInput{4, {"push_swap", "1", "2", "3"}, ""},
        PushSwapInput{4, {"push_swap", "2", "1", "3"}, "sa\n"}
        )
    );
