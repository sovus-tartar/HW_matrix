#include <gtest/gtest.h>
#include <fstream>
#include "../headers/matrix.hpp"

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

TEST(matrix, swap_str1)
{
    matrixes::square_matrix<int> A(2);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    A.swap_str(0, 1);

    EXPECT_EQ(A[0][0], 2);
    EXPECT_EQ(A[0][1], 3);
    EXPECT_EQ(A[1][0], 0);
    EXPECT_EQ(A[1][1], 1);
}

TEST(matrix, swap_coll1)
{
    matrixes::square_matrix<int> A(3);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    A.swap_collumn(0, 1);

    EXPECT_EQ(A[0][0], 1);
    EXPECT_EQ(A[0][1], 0);
    EXPECT_EQ(A[1][0], 3);
    EXPECT_EQ(A[1][1], 2);
}

TEST(matrix, swap_col_and_str)
{
    matrixes::square_matrix<int> A(2);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    A.swap_str(0, 1);
    A.swap_collumn(0, 1);
    
    EXPECT_EQ(A[0][0], 3);
    EXPECT_EQ(A[0][1], 2);
    EXPECT_EQ(A[1][0], 1);
    EXPECT_EQ(A[1][1], 0);
}

TEST(matrix, det1)
{
    matrixes::square_matrix<double> A(2);

    A[0][0] = 0;
    A[0][1] = 1;
    A[1][0] = 2;
    A[1][1] = 3;

    EXPECT_DOUBLE_EQ(A.det(), -2);
    EXPECT_DOUBLE_EQ(A[0][0], 0);
    EXPECT_DOUBLE_EQ(A[0][1], 1);
    EXPECT_DOUBLE_EQ(A[1][0], 2);
    EXPECT_DOUBLE_EQ(A[1][1], 3);
}

TEST(matrix, det2)
{
    std::ifstream file;

    file.open("../tests/222.in");

    int N;
    file >> N;

    matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            file >> A[i][j];

    double expected_det;

    file >> expected_det;

    file.close();
    
    EXPECT_NEAR(A.det(), expected_det, 1);
}

TEST(matrix, det3)
{
    std::ifstream file;

    file.open("../tests/333.in");

    int N;
    file >> N;

    matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            file >> A[i][j];

    double expected_det;

    file >> expected_det;

    file.close();
    
    EXPECT_NEAR(A.det(), expected_det, 1);
}

TEST(matrix, det4)
{
    std::ifstream file;

    file.open("../tests/444.in");

    int N;
    file >> N;

    matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            file >> A[i][j];

    double expected_det;

    file >> expected_det;

    file.close();
    
    EXPECT_NEAR(A.det(), expected_det, 1);
}

TEST(matrix, det5)
{
    matrixes::square_matrix<double> A(1);

    A[0][0] = 13;


    EXPECT_DOUBLE_EQ(A.det(), 13);
}

TEST(matrix, det6)
{
    std::ifstream file;

    file.open("../tests/555.in");

    int N;
    file >> N;

    matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            file >> A[i][j];

    double expected_det;

    file >> expected_det;

    file.close();
    
    EXPECT_NEAR(A.det(), expected_det, 1);
}

TEST(matrix, det7)
{
    std::ifstream file;

    file.open("../tests/666.in");

    int N;
    file >> N;

    matrixes::square_matrix<double> A(N);

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            file >> A[i][j];

    double expected_det;

    file >> expected_det;

    file.close();
    
    EXPECT_NEAR(A.det(), expected_det, 1);
}


int main(int argc, char ** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}