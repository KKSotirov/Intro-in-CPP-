#include <iostream>
const char MAX_WORD_LENGTH = 100;

int strlen(char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void myStrCpy(char *&dest, const char *src, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        dest[i] = src[i];
    }
    dest[size] = '\0';
}

void initMatrix(char **matrix, const size_t size)
{
    char temp[101];
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> temp;
        size_t len = strlen(temp);
        matrix[i] = new char[len + 1];
        myStrCpy(matrix[i], temp, len);
    }
}

bool isSmallLetter(const char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

bool isValidMatrix(const char *const *matrix, const size_t size)
{
    if (size > 100)
        return false;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; matrix[i][j] != '\0'; j++)
        {
            if (isSmallLetter(matrix[i][j]) == false)
                return false;
        }
    }
    return true;
}

void freeMatrix(char **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printStr(const char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}

char *compressString(char *str)
{
    size_t len = strlen(str);
    char *ptr = str;
    char *helperContainer = new char[MAX_WORD_LENGTH + 1];
    size_t newLen = 0;
    while (*str)
    {
        if (newLen == 0 || helperContainer[newLen - 1] != *str)
        {
            helperContainer[newLen] = *str;
            newLen++;
        }
        str++;
    }
    helperContainer[newLen] = '\0';
    delete[] ptr;

    char *newStr = new char[newLen + 1];
    myStrCpy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    std::cout << "Lets check each compressed strings: " << std::endl;
    printStr(newStr);
    std::cout << std::endl;
    return newStr;
}

void compressMatrix(char **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = compressString(matrix[i]);
    }
}

void printBackwards(const char *const *matrix, const size_t size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << matrix[i] << std::endl;
    }
}

int main()
{
    size_t countWords;
    std::cout << "Please enter number of words: " << std::endl;
    std::cin >> countWords;

    char **matrix = new char *[countWords + 1];
    std::cout << "Please enter elements of matrix ~> different words: " << std::endl;
    initMatrix(matrix, countWords);

    if (!isValidMatrix(matrix, countWords))
    {
        std::cout << "Incorrect data for matrix!" << std::endl;
        freeMatrix(matrix, countWords);
        return 0;
    }

    // Else:
    compressMatrix(matrix, countWords);
    printBackwards(matrix, countWords);
    freeMatrix(matrix, countWords);
}