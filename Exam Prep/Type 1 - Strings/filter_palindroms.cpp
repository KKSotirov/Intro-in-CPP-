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
}

void strCpyMatrix(char *&dest, const char *src, const size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void strcpy(char *&dest, const char *src)
{
    int len = strlen(src);
    delete[] dest;
    dest = new char[len + 1];
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

    char *word = nullptr;
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

char **palindromsIntoMatrix(const char *str, int &matrixRows)
{
    int len = strlen(str);
    char *currWord = nullptr;
    size_t currLen = 0;

    char *helperContainer = new char[len + 1];
    char *ogHelper = helperContainer;
    int wordCount = 0;
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
                *helperContainer = ' ';
                helperContainer++;
                ptr += currLen;
                wordCount++; // a new word has been copied
            }
            else
            {
                ptr += currLen;
                // Curr word is not a palindrome, we skip it
            }
            delete[] currWord;
            currWord = nullptr;
        }
    }
    *helperContainer = '\0';
    helperContainer = ogHelper;
    // here we need to make the matrix and to store in it each word
    // lets first get each word's lengths
    char **palindromMatrix = new char *[wordCount];
    matrixRows = wordCount;
    int currMatrixRow = 0;

    while (*ogHelper)
    {
        while (*ogHelper && !isLetter(*ogHelper))
            ogHelper++;

        currWord = getWord(ogHelper);
        currLen = strlen(currWord);
        palindromMatrix[currMatrixRow] = new char[currLen + 1];
        strCpyMatrix(palindromMatrix[currMatrixRow], currWord, currLen);
        currMatrixRow++;
        ogHelper += currLen;

        delete[] currWord;
        currWord = nullptr;
    }

    delete[] helperContainer;

    return palindromMatrix;
}

void freeMatrix(char **matrix, const int rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(char **matrix, const int rows)
{
    for (size_t i = 0; i < rows; i++)
    {
        while (*matrix[i])
        {
            std::cout << *matrix[i];
            matrix[i]++;
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

int main()
{
    const char *testStr = "avava bab joker tatat   joker          joker ana";
    char *str = nullptr;
    strcpy(str, testStr);
    int matrixRows = 0;
    char **matrix = palindromsIntoMatrix(str, matrixRows);
    printMatrix(matrix, matrixRows);

    freeMatrix(matrix, matrixRows);
    return 0;
}