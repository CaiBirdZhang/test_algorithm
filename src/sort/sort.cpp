#include <iostream>
#include <cstring>
#include "sort/sort.h"

using namespace std;

// 时间复杂度O(N^2)
// 稳定的算法
void bubbleSort1(int* a, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            // 大的元素向下沉
            if (a[j] > a[j + 1])
            {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// 时间复杂度在最坏情况下是O(N^2)，平均的时间复杂度是O(N*lgN)
// 不稳定的算法
void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = l;
        int j = r;
        int x = a[i];
        while (i < j)
        {
            // 从后向前找比x小的元素
            while (i < j && a[j] > x)
                --j;
            if (i < j)
                a[i++] = a[j];
            // 从前向后找比x大的元素
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

// 时间复杂度O(N^2)
// 稳定的算法
void insertSort(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; ++i)
    {
        // 选中的值比前面的小
        if (a[i - 1] > a[i])
        {
            int tmp = a[i];
            for (j = i - 1; j >= 0; --j)
            {
                if (a[j] > tmp)
                {
                    // 较大元素向后移动一位
                    a[j + 1] = a[j];
                }
                else {
                    break;
                }
            }
            // 移动到合适位置
            a[j + 1] = tmp;
        }
    }
}

// 时间复杂度O(N^1.5)
// 不稳定的算法
void shellSort1(int a[], int n)
{
    int gap, i, j;
    // gap每次缩减一倍,每组间隔越来越小
    for (gap = n/2; gap > 0; gap /= 2)
    {
        // 间隔gap，对每组进行插入排序
        for (i = 0; i < gap; ++i)
        {
            // 一组的排序
            for (j = i + gap; j < n; j += gap)
            {
                // 后面元素更小
                if (a[j - gap] > a[j])
                {
                    int tmp = a[j];
                    int k = j - gap;
                    // 检查前面的元素是否比当前元素大
                    while (k >= 0 && a[k] > tmp)
                    {
                        a[k + gap] = a[k];
                        k -= gap;
                    }
                    a[k + gap] = tmp;
                }
            }
        }
    }
}

// 时间复杂度O(N^2)
// 稳定的算法
void selectSort(int* a, int n)
{
    int i, j;
    for (i = 0; i < n - 1; ++i)
    {
        int min = i;
        // 最小值放在最上面，记录最小值下标
        for (j = i + 1; j < n; ++j)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int tmp = a[min];
            a[min] = a[i];
            a[i] = tmp;
        }
    }
}

// 时间复杂度是O(N*lgN)
// 稳定的算法
void mergeSortUp2Down(int* a, int start, int end)
{
    if (a == NULL || start >= end)
    {
        return;
    }

    int mid = (start + end)/2;
    // a[start...mid] 和 a[mid...end]是两个有序空间，
    // 将它们排序成一个有序空间a[start...end]
    mergeSortUp2Down(a, start, mid);
    mergeSortUp2Down(a, mid + 1, end);
    merge(a, start, mid, end);
}
void merge(int* a, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    int* b = new int[end - start + 1];
    while (i <= mid && j <= end)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
    }
    while (j <= end)
    {
        b[k++] = a[j++];
    }
    memcpy(a + start, b, sizeof(int)*(end - start + 1));
    delete[] b;
}

// 时间复杂度是O(N*lgN)
//
void BucketSort(int arr[], int n)
{}
struct Node *InsertionSort(struct Node *list)
{}
void print(int arr[])
{}
void printBuckets(struct Node *list)
{}
int getBucketIndex(int value)
{}


// 时间复杂度是O(N*lgN)
// 不稳定的算法
void heapSortAsc(int* a, int n)
{
    // 构建堆
    for (int i = n/2 - 1; i >= 0; --i)
    {
        sink(a, i, n - 1);
    }
    // 获取堆顶(最大)元素，放入数组最后
    // 重新调整堆
    for (int i = n - 1; i > 0; --i)
    {
        // swap a[0]和a[i]
        int max = a[0];
        a[0] = a[i];
        a[i] = max;
        // 调整堆
        sink(a, 0, i - 1);
    }
}
void sink(int* a, int start, int end)
{
    int cur = start;
    int left = cur*2 + 1;
    int swapValue = a[cur];
    for (; left <= end; cur = left, left = left*2+1)
    {
        // 获取左右孩子中的最大值的索引
        if (left < end && a[left] < a[left + 1])
        {
            ++left;
        }
        if (swapValue >= a[left])
        {
            // 父节点>=子节点，退出
            break;
        }
        else
        {
            // 位置调整
            a[cur] = a[left];
            a[left] = swapValue;
        }
    }
}
