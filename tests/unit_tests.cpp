#include <gtest/gtest.h>
#include "../headers/matrix.h"


TEST(matrix, sq_br_test1)
{
    matrixes::square_matrix<int> A(2);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    EXPECT_EQ(A[0][0], 0);
    EXPECT_EQ(A[0][1], 1);
    EXPECT_EQ(A[1][0], 2);
    EXPECT_EQ(A[1][1], 3);
}

TEST(matrix, sq_br_test2)
{
    matrixes::square_matrix<int> A(3);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    EXPECT_EQ(A[0][0], 0);
    EXPECT_EQ(A[0][1], 1);
    EXPECT_EQ(A[1][0], 2);
    EXPECT_EQ(A[1][1], 3);
}

int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}