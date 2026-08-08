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
            *helperContainer = array[i];
            helperContainer++;
            newLen++;
        }
    }

    helperContainer -= newLen;
}
