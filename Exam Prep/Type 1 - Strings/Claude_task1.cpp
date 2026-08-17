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

bool isNumber(const char asciiIndex)
{
    return (asciiIndex >= '0') && (asciiIndex <= '9');
}

char *getNumbers(const char *str)
{
    size_t len = strlen(str);
    char *helperContainer = new char[len + 1];
    size_t newLen = 0;
    const char *ptr = str;

    while (*ptr)
    {
        if (isNumber(*ptr))
        {
            *helperContainer = *ptr;
            helperContainer++;
            newLen++;
        }
        ptr++;
    }
    *helperContainer = '\0';
    helperContainer -= newLen;

    char *newStr = new char[newLen + 1];
    myStrCpy(newStr, helperContainer, newLen);
    delete[] helperContainer;

    return newStr;
}

int main()
{
    const char *testStr = "Mak3 th3 V01C3s Sto0pP!";
    char *str = nullptr;
    strcpy(str, testStr);
    char *numberStr = getNumbers(str);
    std::cout << "Numbers in string are: " << numberStr << std::endl;

    delete[] str;
    delete[] testStr;
    delete[] numberStr;

    return 0;
}