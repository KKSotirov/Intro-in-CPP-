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

void strcpy(char *&dest, const char *str)
{
    size_t len = strlen(str);
    delete[] dest;
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = str[i];
    }
    dest[len] = '\0';
}

void freeMatrix(int **matrix, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool isLetter(const char ch)
{
    return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'));
}

bool hasConsecutiveLetters(char *str)
{
    char prevLetter = '\0';
    while (*str)
    {
        while (isLetter(*str))
        {
            if (prevLetter == *str)
                return true;
            else
            {
                prevLetter = *str;
                str++;
            }
        }
    }
    return false;
}

void writeDownLetters()
{
}
