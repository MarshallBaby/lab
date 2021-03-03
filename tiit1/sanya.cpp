#include <iostream>

void Print(char* a, int n, int i)
{
    if (n)
    {
        if (n & 1)
            std::cout << a[i] << " ";
        Print(a, n >> 1, i + 1);
    }
}

int main()
{
    int r, i, size;
    char a[] = { '1', '2', '3' };
    size = sizeof(a) / sizeof(*a);
    r = 1 << size;
    for (i = 0; i < r; i++)
    {
        Print(a, i, 0);
        std::cout << "\n";
    }
    return 0;
}