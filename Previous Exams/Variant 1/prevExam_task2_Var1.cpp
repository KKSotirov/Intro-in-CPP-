#include <iostream>

void initCharStr(char *str, const unsigned len)
{
    std::cout << "Please enter char string: " << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> str[i];
    }
    str[len] = '\0';
}

void initIntStr(int *str, const unsigned len)
{
    std::cout << "Please enter int string: " << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> str[i];
    }
}

bool isSmallLetter(const char ch)
{
    return (ch >= 'a') && (ch <= 'j');
}

bool areSmallLetters(const char *str, unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (!isSmallLetter(str[i]))
            return false;
    }
    return true;
}

bool isNumber(const int num)
{
    return (num >= 0) && (num <= 9);
}

bool areNumbers(const int *str, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        if (!isNumber(str[i]))
            return false;
    }
    return true;
}

int calculateAlphabetIndex(const char ch)
{
    return ch - 'a';
}

bool areSameIndexes(const char *strCh, const int *strNum, const unsigned len)
{
    if (!areNumbers(strNum, len) || !areSmallLetters(strCh, len))
        return false;
    for (size_t i = 0; i < len; i++)
    {
        if (calculateAlphabetIndex(strCh[i]) != strNum[i])
            return false;
    }
    return true;
}

int main()
{
    unsigned len;
    std::cout << "Please enter length of strings: " << std::endl;
    std::cin >> len;

    char *str = new char[len + 1];
    initCharStr(str, len);
    int *strNumbs = new int[len];
    initIntStr(strNumbs, len);

    if (!areSameIndexes(str, strNumbs, len))
        std::cout << "No, the number string does not correspond to the char strings' indexes!" << std::endl;
    else
        std::cout << "Yes, the number string does correspond to the char strings' indexes!" << std::endl;

    delete[] strNumbs;
    delete[] str;
    return 0;
}