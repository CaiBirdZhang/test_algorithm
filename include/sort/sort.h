#ifndef SORT_H
#define SORT_H

#include <iostream>
using namespace std;

// 冒泡排序
void bubbleSort1(int* a, int n);
void bubbleSort2(int* a, int n);

// 快速排序
void quickSort(int a[], int l, int r);

// 直接插入排序  希尔排序
void insertSort(int a[], int n);
void shellSort1(int a[], int n);

// 选择排序
void selectSort(int* a, int n);

// 归并排序
void mergeSortUp2Down(int* a, int start, int end);
void merge(int* a, int start, int mid, int end);

// 桶排序
struct Node
{
    int data;
    struct Node *next;
};
void BucketSort(int arr[], int n);
struct Node *InsertionSort(struct Node *list);
void print(int arr[]);
void printBuckets(struct Node *list);
int getBucketIndex(int value);


#endif