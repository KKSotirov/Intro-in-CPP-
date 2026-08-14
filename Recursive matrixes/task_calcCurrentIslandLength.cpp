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

bool isValidMatrix(const int *const *matrix, const size_t size)
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

void freeMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int calcCurrentIslandChain(int **matrix, const size_t size, int x, int y)
{
    // Base cases:
    // 1. Outside of matrix
    if (x < 0 || x >= size || y < 0 || y >= size)
        return 0;
    // 2. Water
    if (matrix[x][y] == 0)
        return 0;

    // ELSE ~> WE HAVE FOUND LANDD!!!
    int currIslandChainLength = 1;
    matrix[x][y] = 0; // we sink this place in order to not count it again

    // Call recursively
    currIslandChainLength += calcCurrentIslandChain(matrix, size, x - 1, y); // UP
    currIslandChainLength += calcCurrentIslandChain(matrix, size, x + 1, y); // DOWN
    currIslandChainLength += calcCurrentIslandChain(matrix, size, x, y - 1); // LEFT
    currIslandChainLength += calcCurrentIslandChain(matrix, size, x, y + 1); // RIGHT

    return currIslandChainLength;
}

int main()
{
    size_t size;
    int startX, startY;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;
    std::cout << "Please enter starting coordinates: X,Y " << std::endl;
    std::cin >> startX >> startY;

    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);

    // edge case: start coords are in the middle of the ocean
    if (matrix[startX][startY] == 0)
        std::cout << "We are in the middle of the ocean my friend, shit's so cooked..." << std::endl;

    else
    {
        int currIslandLength = calcCurrentIslandChain(matrix, size, startX, startY);
        std::cout << "Current island chain is this much long: " << currIslandLength << std::endl;
    }

    freeMatrix(matrix, size);
    return 0;
}