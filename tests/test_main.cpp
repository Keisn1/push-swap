#include "test_push_swap.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "StackOperation*";
    // ::testing::GTEST_FLAG(filter) = "SiftDownTests/SiftDownTest*";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/22";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/3";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/SortThreeElementsTest*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/SortThreeElementsWithTailTest*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/MergeRestTest*";
    // ::testing::GTEST_FLAG(filter) = "LeastAmountTests*";
    // ::testing::GTEST_FLAG(filter) = "InsertSortTests*";
    // ::testing::GTEST_FLAG(filter) = "InsertNewValTest*";
    // ::testing::GTEST_FLAG(filter) = "Insert*:StackOperation*:AlgorithmTests/Sort*";
    // ::testing::GTEST_FLAG(filter) = "PushSwapTest*";
    // ::testing::GTEST_FLAG(filter) = "InsertSortTest*";

    return RUN_ALL_TESTS();
}

