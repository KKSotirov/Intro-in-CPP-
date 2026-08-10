#include <iostream>

int **transposeMatrix(const int *const *matrix, unsigned rows, unsigned cols)
{
    int **transposedMatrix = new int *[cols];
    for (size_t i = 0; i < cols; i++)
    {
        transposedMatrix[i] = new int[rows];
        for (size_t j = 0; j < rows; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }

    return transposedMatrix;
}

void freeMatrix(int **matrix, unsigned rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(const int *const *matrix, unsigned rows, unsigned cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    unsigned rows, cols;
    std::cout << "Please enter number of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "Please enter number of cols: " << std::endl;
    std::cin >> cols;

    int **matrix = new int *[rows];
    std::cout << "Enter matrix elements:" << std::endl;
    for (size_t i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (size_t j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    int **transposedMatrix = transposeMatrix(matrix, rows, cols);
    std::cout << "Transposed Matrix:" << std::endl;
    printMatrix(transposedMatrix, cols, rows);

    freeMatrix(matrix, rows);
    freeMatrix(transposedMatrix, cols);

    return 0;
}