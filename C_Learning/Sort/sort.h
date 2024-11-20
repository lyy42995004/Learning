#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 交换函数
void Swap(int *p1, int *p2);

// 插入排序
void InsertSort(int *a, int n);

// 希尔排序
void ShellSort(int *a, int n);

// 选择排序
void SelectSort(int *a, int n);

// 堆排序
void AdjustDwon(int *a, int n, int parent);
void HeapSort(int *a, int n);

// 冒泡排序
void BubbleSort(int *a, int n);

// 快速排序hoare版本
int PartSort1(int *a, int left, int right);
// 快速排序挖坑法
int PartSort2(int *a, int left, int right);
// 快速排序前后指针法
int PartSort3(int *a, int left, int right);
// 快速排序递归实现
void QuickSort(int *a, int left, int right);

// 快速排序 非递归实现
void QuickSortNonR(int *a, int left, int right);

// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);

// 计数排序
void CountSort(int* a, int n);