//
//  stack_ops.c
//  
//
//  Created by Love Bisaria on 12/28/14.
//
//

#include "../include/stack_ops.h"

int main(){
    
    int result;
    int arr[100] , top = -1;
    LLNode *head = NULL;
    
    /*Demo for Stack as Array*/
    result = push_arr(arr , 10 , &top);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr , 20 , &top);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr , 30 , &top);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr , 40 , &top);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_arr(arr , 50 , &top);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    printf("printing the stack\n");
    print_arr(arr , top);
    
    result = pop_arr(arr , &top);
    if (-1 == result) {
        perror("Pop Unsuccessful\n");
    }else
        printf("Popped Element: %d\n",result);
    
    printf("printing the stack\n");
    print_arr(arr , top);
    
    
    /*Demo for Linked List as a LinkedList*/
    result = push_ll(&head , 11);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_ll(&head , 22);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_ll(&head , 33);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_ll(&head , 44);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    
    result = push_ll(&head , 55);
    if (result == -1) {
        perror("push operation unsucessful\n");
    }
    printf("printing the stack\n");
    print_ll(head);
    
    result = pop_ll(&head);
    if (-1 == result)
        perror("Pop Unsuccessful\n");
    else
        printf("Popped Element: %d\n",result);
    
    printf("Printing the Stack..\n");
    print_ll(head);
    
    
    return 0;
}
/* Array version of Push and Pop */
int push_arr(int *arr , int val , int *top){

    if(99 == *top)
        return -1;
    
    (*top)++;
    arr[*top] = val;
    
    return 1;
}

int pop_arr(int *arr , int *top){
    
    if(-1 == *top)
        return -1;
    
    int retval = arr[*top];
    (*top)--;
    
    return retval;
}
/*Linked List version of Push and Pop*/

int push_ll(LLNode **head , int val){
    
    LLNode *temp = (LLNode*)malloc(sizeof(LLNode));
    
    if (NULL == temp) {
        return -1;
    }
    temp->data = val;
    temp->next = *head;
    *head = temp;
    
    return 1;
    
}

int pop_ll(LLNode **head){

    if (NULL == *head)
        return -1;
    LLNode *temp = *head;
    int retval = temp->data;
    
    *head = (*head)->next;
    free(temp);
    
    return retval;
    
}

void print_arr(int *arr , int top){
    
    for (int i = top; i >= 0; i--) {
        printf("%d\n",arr[i]);
    }
    
}

void print_ll(LLNode *head){
    
    while (head != NULL) {
        
        printf("%d\n",head->data);
        head = head->next;
    }
    
}
