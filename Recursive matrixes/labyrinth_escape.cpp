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

bool isValidMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] != 1 && matrix[i][j] != 0)
                return false;
        }
    }
    return true;
}

bool areValidIndexes(int startX, int startY, int endX, int endY, const size_t size)
{
    if (startX < size && startY < size && endX < size && endY < size)
        if (startX >= 0 && startY >= 0 && endX >= 0 && endY >= 0)
            return true;
    return false;
}

void schizophrenicEscape(int **matrix, const size_t size, int x, int y, int currentSteps)
{
    // BASE CASES:
    // 1. Outside matrix
    if (x < 0 || x >= size || y < 0 || y >= size)
        return;

    // 2. We hit a wall
    if (matrix[x][y] == 0)
        return;

    // 3. ELSE ~~> We are in a corridor!
    int stepsMade = currentSteps + 2;

    // 4. If we have already reached this point in the labyrinth, we stop our scizophrenic spinning
    if (matrix[x][y] > 1 && matrix[x][y] <= stepsMade)
        return;

    // 5. ELSE ~~> this is the first time we are this far in the labyrinth (or so we think ?!?!?)
    matrix[x][y] = stepsMade;

    // 6. Call recursively
    schizophrenicEscape(matrix, size, x - 1, y, currentSteps + 1); // UP
    schizophrenicEscape(matrix, size, x + 1, y, currentSteps + 1); // DOWN
    schizophrenicEscape(matrix, size, x, y - 1, currentSteps + 1); // LEFT
    schizophrenicEscape(matrix, size, x, y + 1, currentSteps + 1); // RIGHT
}

int analyseMentalPatient(int **matrix, const size_t size, int startX, int startY, int endX, int endY)
{
    // We fill the matrix, by letting our mental patient walk
    schizophrenicEscape(matrix, size, startX, startY, 0);

    // Our patient has not been able to reach the end
    if (matrix[endX][endY] == 0 || matrix[endX][endY] == 1)
        return -1;

    return matrix[endX][endY] - 2;
}

int main()
{
    size_t size;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;
    int startX, startY, endX, endY;

    std::cout << "Please enter starting coordinates: X,Y = ";
    std::cin >> startX >> startY;
    std::cout << std::endl;

    std::cout << "Please enter ending coordinates: X,Y = ";
    std::cin >> endX >> endY;
    std::cout << std::endl;

    int **matrix = new int *[size];
    std::cout << "Please enter labyrinth: " << std::endl;
    initMatrix(matrix, size);

    // catch edge case ~> invalid matrix
    if (!isValidMatrix(matrix, size))
    {
        std::cout << "Invalid matrix!!!" << std::endl;
        freeMatrix(matrix, size);
        return 0;
    }

    // catch edge case ~> invalid indexes
    if (!areValidIndexes(startX, startY, endX, endY, size))
    {
        std::cout << "Invalid indexes!!!" << std::endl;
        freeMatrix(matrix, size);
        return 0;
    }

    int stepsNeeded = analyseMentalPatient(matrix, size, startX, startY, endX, endY);
    if (stepsNeeded == -1)
        std::cout << "This labyrinth has proven to be inescapable! " << std::endl;
    else
        std::cout << "Shortest path to the escape: " << stepsNeeded << std::endl;

    freeMatrix(matrix, size);
    return 0;
}