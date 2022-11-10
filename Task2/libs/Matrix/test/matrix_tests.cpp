#include "gtest/gtest.h"
#include "matrix.h"

TEST(constructor_tests, base_file)
{
    Matrix matrix("C:/Users/Yana228/LABS_NSU/Task2/libs/GameData/points.txt");

    std::array<std::array<int, PLAYERS_NUMBER>, 8> data =
        {{{4, 4, 4},
          {3, 3, 9},
          {3, 9, 3},
          {9, 3, 3},
          {0, 5, 5},
          {5, 0, 5},
          {5, 5, 0},
          {1, 1, 1}}};

    std::array<std::array<int, PLAYERS_NUMBER>, 8> resultingMatrix = matrix.GetMatrix();

    const int row = 8, column = PLAYERS_NUMBER;

    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            EXPECT_EQ(data[i][j], resultingMatrix[i][j]);
}

TEST(constructor_tests, not_file_found)
{
    std::string fileName = "points.txt";
    try
    {
        Matrix matrix(fileName);
    }
    catch (const NotFoundFileException &exception)
    {
        EXPECT_STREQ(exception.what(), "points.txt not found file");
    }
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}