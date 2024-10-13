#include <gtest/gtest.h>
#include "push_swap.h"

struct PushSwapInput {
    int argc;
    std::vector<char*> argv;
    std::string want_return;
};

class PushSwapTest : public testing::TestWithParam<PushSwapInput> {};


TEST_P(PushSwapTest, first_test) {
    PushSwapInput param = GetParam();

    // get push_swap output
    testing::internal::CaptureStdout();
    push_swap(param.argc, *param.argv.data());
    std::string push_swap_return = testing::internal::GetCapturedStdout();

    ASSERT_STREQ(param.want_return.c_str(), push_swap_return.c_str());
}

PushSwapInput create_push_swap_input(int argc, const std::initializer_list<std::string>& args, std::string want_return) {
    PushSwapInput input{argc, std::vector<char*>(), want_return};
    for (auto& str : args) {
        input.argv.push_back(const_cast<char*>(str.c_str()));
    }
    return input;
}

INSTANTIATE_TEST_SUITE_P(
    PushSwapTests,
    PushSwapTest,
    ::testing::Values(
        create_push_swap_input(3, {"1", "2", "3"}, "")
        )
    );
