#include <iostream>

void initStr(char *&str, const size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> str[i];
    }
    str[len] = '\0';
}

void reverseStr(char *&str, const size_t len)
{
    char tmp;
    for (size_t i = 0; i < len / 2; i++)
    {
        tmp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = tmp;
    }
    // jo\0
}

void reverseStrWithPointers(char *&str, const size_t len)
{
    // one pointer at start, one pointer at end
    char tmp;
    size_t shifts = 0;
    char *ptr = str + len - 1; // shifting to end of string

    while (str != ptr)
    {
        tmp = *str;
        *str = *ptr;
        *ptr = tmp;
        shifts++;
        str++;
        ptr--;
    }
    str -= shifts; // bringing pointer back to start of string!
}

void printStr(const char *str)
{
    while (*str)
    {
        std::cout << *str;
        str++;
    }
}

int main()
{
    size_t len;
    std::cout << "Please enter string len: " << std::endl;
    std::cin >> len;
    char *str = new char[len + 1];
    std::cout << "Please enter string: " << std::endl;
    initStr(str, len);
    // reverseStr(str, len);
    reverseStrWithPointers(str, len);
    std::cout << "Printing string: " << std::endl;
    printStr(str);

    delete[] str;
    return 0;
}