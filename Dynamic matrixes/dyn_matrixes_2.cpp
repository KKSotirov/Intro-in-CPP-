#include <iostream>

int **createPascalMatrix(const unsigned rows)
{
    int **pascalMatrix = new int *[rows];
    for (size_t i = 0; i < rows; i++)
    {
        pascalMatrix[i] = new int[i + 1];

        pascalMatrix[i][0] = 1;
        pascalMatrix[i][i] = 1;

        for (size_t j = 1; j < i; j++)
        {
            pascalMatrix[i][j] = pascalMatrix[i - 1][j - 1] + pascalMatrix[i - 1][j];
        }
    }

    return pascalMatrix;
}

void printPascalMatrix(const int *const *matrix, unsigned n)
{
    if (!matrix)
        return;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void freePascalTriangle(int **matrix, unsigned n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    unsigned rows;
    std::cout << "Please enter the number of rows: " << std::endl;
    std::cin >> rows;
    int **matrix = createPascalMatrix(rows);
    printPascalMatrix(matrix, rows);
    freePascalTriangle(matrix, rows);
    return 0;
}