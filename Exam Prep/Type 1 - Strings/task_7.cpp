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

bool isSmallVowel(const char ch)
{
    return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
}

bool isCapitalVowel(const char ch)
{
    return (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U');
}

bool isVowel(const char ch)
{
    return isSmallVowel(ch) || isCapitalVowel(ch);
}

char *constructNewStr(char *str)
{
    size_t len = strlen(str);
    char *helperContainer = new char[len + 1];
    size_t newLen = 0;
    const char *ptr = str;

    while (*ptr)
    {
        if (!isVowel(*ptr))
        {
            // not a vowel ~~> we write it down
            *helperContainer = *ptr;
            helperContainer++;
            ptr++;
            newLen++;
        }
        else
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
    const char *testStr1 = "Crazy? I was crazy once. They locked me in a room. A rubber room. A rubber room with rats. And rats make me crazy. CRAZY?!?!?!?";
    const char *testStr2 = "JokereIAzSumLud!";
    char *str = nullptr;
    strcpy(str, testStr1);

    char *newStr = constructNewStr(str);
    std::cout << "New string is : " << newStr << std::endl;

    delete[] newStr;
    delete[] str;
    return 0;
}