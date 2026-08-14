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

void initTimeMatrix(int **timeMatrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        timeMatrix[i] = new int[size];
        for (size_t j = 0; j < size; j++)
        {
            timeMatrix[i][j] = -1;
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

void theGreatFlood(int **matrix, int **timeMatrix, int startRow, int startCol, const unsigned size, int time)
{
    // Check if we inside matrix
    if (startRow < 0 || startRow > size || startCol < 0 || startCol > size)
        return;
    // Check if matrix[i][j] = 0, if true, we have reached a wall, thus the water stops spreading
    if (matrix[startRow][startCol] == 0)
        return;

    if (timeMatrix[startRow][startCol] != -1 && timeMatrix[startRow][startCol] <= time)
    {
        return;
    }
    // for each element we move in all four directions
    theGreatFlood(matrix, timeMatrix, startRow, (startCol - 1), size, time + 1);
    theGreatFlood(matrix, timeMatrix, startRow, (startCol + 1), size, time + 1);
    theGreatFlood(matrix, timeMatrix, (startRow - 1), startCol, size, time + 1);
    theGreatFlood(matrix, timeMatrix, (startRow + 1), startCol, size, time + 1);
}

void freeMatrix(int **matrix, const unsigned size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    unsigned size;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;
    unsigned rowStart, colStart;
    std::cout << "Please enter starting row: " << std::endl;
    std::cin >> rowStart;
    std::cout << "Please enter starting col: " << std::endl;
    std::cin >> colStart;

    // 1-> hole, 0 -> solid
    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);

    // Catch edge case where matrix is invalid
    if (!isValidMatrix(matrix, size))
    {
        std::cout << " Invalid matrix!!" << std::endl;
        return 0;
    }

    // Helper matrix, responsible for the time
    int **timeMatrix = new int *[size];
    initTimeMatrix(timeMatrix, size);

    // Getting ready for the Great Flood
    int time = 0;
    theGreatFlood(matrix, timeMatrix, rowStart, colStart, size, time);

    return 0;
}