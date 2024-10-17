#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // ::testing::GTEST_FLAG(filter) = "SiftDownTests/SiftDownTest*";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/22";
    // ::testing::GTEST_FLAG(filter) = "MergeSortTests/MergeSortTest.MergeSortTest/3";
    // ::testing::GTEST_FLAG(filter) = "AlgorithmTests/PartiallySortWithFive*";
    return RUN_ALL_TESTS();
}

