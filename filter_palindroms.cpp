#include <iostream>

void initMatrix(char **matrix, const size_t size)
{
    int currPalindromLength = 0;
    for (size_t i = 0; i < size; i++)
    {
        //        currPalindromLength = strlen(getWord());
        matrix[i] = new char[size + 1];
        matrix[i][size] = '\0';
    }
}

int strlen(const char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void myStrCpy(char *&dest, const char *src)
{
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = ' ';
}

void strcpy(char *&dest, const char *src)
{
    int len = strlen(src);
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

bool isSmallLetter(const char ch)
{
    return (ch >= 'a') && (ch <= 'z');
}

bool isCapLetter(const char ch)
{
    return (ch >= 'A') && (ch <= 'Z');
}

bool isLetter(const char ch)
{
    return isSmallLetter(ch) || isCapLetter(ch);
}

char *getWord(const char *str)
{
    int len = strlen(str);
    char *helperContainer = new char[len + 1];
    int newLen = 0;
    while (*str && isLetter(*str))
    {
        // while the curr symbol is a letter, we copy it in helper container
        *helperContainer = *str;
        str++;
        helperContainer++;
        newLen++;
    }
    *helperContainer = '\0';
    helperContainer -= newLen;

    char *word = new char[newLen + 1];
    strcpy(word, helperContainer);

    delete[] helperContainer;
    return word;
}

bool isPalidrome(char *str, const size_t len)
{
    if (len == 0)
        return false;
    for (size_t i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

char **palindromsIntoMatrix(const char *str)
{
    int len = strlen(str);
    char *currWord = nullptr;
    size_t currLen = 0;

    char *helperContainer = new char[len + 1];
    int helperLen = 0;
    int newLen = 0;
    // str ~~> str with only palindroms and _ inbetween ~~> matrix
    const char *ptr = str;
    while (*ptr)
    {
        if (!isLetter(*ptr))
            ptr++;
        else
        {
            // found the start of a word
            currWord = getWord(ptr);
            currLen = strlen(currWord);
            if (isPalidrome(currWord, currLen))
            {

                myStrCpy(helperContainer, currWord);
                helperContainer++;
                helperLen += currLen + 1;
                newLen++; // a new palindrom has been copied
                ptr += currLen;
            }
            else
            {
                ptr += currLen;
                // Curr word is not a palindrome, we skip it
            }
        }
    }
    *helperContainer = '\0';
    helperContainer -= helperLen;
}

int main()
{
    const char *testStr = "avava bab joker tatat   joker          joker ana";
    char *str = nullptr;

    return 0;
}