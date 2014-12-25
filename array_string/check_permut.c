//
//  check_permut.c
//  CTCI - Question - 1.3
//
//  Created by Love Bisaria on 12/18/14.
//
//

#include "../include/check_permut.h"

int main(){
    
    char str1[MAXARRAYSIZE], str2[MAXARRAYSIZE];
    
    printf("Enter String1..!!\n");
    scanf("%s" , str1);
    printf("Enter String1..!!\n");
    scanf("%s" , str2);
    
    int result = isPermutation(str1 , str2);
    
    if(result == 0)
        printf("Strings are permutation of each other..!!\n");
    else
        printf("Strings are not permutation of each other..!!\n");
    
    return 0;
}


void insertion_sort(char *arr , int len){
    
    int i , j ;
    char item;
    
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

int isPermutation(char *str1 , char *str2){
    
    insertion_sort(str1 , strlen(str1));
    insertion_sort(str2 , strlen(str2));
    
    return strcmp(str1 , str2);
    
}