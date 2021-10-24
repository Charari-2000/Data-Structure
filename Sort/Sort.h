#ifndef DS_SORT_H
#define DS_SORT_H

#include "Common.h"
#define null -1

// Insert sort
void InsertSort(DataType* a, int n, Cmp Order);
void BInsertSort(DataType* a, int n, Cmp Order);
void TwoWaysInsertSort(DataType* a, int n, Cmp Order);
void TableInsertSort(DataType* a, int n, Cmp Order);
// Shell sort
void ShellSort(DataType* a, int n, Cmp Order);
// Select sort
void SelectSort(DataType* a, int n, Cmp Order);
// Heap sort
void HeapSort(DataType* a, int n, Cmp Order);
// Bubble sort
void BubbleSort(DataType* a, int n, Cmp Order);
// Quick sort
void QuickSort(DataType* a, int n, Cmp Order);
void QuickSort_Iter(DataType* a, int n, Cmp Order);
// Merge sort
void MergeSort(DataType* a, int n, Cmp Order);
void MergeSort_Iter(DataType* a, int n, Cmp Order);
// Radix sort
void RadixSort(DataType* a, int n, Cmp Order);

#endif //DS_SORT_H
