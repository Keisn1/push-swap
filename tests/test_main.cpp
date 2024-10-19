#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "StackOperation*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests*";
    // ::testing::GTEST_FLAG(filter) = "LeastAmountTests*";
    // ::testing::GTEST_FLAG(filter) = "InsertSortTests*";
    // ::testing::GTEST_FLAG(filter) = "InsertNewValTest*";
    // ::testing::GTEST_FLAG(filter) = "Insert*";
    return RUN_ALL_TESTS();
}

