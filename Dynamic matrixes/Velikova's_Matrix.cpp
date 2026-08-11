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
}