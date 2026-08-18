#include <iostream>

void myStrCpy(int *&dest, const int *src, const size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
}

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

void sortAscending(int *&str, const size_t len, size_t posStr)
{
    if (posStr >= len)
        return;

    int min = str[posStr];
    int posMin = posStr;

    for (size_t i = posStr; i < len; i++)
    {
        if (str[i] < min)
        {
            min = str[i];
            posMin = i;
        }
    }
    // after cycle ~~> we have min and its index!!
    // all left to do is swap posStr with min
    int temp = str[posStr];
    str[posStr] = min;
    str[posMin] = temp;

    sortAscending(str, len, posStr + 1);
}

bool isUnique(int *str, int elem, const size_t len)
{
    for (size_t i = 0; i < len; i++)

    {
        if (*str == elem)
            return false;

        str++;
    }
    return true;
}

int *constructStr(const int *const *matrix, const size_t size, size_t &newStrLen)
{
    int *helperContainer = new int[size * size];
    size_t newLen = 0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (i == j || (i + j == size - 1))
            {
                // we either on main diag on secondary diag
                if (isUnique(helperContainer, matrix[i][j], newLen))
                {
                    helperContainer[newLen] = matrix[i][j];
                    newLen++;
                }
            }
        }
    }
    sortAscending(helperContainer, newLen, 0);

    int *newStr = new int[newLen];
    myStrCpy(newStr, helperContainer, newLen);
    delete[] helperContainer;

    newStrLen = newLen;
    return newStr;
}

int main()
{
    size_t size;
    std::cout << "Please enter size ";
    std::cin >> size;
    std::cout << std::endl;

    int **matrix = new int *[size];
    std::cout << "Please enter matrix: " << std::endl;
    initMatrix(matrix, size);

    size_t newLen = 0;
    int *newStr = constructStr(matrix, size, newLen);
    std::cout << "New string is : ";
    for (size_t i = 0; i < newLen; i++)
    {
        std::cout << newStr[i] << " ";
    }
    std::cout << std::endl;

    delete[] newStr;
    freeMatrix(matrix, size);

    return 0;
}