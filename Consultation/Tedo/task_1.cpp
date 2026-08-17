#include <iostream>
// sum of all numbers in string

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
    delete[] dest;
    size_t len = strlen(src);
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool isNumber(const char ch)
{
    return (ch >= '0') && (ch <= '9');
}

int charToInt(const char ch)
{
    return ch - '0';
}

int returnSum(const char *str)
{
    size_t len = strlen(str);
    int sum = 0;
    int currNumber;
    while (*str)
    {
        if (isNumber(*str))
        {
            currNumber = 0;
            while (isNumber(*str))
            {
                currNumber = currNumber * 10 + charToInt(*str);
                str++;
            }
            sum += currNumber;
        }
        str++;
    }

    return sum;
}

int main()
{
    const char *testStr = "ab37x10s30";
    char *str = nullptr;
    strcpy(str, testStr);
    std::cout << "Sum of entered string is = " << returnSum(str);

    delete[] testStr;
    delete[] str;
    return 0;
}