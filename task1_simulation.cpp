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

bool isLetter(const char ch)
{
    return ((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'));
}

bool isSmallLetter(const char ch)
{
    return (ch >= 'a') && (ch <= 'z');
}

int calcWordLength(const char *str)
{
    int len = 0;
    while (isLetter(*str))
    {
        len++;
        str++;
    }
    return len;
}

bool hasEvenLength(const int len)
{
    if (len % 2 == 0)
        return true;
    return false;
}

void toCapitalLetter(char &ch)
{
    int asciiDist = 'A' - 'a';
    if (isSmallLetter(ch))
        ch += asciiDist;
}

void toCapitalWord(char *&word)
{
    int wordLen = calcWordLength(word);
    for (size_t i = 0; i < wordLen; i++)
    {
        toCapitalLetter(word[i]);
    }
}

char *extractEvenWordsUpper(const char *sentence)
{
    size_t len = strlen(sentence);
    char *helperContainer = new char[len + 1];
    size_t newLen = 0;
    size_t currWordLen = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (isLetter(sentence[i]))
        {
            currWordLen = calcWordLength(sentence + i);
            if (hasEvenLength(currWordLen))
            {
                for (size_t j = i; j < currWordLen + i; j++)
                {
                    helperContainer[newLen] = sentence[j];
                    toCapitalLetter(helperContainer[newLen]);
                    newLen++;
                }
                // helperContainer now has that word copied
                helperContainer[newLen] = ' ';
                newLen++;
            }
            i += currWordLen;
        }
    }
    if (newLen > 0)
        newLen--;
    // removing the last interval

    char *newStr = new char[newLen + 1];
    myStrCpy(newStr, helperContainer, newLen);
    delete[] helperContainer;

    return newStr;
}
int main()
{
    const char *testStr = "Crazy rat in a rubber room!";
    char *str = nullptr;
    strcpy(str, testStr);

    char *newStr = extractEvenWordsUpper(str);
    std::cout << "New string is : " << newStr;
    return 0;
}
