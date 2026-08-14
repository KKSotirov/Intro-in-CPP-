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

int max(const int num1, const int num2, const int num3, const int num4)
{
    if (num1 >= num2 && num1 >= num3 && num1 >= num4)
        return num1;
    if (num2 >= num1 && num2 >= num3 && num2 >= num4)
        return num2;
    if (num3 >= num1 && num3 >= num2 && num3 >= num4)
        return num3;
    else
        return num4;
}
void theGreatFlood(int **matrix, const size_t size, int x, int y, int currentTime)
{
    // BASE CASES:
    //  1. Outside matrix
    if (x < 0 || x >= size || y < 0 || y >= size)
        return;

    // 2. Solid wall ~> '0'
    if (matrix[x][y] == 0)
        return;

    // ELSE : WE HAVE FOUND A HOLE !
    int arrivalHere = currentTime + 2;

    // 3. We have already reached this place in a much shorter time
    if (matrix[x][y] > 1 && matrix[x][y] < arrivalHere)
        return;

    // 4. If we have arrived faster than previously (or for the first time) we write the timeElapsed to get to here
    matrix[x][y] = arrivalHere;

    // 5. Call recursively, in order to fill the whole matrix with the time elapsed to get to each hole/ to fill it
    theGreatFlood(matrix, size, x - 1, y, currentTime + 1);
    theGreatFlood(matrix, size, x + 1, y, currentTime + 1);
    theGreatFlood(matrix, size, x, y - 1, currentTime + 1);
    theGreatFlood(matrix, size, x, y + 1, currentTime + 1);
}

int analyseTheGreatFlood(int **matrix, const size_t size, int x, int y)
{
    theGreatFlood(matrix, size, x, y, 0);
    int timeElapsed = 0;
    // lets check if there are empty boxes, if yes ~> we return -1;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (matrix[i][j] == 1)
                return -1;
            if (matrix[i][j] > timeElapsed)
                timeElapsed = matrix[i][j];
        }
    }

    return timeElapsed - 2;
}

int main()
{
    size_t size;
    std::cout << "Please enter size of matrix: " << std::endl;
    std::cin >> size;
    int startX, startY;
    std::cout << "Please enter starting row: " << std::endl;
    std::cin >> startX;
    std::cout << "Please enter starting col: " << std::endl;
    std::cin >> startY;

    // 1-> hole, 0 -> solid
    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);

    // Catch edge case where matrix is invalid
    if (!isValidMatrix(matrix, size))
    {
        std::cout << " Invalid matrix!!" << std::endl;
        freeMatrix(matrix, size);
        return 0;
    }

    // Getting ready for the Great Flood
    int timeElapsed = analyseTheGreatFlood(matrix, size, startX, startY);
    if (timeElapsed == -1)
        std::cout << "We have failed with filling the whole matrix!" << std::endl;
    else
        std::cout << "We have successfully filled the whole matrix! Time elapsed = " << timeElapsed << std::endl;

    freeMatrix(matrix, size);
    return 0;
}