#include <iostream>
void initMatrix(int **matrix, const size_t size)
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

void freeMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void myMatrixCpy(int **dest, int **src, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dest[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

void transposeMatrix(int **matrix, const size_t size)
{
    int **matrixCpy = new int *[size];
    myMatrixCpy(matrixCpy, matrix, size);
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = matrixCpy[j][i];
        }
    }
    freeMatrix(matrixCpy, size);
}

double calcAverageForRow(int **matrix, size_t row, const size_t size)
{
    double average = 0;
    for (size_t i = 0; i < size; i++)
    {
        average += matrix[row][i];
    }
    return (average / size);
}

double *avgEvenRows(int **matrix, const size_t size)
{
    double averageEvenRows[size / 2] = {0};
    int pos = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i % 2 == 0)
            {
                averageEvenRows[pos] = calcAverageForRow(matrix, i, size);
            }
        }
    }
    return averageEvenRows;
}

double calcAverageForCol(int **matrix, size_t col, const size_t size)
{
    double averageForCol = 0;
    for (size_t i = 0; i < size; i++)
    {
        averageForCol += matrix[i][col];
    }
    return (averageForCol / size);
}

double *avgUnevenCols(int **matrix, size_t size)
{
    double averageUnevenCols[size / 2] = {0};
    int pos = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (j % 2 == 1)
            {
                averageUnevenCols[pos] = calcAverageForCol(matrix, j, size);
            }
        }
    }
    return averageUnevenCols;
}

void printMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printStr(double *averages, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << averages << " , ";
    }
    std::cout << std::endl;
}

int main()
{
    size_t size;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;

    int **matrix = new int *[size];
    initMatrix(matrix, size);
    transposeMatrix(matrix, size);
    std::cout << "Even rows average:  " << std::endl;
    printStr(avgEvenRows(matrix, size), size / 2);
    std::cout << std::endl;
    std::cout << "Unven cols average:  " << std::endl;
    printStr(avgUnevenCols(matrix, size), size / 2);
    std::cout << std::endl;

    freeMatrix(matrix, size);
    return 0;
}
