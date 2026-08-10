#include <iostream>

// Filling a matrixa s a reverse spiral

//  3  2  1
//  4  9  8
//  5  6  7             size = 3

//  4   3    2    1
//  5   14   13   12
//  6   15   16   11
//  7   8    9    10        size = 4

int **createReverseSpiral(const unsigned len)
{
    int **reversedSpiral = new int *[len];
    for (size_t i = 0; i < len; i++)
    {
        reversedSpiral[i] = new int[len];
        for (size_t j = 0; j < len; j++)
        {
            reversedSpiral[i][j] = 0;
        }
    }
    int i = len - 1;
    int j = len - 1;
    int currSpiral = 0;
    int currNumber = 1;
    while (currNumber <= len * len)
    {
        i = len - 1 - currSpiral;
        j = len - 1 - currSpiral;
        // lets dismantle each spiral into 4 parts:      1.left, 2.up, 3.right, 4.down
        while (j >= currSpiral)
        {
            reversedSpiral[i][j] = currNumber;
            currNumber++;
            j--; // Left ~~> 1/4 Spiral
        }
        j++;
        i--;
        while (i >= currSpiral)
        {
            reversedSpiral[i][j] = currNumber;
            currNumber++;
            i--; // Up ~~> 2/4 Spiral
        }
        i++;
        j++;
        while (j < len - currSpiral)
        {
            reversedSpiral[i][j] = currNumber;
            currNumber++;
            j++; // Right ~~> 3/4 Spiral
        }
        j--;
        i++;
        while (i < len - currSpiral - 1)
        {
            reversedSpiral[i][j] = currNumber;
            currNumber++;
            i++; // Down ~~> 4/4 Spiral      ==> Successfully completed a reverse spiral!
        }
        currSpiral++;
    }

    return reversedSpiral;
}

void printMatrix(const int *const *matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            std::cout << matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}

void freeMatrix(int **matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    unsigned len;
    std::cout << "Please enter matrix dimensions: " << std::endl;
    std::cin >> len;
    int **reverseSpiral = createReverseSpiral(len);
    printMatrix(reverseSpiral, len);
    freeMatrix(reverseSpiral, len);

    return 0;
}