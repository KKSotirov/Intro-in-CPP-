#include <iostream>

// count of square roots

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

void strcpy(char *&dest, const char *src)
{
    size_t len = strlen(src);
    delete[] dest;
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool isSquareRoot(const int num)
{
    for (size_t i = 0; i <= num / 2; i++)
    {
        if (num == i * i)
            return true;
    }
    return false;
}

bool isNum(const char ch)
{
    return ch >= '0' && ch <= '9';
}

int charToInt(const char ch)
{
    return ch - '0';
}

int getSquareRoots(const char *str)
{
    int count = 0;
    bool foundAny = false;
    unsigned currNumber;
    const char *ptr = str;
    while (*ptr)
    {
        if (isNum(*ptr))
        {
            foundAny = true;
            currNumber = 0;
            while (isNum(*ptr))
            {
                currNumber = currNumber * 10 + charToInt(*ptr);
                ptr++;
            }
            if (isSquareRoot(currNumber))
                count++;
        }
    }

    return count;
}
