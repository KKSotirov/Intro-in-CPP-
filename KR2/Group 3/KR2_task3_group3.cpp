#include <iostream>

unsigned strlen(const char *str)
{
    unsigned count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return count;
}

void strcpy(char *&dest, const char *src)
{
    unsigned len = strlen(src);
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool isSmallLetter(const char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

void encrypt(char *&str, const int pos)
{
    if (*str == '\0')
    {
        return;
    }
    if (isSmallLetter(*str))
    {
        if (*str + pos > 'z')
            *str = *str + pos - 'z';
        else
            *str = *str + pos;
    }
    str++;
    encrypt(str, pos);
}

void printStr(char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
    std::cout << std::endl;
}
int main()
{
    int pos;
    const char *testStr = "hello world!";
    char *str = nullptr;
    strcpy(str, testStr);
    unsigned len = strlen(str);
    std::cout << "Please enter with how many positions shall we shift forward small letters: " << std::endl;
    std::cin >> pos;
    encrypt(str, pos);
    str -= len;
    printStr(str);

    return 0;
}