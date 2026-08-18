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

bool isEvenCount(const int len)
{
    return len % 2 == 0;
}

bool isLetter(const char ch)
{
    return (ch >= 'a') && (ch <= 'z');
}

char *returnEven(const char *str)
{
    size_t len = strlen(str);
    size_t newLen = 0;
    char *helperContainer = new char[len + 1];
    const char *ptr = str;
    size_t currWordLen = 0;

    while (*str)
    {
        if (isLetter(*str))
        {
            currWordLen = 0;
            while (isLetter(*str))
            {
                helperContainer[newLen] = *str;
                str++;
                newLen++;
                currWordLen++;
            }
            // WE HAVE COPIED A WORD! Lets see if it has even length
            if (isEvenCount(currWordLen))
            {
                helperContainer[newLen] = ' ';
                newLen++;
            }
            else
                newLen -= currWordLen;
        }
        if (*str)
            str++;
    }
    if (newLen > 0 && helperContainer[newLen - 1] == ' ')
        newLen--;
    helperContainer[newLen] = '\0';

    char *newStr = new char[newLen + 1];
    myStrCpy(newStr, helperContainer, newLen);
    delete[] helperContainer;

    return newStr;
}

int main()
{
    const char *testStr = "hi abcdef";
    char *str = nullptr;
    strcpy(str, testStr);

    char *evenStr = returnEven(str);
    std::cout << "Even string is : " << evenStr << std::endl;

    delete[] str;
    delete[] evenStr;
    return 0;
}