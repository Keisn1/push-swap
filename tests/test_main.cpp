#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "StackOperation*";
    // ::testing::GTEST_FLAG(filter) = "SiftDownTests/SiftDownTest*";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/22";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/3";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/PartiallySortWithFive*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/SortThreeElementsTest*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/SortThreeElementsWithTailTest*";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/MergeRestTest*";
    // ::testing::GTEST_FLAG(filter) = "LeastAmountTests*";
    ::testing::GTEST_FLAG(filter) = "InsertSortTests*";
    return RUN_ALL_TESTS();
}

