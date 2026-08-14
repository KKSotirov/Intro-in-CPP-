#include <iostream>

void initMatrix(int **matrix, const unsigned size)
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

bool isValidMatrix(const int *const *matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] > 1 || matrix[i][j] < 0)
                return false;
        }
    }
    return true;
}

void freeMatrix(int **matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int calcIslandChain(int **matrix, int row, int col, const size_t size)
{
    // Recursive base:
    // 1. We are outside matrix
    if (row < 0 || row >= size || col < 0 || col >= size)
        return 0;

    // 2. Curr element is water, we skip
    if (matrix[row][col] == 0)
        return 0;

    // 3. Curr element is an island, we make it water and increment current chain length

    int longestIslandChain = 1;
    matrix[row][col] = 0;

    // 5. Call recursively
    longestIslandChain += calcIslandChain(matrix, row - 1, col, size); // calc UP
    longestIslandChain += calcIslandChain(matrix, row + 1, col, size); // calc DOWN
    longestIslandChain += calcIslandChain(matrix, row, col - 1, size); // calc LEFT
    longestIslandChain += calcIslandChain(matrix, row, col + 1, size); // calc RIGHT

    return longestIslandChain;
}

int findBiggestIslandChain(int **matrix, const size_t size)
{
    int currChainLength = 0;
    int max = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
            {
                currChainLength = calcIslandChain(matrix, i, j, size);
                if (currChainLength > max)
                    max = currChainLength;
            }
        }
    }
    return max;
}

int main()
{
    size_t size;
    std::cout << "Please enter size: " << std::endl;
    std::cin >> size;

    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);
    int longestIslanChain = findBiggestIslandChain(matrix, size);
    std::cout << "The longest island chain is this much long: " << longestIslanChain << std::endl;

    freeMatrix(matrix, size);
}