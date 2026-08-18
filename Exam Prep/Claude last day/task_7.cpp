#include <iostream>

int binarySearch(int *sortedArr, int startIndex, int endIndex, const int target)
{
    if (startIndex == endIndex)
        return (sortedArr[startIndex] == target) ? startIndex : -1;

    size_t middleIndex = (startIndex + endIndex) / 2;

    if (target == sortedArr[middleIndex])
        return middleIndex;

    if (target > sortedArr[middleIndex])
        return binarySearch(sortedArr, middleIndex + 1, endIndex, target);

    if (target < sortedArr[middleIndex])
        return binarySearch(sortedArr, startIndex, middleIndex - 1, target);
}

int main()
{
    size_t len;
    std::cout << "Please enter array length: ";
    std::cin >> len;
    std::cout << std::endl;

    int arr[len];
    std::cout << "Please enter array: ";
    for (size_t i = 0; i < len; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << std::endl;

    int target;
    std::cout << "Please enter target: ";
    std::cin >> target;
    std::cout << std::endl;

    if (binarySearch(arr, 0, len - 1, target) == -1)
        std::cout << "The target was NOT found!" << std::endl;
    else
        std::cout << "The target was found at index " << binarySearch(arr, 0, len - 1, target) << "!" << std::endl;

    return 0;
}