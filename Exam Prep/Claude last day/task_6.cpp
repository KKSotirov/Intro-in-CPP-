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

bool isBalanced(char *str, size_t pos, int countOpen, int countClose, const size_t len)
{
    if (pos > len)
    {
        return false;
    }
    if (pos == len)
        return (countOpen == countClose);

    if (str[pos] == '(')
        return isBalanced(str, pos + 1, countOpen + 1, countClose, len);
    if (str[pos] == ')')
        return isBalanced(str, pos + 1, countOpen, countClose + 1, len);
    else
        return isBalanced(str, pos + 1, countOpen, countClose, len);
}

int main()
{
    const char *testStr = "((A)l)u)c(a)(rD)";
    char *str = nullptr;
    strcpy(str, testStr);
    size_t len = strlen(str);

    if (isBalanced(str, 0, 0, 0, len))
        std::cout << "This string is Balanced " << std::endl;
    else
        std::cout << "This string is Unbalanced" << std::endl;

    delete[] str;
    return 0;
}