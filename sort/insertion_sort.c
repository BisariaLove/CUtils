//
//  insertion_sort.c
//  
//
//  Created by Love Bisaria on 12/17/14.
//
//

#include <stdio.h>
#define MAXARRAYSIZE 100

void print_array(int arr[MAXARRAYSIZE] , int len);
void read_elements(int * arr , int *len);
void insertion_sort(int *arr , int len);

int main(){
    
    int len , arr[MAXARRAYSIZE] ;
    
    printf("---------Insertion Sort---------\n");
    
    read_elements(arr , &len);
    print_array(arr , len);
    insertion_sort(arr , len);
    print_array(arr , len);
    
    return 0;
}

void read_elements(int * arr , int *len){
    
    int i;
    
    printf("Enter Size of Array (Max 100) ..!!\n");
    
    scanf("%d" , len);
    
    printf("\nEnter Array Elements ..!!\n");
    
    for(i=0 ; i<(*len) ; i++){
        scanf("%d" , (arr + i));
    }
    
    
}

void print_array(int *arr , int len){
    
    printf("\nPrinting Array Elements..!!\n");
    
    for(int i=0;i<len;i++){
        
        printf("%d\n",arr[i]);
        
    }
    
}

void insertion_sort(int *arr , int len){
    
    int i , j , item;
    
    printf("\nSorting of Array..!!\n");
    
    for(j=1 ; j<len ; j++){
        
        item = *(arr + j);
        
        i = (j-1);
        
        while((i >= 0) && (arr[i] > item)){
            
            *(arr + (i+1)) = *(arr + i);
            i--;
        }
        
        *(arr + (i+1)) = item;
    }
    
}