#include <iostream>
const size_t MATRIX_DIMENSIONS = 2;

void innitMatrix(int **matrix)
{
    for (size_t i = 0; i < MATRIX_DIMENSIONS; i++)
    {
        matrix[i] = new int[MATRIX_DIMENSIONS];
        for (size_t j = 0; j < MATRIX_DIMENSIONS; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(const int *const *matrix)
{
    for (unsigned i = 0; i < MATRIX_DIMENSIONS; i++)
    {
        for (unsigned j = 0; j < MATRIX_DIMENSIONS; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int **matrix)
{
    for (unsigned i = 0; i < MATRIX_DIMENSIONS; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int **getInverse2x2Int(const int *const *A)
{
    int det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);

    if (det == 0)
    {
        std::cout << "The entered matrix has a determinant equal to 0! Thus, no inverted matrix exists!!!" << std::endl;
        return nullptr;
    }

    int **inversedMatrix = new int *[MATRIX_DIMENSIONS];
    for (size_t i = 0; i < MATRIX_DIMENSIONS; i++)
    {
        inversedMatrix[i] = new int[MATRIX_DIMENSIONS];
    }

    inversedMatrix[0][0] = A[1][1] / det;
    inversedMatrix[0][1] = -A[0][1] / det;
    inversedMatrix[1][0] = -A[1][0] / det;
    inversedMatrix[1][1] = A[0][0] / det;

    return inversedMatrix;
}

int main()
{
    int **matrix = new int *[MATRIX_DIMENSIONS];
    innitMatrix(matrix);
    int **inversedMatrix = getInverse2x2Int(matrix);
    if (inversedMatrix != nullptr)
    {
        std::cout << "Inverted matrix: " << std::endl;
        printMatrix(inversedMatrix);
        freeMatrix(inversedMatrix);
    }
    freeMatrix(matrix);
    return 0;
}