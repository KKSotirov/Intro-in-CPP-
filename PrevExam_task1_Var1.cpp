#include <iostream>

unsigned calcMatrixSize(int **matrix)
{
    unsigned col = 0;
    unsigned size = 0;
    while (matrix[0][col] >= 0 && matrix[0][col] <= 9)
    {
        col++;
        size++;
    }
    return size;
}

int abs(int num)
{
    if (num < 0)
        num *= (-1);
    return num;
}

bool isValidMatrix(const int *const *matrix, const unsigned size)
{
    return (size > 3) && (size % 2 != 0);
}

void initSubMatrix(int **matrixDest, const int *const *matrixSrc, const unsigned sizeSubMatrix, const unsigned startRow, const unsigned startCol)
{
    for (size_t i = 0; i < sizeSubMatrix; i++)
    {
        matrixDest[i] = new int[sizeSubMatrix];
        for (size_t j = 0; j < sizeSubMatrix; j++)
        {
            matrixDest[i][j] = matrixSrc[i + startRow][j + startCol];
        }
    }
}

void freeMatrix(int **matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int sumMainDiag(int **matrix, const unsigned size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
    {
        sum += matrix[i][i];
    }
    return sum;
}

bool adjMatrix(const int *const *matrix, const unsigned size)
{
    if (!isValidMatrix(matrix, size))
        return false;

    int middleIndex = size / 2;
    unsigned sizeSubMatrix = size / 2;

    // Initializing the 4 submatrixes
    int **subMatrix1 = new int *[sizeSubMatrix];
    initSubMatrix(subMatrix1, matrix, sizeSubMatrix, 0, 0);
    int **subMatrix2 = new int *[sizeSubMatrix];
    initSubMatrix(subMatrix2, matrix, sizeSubMatrix, 0, middleIndex + 1);
    int **subMatrix3 = new int *[sizeSubMatrix];
    initSubMatrix(subMatrix3, matrix, sizeSubMatrix, middleIndex + 1, 0);
    int **subMatrix4 = new int *[sizeSubMatrix];
    initSubMatrix(subMatrix4, matrix, sizeSubMatrix, middleIndex + 1, middleIndex + 1);

    // Calc all sums
    int sum1 = sumMainDiag(subMatrix1, sizeSubMatrix);
    int sum2 = sumMainDiag(subMatrix2, sizeSubMatrix);
    int sum3 = sumMainDiag(subMatrix3, sizeSubMatrix);
    int sum4 = sumMainDiag(subMatrix4, sizeSubMatrix);

    // Freeing all memory
    freeMatrix(subMatrix1, sizeSubMatrix);
    freeMatrix(subMatrix2, sizeSubMatrix);
    freeMatrix(subMatrix3, sizeSubMatrix);
    freeMatrix(subMatrix4, sizeSubMatrix);

    return (sum1 == sum2) && (sum1 == sum3) && (sum3 == sum4);
}

int main()
{
    unsigned size;
    std::cout << "Please enter matrix size " << std::endl;
    std::cin >> size;

    int **matrix = new int *[size];
    std::cout << "Please enter values for matrix: " << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    if (adjMatrix(matrix, size))
        std::cout << "Yes, the main diagonals of the 4 submatrixes are equal!" << std::endl;
    else
        std::cout << "No, the main diagonal of al the 4 submatrixes are not equal!" << std::endl;

    freeMatrix(matrix, size);
    return 0;
}