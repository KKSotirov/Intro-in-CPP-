#include <iostream>

#include <iostream>

int **rotateMatrix90(const int *const *matrix, unsigned n)
{
    int **rotatedMatrix = new int *[n];
    for (size_t i = 0; i < n; i++)
    {
        rotatedMatrix[i] = new int[n];
        for (size_t j = 0; j < n; j++)
        {
            rotatedMatrix[i][j] = matrix[n - 1 - j][i];
        }
    }

    return rotatedMatrix;
}

void freeMatrix(int **matrix, unsigned n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(const int *const *matrix, unsigned n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
