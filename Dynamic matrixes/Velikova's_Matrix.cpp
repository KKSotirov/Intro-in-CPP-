#include <iostream>

void initMatrix(int **matrix, const size_t size)
{
    unsigned currNumber = 1;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = currNumber;
            currNumber++;
        }
    }
    // filling the og matrix
}

void initSubMatrix(const int *const *matrix, int **subMatrix, const size_t sizeSubMatrix, int startPosRow, int startPosCol)
{

    for (size_t i = 0; i < sizeSubMatrix; i++)
    {
        subMatrix[startPosRow] = new int[sizeSubMatrix];
        for (size_t j = 0; j < sizeSubMatrix; j++)
        {
            subMatrix[i][j] = matrix[i + startPosRow][j + startPosCol];
            // startPosRow++;
            // startPosCol++;
        }
    }
}

void rotate90DegreesRight(int **matrix, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = matrix[size - 1 - j][i];
        }
    }
}

void rotate90DegreesLeft(int **matrix, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            matrix[i][j] = matrix[j][size - 1 - i];
        }
    }
}
void matrixCpy(int **dest, int **src, unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            dest[i][j] = src[i][j];
        }
    }
}

void freeMatrix(int **matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
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

                // Валидация дали съседът е вътре в границите на Q4 (k x k)
                if (nextRow >= 0 && nextRow < (int)size && nextCol >= 0 && nextCol < (int)size)
                {
                    neighborSum += matrix[nextRow][nextCol]; // Четем от ОРИГИНАЛА
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
    size_t sizeSubMatrix = size / 2;
    size_t startRow = 0;
    size_t startCol = 0;

    int **subMatrix1 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix1, sizeSubMatrix, startRow, startCol); // Q1
    startCol += sizeSubMatrix;

    int **subMatrix2 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix2, sizeSubMatrix, startRow, startCol); // Q2
    startCol -= sizeSubMatrix;
    startRow += sizeSubMatrix;

    int **subMatrix3 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix3, sizeSubMatrix, startRow, startCol); // Q3
    startCol += sizeSubMatrix;

    int **subMatrix4 = new int *[sizeSubMatrix];
    initSubMatrix(matrix, subMatrix4, sizeSubMatrix, startRow, startCol); // Q4
    // Have successfully disassembled matrix into four quadrants

    // Q1 ~~> Transpose
    for (size_t i = 0; i < sizeSubMatrix; i++)
    {
        for (size_t j = 0; j < sizeSubMatrix; j++)
        {
            subMatrix1[i][j] = subMatrix1[j][i];
        }
    }

    // Q2 ~~> Rotate 90 degrees right:
    rotate90DegreesRight(subMatrix2, sizeSubMatrix);
    // Q3 ~~> Rotate 90 degrees left:
    rotate90DegreesLeft(subMatrix3, sizeSubMatrix);
    // Q4 ~~> Summing neighboring elements
    transformQ4(subMatrix4, size);
}