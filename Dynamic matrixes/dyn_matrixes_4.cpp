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

int main()
{
    unsigned n = 3;

    // Creating test matrix 3x3
    int **matrix = new int *[n];
    int counter = 1;
    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
        for (size_t j = 0; j < n; j++)
        {
            matrix[i][j] = counter++;
        }
    }

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix, n);

    int **rotated = rotateMatrix90(matrix, n);

    std::cout << "\nRotated Matrix (90 degrees clockwise):" << std::endl;
    printMatrix(rotated, n);

    freeMatrix(matrix, n);
    freeMatrix(rotated, n);

    return 0;
}