//
//  quick_sort.c
//  
//
//  Created by Love Bisaria on 1/11/15.
//
//

#include <stdio.h>
#include <stdlib.h>

int partition(int *arr , int left , int right);
void quick_sort(int *arr , int left , int right);

int main(){
    
    int *arr = NULL , n = -1 , i;
    
    printf("Enter the Number of Array elements..!!\n");
    scanf("%d" , &n);
    
    arr = (int*) malloc(sizeof(int) * n);
    printf("Enter the array Elements..!!\n");
    
    for (i = 0; i < n; i++) {
        scanf("%d" ,(arr+i));
    }
    
    printf("Printing the array elements..!!\n");
    for (i = 0; i < n; i++) {
        printf("%d\n" ,*(arr+i));
    }
    
    quick_sort(arr , 0 , (n-1));
    
    printf("Array after Quick_SORT..!!\n");
    for (i = 0; i < n; i++) {
        printf("%d\n" ,*(arr+i));
    }
}

int partition(int *arr , int left , int right){
    
    int i = left , j = right;
    int tmp;
    
    int pivot = arr[(left + right)/2];
    
    while (i <= j) {
        
        while(arr[i] < pivot){
            i++;
        }
        
        while (arr[j] > pivot) {
            j--;
        }
        
        if(i <= j){
            
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    return i;
}

void quick_sort(int *arr , int left , int right){
    int index = partition(arr , left , right);
    
    if(left < (index-1))
        quick_sort(arr , left , index-1);
    if(index < right)
        quick_sort(arr , index , right);
}
