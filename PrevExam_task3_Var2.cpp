#include <iostream>

void initMatrix(int **matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

bool isValidMatrix(const int *const *matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] > 1 || matrix[i][j] < 0)
                return false;
        }
    }
    return true;
}

unsigned moveLeft(int **matrix, unsigned startRow, unsigned StartCol, const unsigned size, const unsigned time)
{
    if (startRow >= 0)
    {
        if (matrix[startRow - 1][StartCol] == 1)
        {
            // We have found a hole!
        }
    }
}

unsigned moveRight(int **matrix, unsigned startRow, unsigned StartCol, const unsigned size, const unsigned time)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
        }
    }
}

unsigned moveUp(int **matrix, unsigned startRow, unsigned StartCol, const unsigned size, const unsigned time)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
        }
    }
}

unsigned moveDown(int **matrix, unsigned startRow, unsigned StartCol, const unsigned size, const unsigned time)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
        }
    }
}

unsigned theGreatFlood(int **matrix, unsigned startRow, unsigned startCol, const unsigned size, const unsigned timeElapsed)
{
    // Recursion
    // Water passes in all 4 directions   left, up, down, right
    // start: matrix[startRow][startCol]
}
int main()
{
    unsigned size;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;
    unsigned rowStart, colStart;
    std::cout << "Please enter starting row: " << std::endl;
    std::cin >> rowStart;
    std::cout << "Please enter starting col: " << std::endl;
    std::cin >> colStart;

    // 1-> hole, 0 -> solid
    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);

    // Catch edge case where matrix is invalid
    if (!isValidMatrix(matrix, size))
    {
        std::cout << " Invalid matrix!!" << std::endl;
        return 0;
    }

    //

    return 0;
}