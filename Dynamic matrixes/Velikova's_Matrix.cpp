#include <iostream>
#include <utility>

void freeMatrix(int **matrix, const size_t len)
{
    if (!matrix)
        return;
    for (size_t i = 0; i < len; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void matrixCpy(int **dest, int **src, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

void initSubMatrix(const int *const *matrix, int **subMatrix, size_t sizeSubMatrix, size_t startPosRow, size_t startPosCol)
{
    for (size_t i = 0; i < sizeSubMatrix; i++)
    {
        subMatrix[i] = new int[sizeSubMatrix];
        for (size_t j = 0; j < sizeSubMatrix; j++)
        {
            subMatrix[i][j] = matrix[i + startPosRow][j + startPosCol];
        }
    }
}

void transposeMatrix(int **matrix, size_t size)
{
    int **temp = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        temp[i] = new int[size];
    }

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            temp[i][j] = matrix[j][i];
        }
    }

    matrixCpy(matrix, temp, size);
    freeMatrix(temp, size);
}

void rotate90DegreesRight(int **matrix, size_t size)
{
    int **temp = new int *[size];
    for (size_t i = 0; i < size; i++)
        temp[i] = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            temp[i][j] = matrix[size - 1 - j][i];
        }
    }
    matrixCpy(matrix, temp, size);
    freeMatrix(temp, size);
}

void rotate90DegreesLeft(int **matrix, size_t size)
{
    int **temp = new int *[size];
    for (size_t i = 0; i < size; i++)
        temp[i] = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            temp[i][j] = matrix[j][size - 1 - i];
        }
    }
    matrixCpy(matrix, temp, size);
    freeMatrix(temp, size);
}

void transformQ4(int **matrix, size_t size)
{
    int **helpercontainer = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        helpercontainer[i] = new int[size];
    }

    int dRow[] = {-1, 1, 0, 0};
    int dCol[] = {0, 0, -1, 1};

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            int neighborSum = 0;
            for (size_t dir = 0; dir < 4; dir++)
            {
                int nextRow = (int)i + dRow[dir];
                int nextCol = (int)j + dCol[dir];

                if (nextRow >= 0 && nextRow < (int)size && nextCol >= 0 && nextCol < (int)size)
                {
                    neighborSum += matrix[nextRow][nextCol];
                }
            }
            helpercontainer[i][j] = neighborSum;
        }
    }
    matrixCpy(matrix, helpercontainer, size);
    freeMatrix(helpercontainer, size);
}

int **processAndReduceMatrix(const int *const *matrix, size_t size, size_t &outSize)
{
    // Validating data
    if (!matrix || size == 0 || size % 2 != 0)
    {
        outSize = 0;
        return nullptr;
    }

    size_t sizeSubMatrix = size / 2;
    outSize = sizeSubMatrix;

    // Building our 4 quadrants
    int **subMatrix1 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix1, sizeSubMatrix, 0, 0);

    int **subMatrix2 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix2, sizeSubMatrix, 0, sizeSubMatrix);

    int **subMatrix3 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix3, sizeSubMatrix, sizeSubMatrix, 0);

    int **subMatrix4 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix4, sizeSubMatrix, sizeSubMatrix, sizeSubMatrix);

    // Transforming the quadrants
    transposeMatrix(subMatrix1, sizeSubMatrix);
    rotate90DegreesRight(subMatrix2, sizeSubMatrix);
    rotate90DegreesLeft(subMatrix3, sizeSubMatrix);
    transformQ4(subMatrix4, sizeSubMatrix);

    // Freeing the memory
    freeMatrix(subMatrix1, sizeSubMatrix);
    freeMatrix(subMatrix2, sizeSubMatrix);
    freeMatrix(subMatrix3, sizeSubMatrix);
    freeMatrix(subMatrix4, sizeSubMatrix);
}