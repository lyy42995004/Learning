#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity; 
}Heap;

//向上调整
void AdjustUp(HPDataType* a, int child);
//向下调整
void AdjustDown(HPDataType* a, int n, int parent);
//交换
void Swap(HPDataType* p1, HPDataType* p2);

// 堆的初始化
void HeapInit(Heap* php);
// 堆的销毁
void HeapDestory(Heap* php);
// 堆的插入
void HeapPush(Heap* php, HPDataType x);
// 堆的删除
void HeapPop(Heap* php);
// 取堆顶的数据
HPDataType HeapTop(Heap* php);
// 堆的数据个数
int HeapSize(Heap* php);
// 堆的判空
int HeapEmpty(Heap* php);