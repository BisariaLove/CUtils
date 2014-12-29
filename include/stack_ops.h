//
//  stack_ops.h
//  
//
//  Created by Love Bisaria on 12/28/14.
//
//

#ifndef ____stack_ops__
#define ____stack_ops__

#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
} LLNode;

int push_arr(int *arr , int val , int *top);
int pop_arr(int *arr , int *top);
int push_ll(LLNode **head , int val);
int pop_ll(LLNode **head);
void print_arr(int *arr , int top);
void print_ll(LLNode *head);

#endif /* defined(____stack_ops__) */
