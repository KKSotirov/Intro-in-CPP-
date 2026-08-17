#include <iostream>

// returns a new string with only unique elements

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

void myStrCpy(char *&dest, const char *src, const size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int charToInt(const char ch)
{
    return static_cast<int>(ch);
}

char *uniqueStr(const char *str)
{
    size_t len = strlen(str);
    char *helperContainer = new char[len + 1];
    size_t newLen = 0;
    int asciiIndexes[256] = {0}; // all symbols

    // count occurances
    for (size_t i = 0; i < len; i++)
    {
        asciiIndexes[charToInt(str[i])]++;
    }

    for (size_t i = 0; i < len; i++)
    {
        if (asciiIndexes[charToInt(str[i])] == 1)
        {
            helperContainer[newLen] = str[i];
            newLen++;
        }
    }
    char *newStr = new char[newLen + 1];
    myStrCpy(newStr, helperContainer, newLen);

    delete[] helperContainer;
    return newStr;
}

int main()
{
    const char *testStr = "They shall see"; // ya
    char *str = nullptr;
    strcpy(str, testStr);
    char *unique = uniqueStr(str);
    std::cout << "New string is : " << unique << std::endl;

    delete[] unique;
    delete[] str;
    delete[] testStr;
    return 0;
}