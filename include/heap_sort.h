//
//  heap_sort.h
//  
//
//  Created by Love Bisaria on 12/25/14.
//
//

#ifndef ____heap_sort__
#define ____heap_sort__

#include <stdio.h>
#include <math.h>
#define MAXSIZE    100
#define LEFT(X)    (2*(X))
#define RIGHT(X)   ((2*(X)) + 1)
#define Parent(X)  ((X)/2)

void inputElements(int *arr ,int *size);
void printElements(int *arr , int size);
void max_heapify(int *arr , int index , int heap_size);
void build_max_heap(int *arr,int heap_size);
void heap_sort(int *arr , int heap_size);

#endif /* defined(____heap_sort__) */
