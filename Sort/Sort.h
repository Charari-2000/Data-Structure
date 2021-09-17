//
// Created by charari on 9/7/21.
//

#ifndef BITEDU_DS_SORT_H
#define BITEDU_DS_SORT_H

#include "Common.h"
#define null -1

typedef void(*Sort)(DataType*, int, Cmp);
// 插入排序
void InsertSort(DataType* a, int n, Cmp Order);
void BInsertSort(DataType* a, int n, Cmp Order);
void TwoWaysInsertSort(DataType* a, int n, Cmp Order);
void TableInsertSort(DataType* a, int n, Cmp Order);
// 希尔排序
void ShellSort(DataType* a, int n, Cmp Order);
// 选择排序
void SelectSort(DataType* a, int n, Cmp Order);
// 堆排序
void HeapSort(DataType* a, int n, Cmp Order);
// 冒泡排序
void BubbleSort(DataType* a, int n, Cmp Order);
// 快速排序
void QuickSort(DataType* a, int n, Cmp Order);
// 快速排序 非递归实现
void QuickSortNonR(DataType* a, int n, Cmp Order);
// 归并排序递归实现（自顶向下）
void MergeSort(DataType* a, int n, Cmp Order);
// 归并排序非递归实现（自底向上）
void MergeSortNonR(DataType* a, int n, Cmp Order);
// 基数排序
void RadixSort(DataType* a, int n, Cmp Order);

static Sort sort[] = { InsertSort, BInsertSort, TwoWaysInsertSort, TableInsertSort, ShellSort, SelectSort, HeapSort, BubbleSort, QuickSort,
                      QuickSortNonR, MergeSort, MergeSortNonR, RadixSort };

#endif //BITEDU_DS_SORT_H
