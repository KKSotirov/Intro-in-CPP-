#include <iostream>

unsigned strlen(const char *str)
{
    unsigned len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void strcpy(char *&dest, const char *src)
{
    delete[] dest;
    dest = new char[strlen(src) + 1];
    unsigned pos = 0;
    while (*src)
    {
        *dest = *src;
        src++;
        pos++;
        dest++;
    }
    *dest = '\0';
    dest -= pos;
}

void myStrCopy(char *&dest, const char *src, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int getASCII(const char ch)
{
    return static_cast<int>(ch);
}

char *returnUnique(const char *str)
{
    unsigned len = strlen(str);
    char *helperContainer = new char[len + 1];
    unsigned newLen = 0;
    const char *ptr = str;
    char array[256] = {0};
    while (*ptr)
    {
        array[getASCII(*ptr)]++;
        ptr++;
    }
    // counts all of the  occurances
    ptr = str;
    for (size_t i = 0; i < 256; i++)
    {
        if (array[i] == 1)
        {
            *helperContainer = static_cast<char>(array[i]);
            helperContainer++;
            newLen++;
        }
    }

    helperContainer -= newLen;
    char *newStr = new char[newLen + 1];
    myStrCopy(newStr, helperContainer, newLen);
    delete[] helperContainer;
    return newStr;
}

void printStr(const char *str)
{
    unsigned len = strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        std::cout << str[i];
    }

    std::cout << std::endl;
}

int main()
{
    const char *testStr = "AKaKKyyassAsSa";
    char *amenStr = nullptr;
    strcpy(amenStr, testStr);
    char *theChosenOne = returnUnique(amenStr);
    std::cout << "The chosen one is :   " << std::endl;
    printStr(theChosenOne);
    delete[] theChosenOne;
    return 0;
}