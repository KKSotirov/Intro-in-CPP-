#include <iostream>

bool isPalindrom(const char *str, const size_t len, size_t startingPos)
{
    if (startingPos >= (len / 2))
        return true;

    if (str[startingPos] == str[len - 1 - startingPos])
        return isPalindrom(str, len, startingPos + 1);
    else
        return false;
}
