#include <iostream>

int countSubsets(const int *str, const size_t len, const size_t countEven, int currCountEven, int currSum, int pos)
{
    bool isEven = 0;

    if (pos == len)
    {
        if (countEven == currCountEven && currSum % 2 == 1)
            return 1;
        return 0;
    }

    if (*str % 2 == 0)
        isEven = 1;

    // We try calling it recursively
    int include = 0;
    int exclude = 0;
    include += countSubsets(str + 1, len, countEven, currCountEven + isEven, currSum + *str, pos + 1); // WE INCLUDE
    exclude += countSubsets(str + 1, len, countEven, currCountEven, currSum, pos + 1);                 // WE EXCLUDE

    return include + exclude;
}

int main()
{
    int str[] = {1, 2, 3, 4};
    size_t len = sizeof(str) / sizeof(str[0]);

    size_t countEven;
    std::cout << "Please enter count even numbers: ";
    std::cin >> countEven;
    std::cout << std::endl;

    std::cout << "Number of eligible subsets: " << countSubsets(str, len, countEven, 0, 0, 0);

    return 0;
}
