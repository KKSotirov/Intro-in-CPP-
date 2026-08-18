#include <iostream>

int calcSum(const int *arr, const size_t len, size_t pos, int sum)
{
    if (pos >= len)
        return sum;

    return calcSum(arr, len, pos + 1, sum + arr[pos]);
}

int main()
{
    size_t len;
    std::cout << "Please enter length: " << std::endl;
    std::cin >> len;

    int arr[len];
    std::cout << "Please enter int array: " << std::endl;
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> arr[i];
    }

    int sum = calcSum(arr, len, 0, 0);
    std::cout << "Sum of array is : " << sum << std::endl;

    return 0;
}