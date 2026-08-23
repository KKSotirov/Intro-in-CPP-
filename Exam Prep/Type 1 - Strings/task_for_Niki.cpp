#include <iostream>
const size_t THREE = 3;

// >> three digit number
// return palindrome

int getDigs(const char *str, int digits[THREE])
{
    if (!str)
        return -1;

    int count = 0;
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            digits[count] = str[i] - '0';
        }
        else
            return -1;
        count++;
    }

    return count;
}

void sort(int &dig0, int &dig1, int &dig2)
{
    int temp;

    if (dig0 > dig1)
    {
        temp = dig0;
        dig0 = dig1;
        dig1 = temp;
    }

    if (dig1 > dig2)
    {
        temp = dig1;
        dig1 = dig2;
        dig2 = temp;
    }
    // step 2 might have fucked us up, we check again :)
    if (dig0 > dig1)
    {
        temp = dig0;
        dig0 = dig1;
        dig1 = temp;
    }
    // voilla
}

int generatePalindrome(const char *str)
{
    int digits[3];
    int count = getDigs(str, digits);

    if (count != 3)
    {
        std::cout << std::endl;
        std::cout << "Invalid input, you degenerate autist!" << std::endl;
        return -1;
    }

    // Lets sort the numbers ascendingly
    sort(digits[0], digits[1], digits[2]);

    // case 1: 3 equal digs
    // case 2: 2 equal digs
    // case 3: all unique digs   ~~> 5 digit

    // CASE 1:  3 equal digs
    if (digits[0] == digits[2])
        return (digits[0] * 100) + (digits[0] * 10) + digits[0];

    // CASE 2:  2 equal digs
    if (digits[0] == digits[1])
    {
        if (digits[0] == 0)
            return digits[2];

        return digits[0] * 100 + digits[2] * 10 + digits[0];
    }

    if (digits[1] == digits[2])
    {
        return digits[1] * 100 + digits[0] * 10 + digits[1];
    }

    // CASE 3:  all unique digs   ~~> 5 digit
    if (digits[0] != 0)
    {
        return digits[0] * 10000 + digits[1] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];
    }

    // we have 3 different digs and a 0 among them  >:(
    return digits[1] * 10000 + digits[0] * 1000 + digits[2] * 100 + digits[0] * 10 + digits[1];
}

int main()
{
    std::cout << "Generating palindrome with 055 ~~> " << generatePalindrome("505") << std::endl;
    std::cout << "Generating palindrome with 000 ~~> " << generatePalindrome("000") << std::endl;
    std::cout << "Generating palindrome with 123 ~~> " << generatePalindrome("123") << std::endl;
    std::cout << "Generating palindrome with 120 ~~> " << generatePalindrome("120") << std::endl;
    std::cout << "Generating palindrome with 100 ~~> " << generatePalindrome("100") << std::endl;
    std::cout << "Generating palindrome with Abc ~~> " << generatePalindrome("Abc") << std::endl;

    return 0;
}
