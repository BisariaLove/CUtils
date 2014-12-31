//
//  heap_sort.c
//  
//
//  Created by Love Bisaria on 12/25/14.
//
//

#include "../include/heap_sort.h"


int main(){
    
    int arr[MAXSIZE] ;
    int size = 0;
    
    inputElements(arr , &size);
    printElements(arr , size);
    
    heap_sort(arr, size);
    printf("Array after Heap Sort");
    printElements(arr , size);
    
    
    return 0 ;
}


void inputElements(int *arr ,int *size){
    
    
    printf("Enter Size of Array(max %d)..\n" , MAXSIZE);
    scanf("%d",size);
    
    printf("Enter the array Elements..\n");
    for(int i=0 ; i<(*size) ; i++){
        scanf("%d" , (arr+i));
    }
    
}

void printElements(int *arr , int size){
    
    printf("Printing Array Elements..\n");
    for(int i=0 ; i<size ; i++){
        printf("%d\n" , arr[i]);
    }
    
}


void build_max_heap(int *arr,int heap_size){
    
    for(int i=((heap_size)/2) ; i>=0 ; i--){
        
        max_heapify(arr , i , heap_size);
    }
    
}

void max_heapify(int *arr , int index , int heap_size){
    
    int l ,r , largest , temp;
    
    l = LEFT(index);
    r = RIGHT(index);
    
    if ((l < heap_size) && (arr[l] > arr[index])) {
        largest = l;
    } else {
        largest = index;
    }
    
    if ((r < heap_size) && (arr[r] > arr[index])) {
        largest = r;
    }
    
    if (largest != index) {
        temp = arr[index];
        arr[index] = arr[largest];
        arr[largest] = temp;
        max_heapify(arr , largest , heap_size);
    }
    
}



void heap_sort(int *arr , int heap_size){
    
    int temp = -1 , i ;
    build_max_heap(arr,heap_size);
    
    for (i = (heap_size-1); i >= 1; i--) {
        
        temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heap_size = heap_size-1;
        max_heapify(arr , 0 , heap_size);
    }
    
}
