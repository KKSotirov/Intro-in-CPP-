#include <iostream>

size_t strlen(const char *str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

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

void freeMatrix(int **matrix, const size_t rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int getLen(int num)
{
    size_t len = 0;
    while (num > 0)
    {
        num /= 10;
        len++;
    }
    return len;
}

char *intToStr(int num)
{
    int numLen = getLen(num);
    char *numb = new char[numLen + 1];

    for (int i = numLen; i > 0; i--)
    {
        numb[i - 1] = (num % 10) + '0';
        num /= 10;
    }
    numb[numLen] = '\0';

    return numb;
}

bool isPalindrom(const char *num)
{
    size_t len = strlen(num);
    if (len == 1)
        return true;

    for (size_t i = 0; i < len / 2; i++)
    {
        if (num[i] != num[len - 1 - i])
            return false;
    }
    return true;
}

int strToInt(const char *num)
{
    size_t len = strlen(num);
    int currNumber = 0;
    while (*num)
    {
        currNumber = currNumber * 10 + *num;
    }
    return currNumber;
}

int *getPalindromNumbersStr(int **matrix, const size_t rows, const size_t cols, size_t &palindromStrLen)
{
    size_t palindromCount = 0;
    int helperMaxSize = rows * cols;
    int *helperContainter = new int[helperMaxSize];

    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            char *numToStr = intToStr(matrix[i][j]);
            if (isPalindrom(numToStr))
            {
                helperContainter[palindromCount] = matrix[i][j];
                palindromCount++;
            }
            delete[] numToStr;
        }
    }
    int *palindromStr = new int[palindromCount];
    for (size_t i = 0; i < palindromCount; i++)
    {
        palindromStr[i] = helperContainter[i];
    }
    delete[] helperContainter;

    palindromStrLen = palindromCount;
    return palindromStr;
}

void printStr(const int *str, const size_t len)
{
    for (size_t i = 0; i < len - 1; i++)
    {
        std::cout << str[i] << ", ";
    }
    std::cout << str[len - 1];
    std::cout << std::endl;
}

int main()
{
    size_t rows, cols;
    std::cout << "Please enter rows and cols: ";
    std::cin >> rows >> cols;
    std::cout << std::endl;

    int **matrix = new int *[rows];
    std::cout << "Please enter values of matrix: " << std::endl;
    initMatrix(matrix, rows, cols);

    size_t palindromLen = 0;
    int *palindromStr = getPalindromNumbersStr(matrix, rows, cols, palindromLen);

    std::cout << "Printing palindrom numbers: " << std::endl;
    printStr(palindromStr, palindromLen);

    delete[] palindromStr;
    freeMatrix(matrix, rows);
    return 0;
}