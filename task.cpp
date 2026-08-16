#include <iostream>

void initMatrix(int **matrix, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void freeMatrix(int **matrix, const size_t rows, const size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isValidCol(const int *const *matrix, const size_t row, const size_t col)
{
    bool containsNegElement = false;
    int sum = 0;
    for (size_t i = 0; i < row; i++)
    {
        if (matrix[i][col] < 0)
            containsNegElement = true;
        sum += matrix[i][col];
    }
    return containsNegElement && (sum > 0);
}

void copyCol(int **helperMatrix, const int *const *matrix, const int currCol, const size_t j, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        helperMatrix[i][currCol] = matrix[i][j];
    }
}

int **extractValidColumns(const int *const *matrix, size_t rows, size_t cols, size_t &outCols)
{
    int **helperMatrix = new int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        helperMatrix[i] = new int[cols];
    }

    int currCol = 0;

    for (size_t j = 0; j < cols; j++)
    {
        if (isValidCol(matrix, rows, j))
        {
            copyCol(helperMatrix, matrix, currCol, j, rows);
            currCol++;
        }
    }

    if (currCol == 0)
    {
        outCols = 0;
        freeMatrix(helperMatrix, rows, cols);
        return nullptr;
    }

    // copy helperMatrix into new matrix
    int **newMatrix = new int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        newMatrix[i] = new int[currCol];
        for (size_t j = 0; j < currCol; j++)
        {
            newMatrix[i][j] = helperMatrix[i][j];
        }
    }
    freeMatrix(helperMatrix, rows, currCol);

    outCols = currCol;
    return newMatrix;
}