#include <iostream>

void fillMatrix(int **matrix, const unsigned len)
{
    // тук по копие на матрицата ли работим? Ако тук въведем стойност за всяко поле на матрицата, то то ще се запизи ли извън scope-a на функцията?
    for (size_t i = 0; i < len; i++)
    {
        matrix[i] = new int[len];
        for (size_t j = 0; j < len; j++)
        {
            std::cout << "Please enter value for element on row: " << i << " and col: " << j << std::endl;
            std::cin >> matrix[i][j];
        }
        //        matrix[i][len] = '\0';  // но това не е вярно, тъй като работим с int матрици... трябва ли да се грижа за полседният елемент по някакъв специален начин или Int матриците не го изискват?
    }
}

// Lets rotate 90 degrees Left
int **rotate90DegreesLeft(const int *const *matrix, const unsigned len)
{
    int **rotatedMatrix = new int *[len];
    for (size_t i = 0; i < len; i++)
    {
        rotatedMatrix[i] = new int[len];
        for (size_t j = 0; j < len; j++)
        {
            rotatedMatrix[i][j] = matrix[j][len - 1 - i];
        }
    }
    return rotatedMatrix;
}

void freeMatrix(int **matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(const int *const *matrix, const unsigned len)
{
    std::cout << "Printing matrix:" << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    unsigned len;
    std::cout << "Please enter matrix dimensions: " << std::endl;
    std::cin >> len;

    int **matrix = new int *[len];
    fillMatrix(matrix, len);
    int **rotatedMatrix = rotate90DegreesLeft(matrix, len);
    printMatrix(rotatedMatrix, len);
    freeMatrix(matrix, len);
    freeMatrix(rotatedMatrix, len);
    return 0;
}