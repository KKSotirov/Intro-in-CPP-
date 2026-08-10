#include <iostream>

// Filling a matrix spyrally

int **returnSpiralMatrix(const unsigned len)
{
    // Lets first innit Matrix
    int **spiralMatrix = new int *[len];
    for (size_t i = 0; i < len; i++)
    {
        spiralMatrix[i] = new int[len];
        for (size_t j = 0; j < len; j++)
        {
            spiralMatrix[i][j] = 0;
        }
    }
    // now we have a len x len matrix
    int i = 0;
    int j = 0;
    int currNumber = 1;
    int currSpiral = 0;
    // FIRST SPIRAL
    while (currNumber <= len * len)
    {
        i = currSpiral;
        j = currSpiral;
        while (j < len - currSpiral)
        {
            spiralMatrix[i][j] = currNumber;
            j++;
            currNumber++;
            // i = 0, j = len + 1      1/4 spiral
        }
        j--;
        i++;
        while (i < len - currSpiral)
        {
            spiralMatrix[i][j] = currNumber;
            i++;
            currNumber++;
            // i = len + 1, j = len     2/4 spiral
        }
        i--;
        j--;
        while (j >= currSpiral)
        {
            spiralMatrix[i][j] = currNumber;
            j--;
            currNumber++;
            // i = len, j = 0       3/4 spiral
        }
        i--;
        j++;
        while (i > currSpiral)
        {
            spiralMatrix[i][j] = currNumber;
            i--;
            currNumber++;
            // i = 1, j = 0         4/4 spiral ==> successfully comleted a spiral!
        }
        currSpiral++;
    }

    return spiralMatrix;
}

void freeMatrix(int **matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void printMatrix(int **matrix, const unsigned len)
{
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < len; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main()
{
    unsigned len;
    std::cout << "Please enter size of square matrix: " << std::endl;
    std::cin >> len;
    int **spiralMatrix = returnSpiralMatrix(len);
    printMatrix(spiralMatrix, len);
    freeMatrix(spiralMatrix, len);
}