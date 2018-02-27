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

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = l;
        int j = r;
        int x = a[i];
        while (i < j)
        {
            while (i < j && a[j] > x)
                --j;
            if (i < j)
                a[i++] = a[j];
            while (i < j && a[i] < x)
                ++i;
            if (i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}