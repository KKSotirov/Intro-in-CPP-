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

int calcRowSum(const int *const *matrix, const size_t currRow, const size_t cols)
{
    int rowSum = 0;
    for (size_t i = 0; i < cols; i++)
    {
        rowSum += matrix[currRow][i];
    }
    return rowSum;
}

void sortDescending(int *&str, const size_t len, int startingPos)
{
    if (startingPos == len)
        return;

    int max = str[startingPos];
    int indexMax = startingPos;
    for (size_t i = 0; i < len; i++)
    {
        // FINDING MAX
        if (str[i] > max)
        {
            max = str[i];
            indexMax = i;
        }
    }
    int tmp = str[startingPos];
    str[startingPos] = max;
    str[indexMax] = tmp;
    sortDescending(str, len, startingPos + 1);
}

int *getRowSums(const int *const *matrix, const size_t rows, const size_t cols)
{
    int *sumsDescending = new int[rows];
    int currRowSum = 0;
    for (size_t i = 0; i < rows; i++)
    {
        currRowSum = calcRowSum(matrix, i, cols);
        *sumsDescending = currRowSum;
        sumsDescending++;
    }
    sumsDescending -= rows;
    // we have now written all of the sums
    // now all we have to do is sort them descending
    sortDescending(sumsDescending, rows, 0);

    return sumsDescending;
}