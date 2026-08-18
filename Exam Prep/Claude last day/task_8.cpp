#include <iostream>

void printSubsets(int *arr, const int k, const size_t len, size_t currIndex, int *chosen, int chosenCount)
{
    if (chosenCount == k)
    {
        std::cout << "{";
        for (size_t i = 0; i < chosenCount - 1; i++)
        {
            std::cout << chosen[i] << ", ";
        }
        std::cout << chosen[chosenCount - 1] << "}" << std::endl;
        return;
    }

    if (currIndex >= len)
        return;

    // CHOISE 1: INCLUDE arr[currIndex] into chosen
    chosen[chosenCount] = arr[currIndex];
    printSubsets(arr, k, len, currIndex + 1, chosen, chosenCount + 1);

    // CHOISE 2: EXCLUDE arr[currIndex] from chosen
    printSubsets(arr, k, len, currIndex + 1, chosen, chosenCount);
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

    int countElements;
    std::cout << "Please enter amount of elements in subsets: ";
    std::cin >> countElements;
    std::cout << std::endl;
    int *chosen = new int[countElements];

    std::cout << "Printing all subsets: " << std::endl;
    printSubsets(arr, countElements, len, 0, chosen, 0);

    delete[] chosen;
    return 0;
}