#include <gtest/gtest.h>
#include "push_swap.h"
#include "libft.h"


struct ErrorHandlingTestParams {
	std::vector<std::string> argv;
	int want;
};

class ErrorHandlingTest : public testing::TestWithParam<ErrorHandlingTestParams> {};

TEST_P(ErrorHandlingTest, ErrorHandlingTest) {
	ErrorHandlingTestParams param = GetParam();

    char** argv = (char**)malloc(sizeof(char*) * param.argv.size());
    int counter = 0;
    for (std::string str : param.argv) {
        argv[counter] = ft_strdup(str.c_str());
        counter++;
    }

    int got = check_errors((int)param.argv.size(), argv);

	EXPECT_EQ(got, param.want);

    size_t count = 0;
    while (count < param.argv.size()) {
        free(argv[count]);
		count++;
    }

	free(argv);
}

INSTANTIATE_TEST_SUITE_P(
    ErrorHandlingTests,
    ErrorHandlingTest,
    ::testing::Values(
		ErrorHandlingTestParams{{"push_swap", "1", "2", "3"}, 0},
		ErrorHandlingTestParams{{"push_swap",  "dog"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "cat"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "3cat"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "12",  "3cat"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "12",  "-12"}, 0},
		ErrorHandlingTestParams{{"push_swap",  "12",  "--"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "2147483648"}, -1}, // equals INT_MAX+1
		ErrorHandlingTestParams{{"push_swap",  "12", "2147483648"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "12", "-2147483649"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "12", "12"}, -1},
		ErrorHandlingTestParams{{"push_swap",  "12"}, 0},
		ErrorHandlingTestParams{{"push_swap",  "12", "13", "13"}, -1}
		)
);
