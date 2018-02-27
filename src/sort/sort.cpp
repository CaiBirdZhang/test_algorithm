#include <iostream>
#include "sort/sort.h"

using namespace std;

// 时间复杂度O(N2)
void bubbleSort1(int* a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

void bubbleSort2(int* a, int n)
{

}