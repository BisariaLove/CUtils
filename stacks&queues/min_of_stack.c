//
//  min_of_stack.c
//  CTCI - Question - 3.2
//
//  Created by Love Bisaria on 12/29/14.
//
//

#include <stdio.h>

int push_arr(int *arr , int val , int *top);
int pop_arr(int *arr , int *top);
int peek_arr(int *arr , int top);
int push_min(int val);
void print_arr(int *arr , int top);

static int min_top = -1 , min[100];

int main(){
    
    int result;
    int arr1[100] , top1 = -1;
    
    result = push_arr(arr1 , 44 , &top1);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr1 , 11 , &top1);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr1 , 22 , &top1);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    printf("Printing the stack..\n");
    print_arr(arr1 , top1);
    result = peek_arr(min , min_top);
    printf("Min of the array is: %d\n" ,result);
    
    result = push_arr(arr1 , 9 , &top1);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    printf("Printing the stack..\n");
    print_arr(arr1 , top1);
    result = peek_arr(min , min_top);
    printf("Min of the array is: %d\n" ,result);
    
    return 0;
}

int push_arr(int *arr , int val , int *top){
    
    if(99 == *top)
        return -1;
    
    (*top)++;
    arr[*top] = val;
    
    push_min(arr[*top]);
    
    return 1;
}

int pop_arr(int *arr , int *top){
    
    if(-1 == *top)
        return -1;
    
    int retval = arr[*top];
    (*top)--;
    
    if(retval == min[min_top])
        min_top--;
    
    return retval;
}

void print_arr(int *arr , int top){
    
    for (int i = top; i >= 0; i--) {
        printf("%d\n",arr[i]);
    }
    
}

/*
 * peek_arr function returns the value at the top
 * of the stack, without deleting it.
 */

int peek_arr(int *arr , int top){

    if(-1 == top)
        return -1;
    
    int retval = arr[top];
    return retval;
}

int push_min(int val){
    
    //printf("Val: %d , min[min_top]: %d , min_top: %d\n", val , min[min_top] , min_top);
    if((val <= min[min_top]) || (-1 == min_top)){
        min_top++;
        min[min_top] = val;
        
    }
    //printf("After Insertion min[min_top]: %d , min_top: %d\n",min[min_top] , min_top);
    
    return 1;
}