#include <iostream>

char *swap(char *&str, const int index1, const int index2)
{
    char tmp = str[index2];
    str[index2] = str[index1];
    str[index1] = tmp;

    return str;
}

bool isDuplicate(const char *str, const size_t start, const size_t limit)
{
    for (size_t i = start; i < limit; i++)
    {
        if (str[i] == str[limit])
            return true;
    }
    return false;
}

void printAllPermutations(char *ogStr, const size_t len, size_t currIndex)
{
    // BASE CASES
    if (currIndex >= len)
    {
        std::cout << ogStr << std::endl;
        return;
    }

    for (size_t i = currIndex; i < len; i++)
    {
        if (isDuplicate(ogStr, currIndex, i))
            continue;
        swap(ogStr, currIndex, i);
        printAllPermutations(ogStr, len, currIndex + 1);
        swap(ogStr, currIndex, i);
    }
}

int main()
{
    char str[] = "abc";
    size_t len = 3;

    std::cout << "All permutations : " << std::endl;
    printAllPermutations(str, len, 0);
}