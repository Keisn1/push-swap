#include <gtest/gtest.h>
#include "test_push_swap.hpp"
#include "push_swap.h"

struct CreateStackTestParam {
	int argc;
	std::vector<std::string> argv;
	std::vector<int> want;
};

class CreateStackTest : public testing::TestWithParam<CreateStackTestParam> {};

TEST_P(CreateStackTest, CreateStackTest) {
	CreateStackTestParam param = GetParam();

    char** argv = (char**)malloc(sizeof(char*) * param.argc);
    int counter = 0;
    for (std::string str : param.argv) {
        argv[counter] = ft_strdup(str.c_str());
        counter++;
    }
    t_stack *got = create_stack(param.argc, argv);

    assert_correct_stack(got, param.want);

    ft_lstclear(&got,free);
    int count = 0;
    while (count < param.argc) {
        free(argv[count]);
		count++;
    }
	free(argv);
}

INSTANTIATE_TEST_SUITE_P(
    CreateStackTests,
    CreateStackTest,
    ::testing::Values(
		CreateStackTestParam{1, {"push_swap"}, {}},
		CreateStackTestParam{2, {"push_swap", "1"}, {1}},
		CreateStackTestParam{2, {"push_swap", "+1"}, {1}},
		CreateStackTestParam{2, {"push_swap", "-1"}, {-1}},
		CreateStackTestParam{2, {"push_swap", "01"}, {1}},
		CreateStackTestParam{2, {"push_swap", "002147483647"}, {INT_MAX}},
		CreateStackTestParam{2, {"push_swap", "-01"}, {-1}},
		CreateStackTestParam{2, {"push_swap", "-002147483648"}, {INT_MIN}},
		CreateStackTestParam{9, {"push_swap", "3", "4", "6", "8", "9", "74", "-56", "+495"}, {3, 4, 6, 8, 9, 74, -56, 495}}
		)
);
