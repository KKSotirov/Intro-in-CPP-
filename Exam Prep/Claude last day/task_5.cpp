#include <iostream>

size_t strlen(const char *str)
{
    size_t len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

void strcpy(char *&dest, const char *src)
{
    size_t len = strlen(src);
    delete[] dest;
    dest = new char[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

void swap(char *&str, size_t index1, size_t index2)
{
    char tmp = str[index1];
    str[index1] = str[index2];
    str[index2] = tmp;
}

void mirrorStr(char *&str, size_t startPos, size_t endPos)
{
    if (startPos == endPos)
        return;

    swap(str, startPos, endPos);
    mirrorStr(str, startPos + 1, endPos - 1);
}

int main()
{
    const char *testStr = "AlucarD";
    char *str = nullptr;
    strcpy(str, testStr);

    // Lets mirror str
    size_t lastPos = strlen(str) - 1;
    mirrorStr(str, 0, lastPos);

    std::cout << "This is the now mirrored string: " << str << std::endl;

    delete[] str;
    return 0;
}