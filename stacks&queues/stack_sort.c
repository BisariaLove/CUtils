//
//  stack_sort.c
//  CTCI - Question - 3.6
//
//  Created by Love Bisaria on 1/1/15.
//
//

#include <stdio.h>

int push_ll(LLNode **head , int val);
int pop_ll(LLNode **head);
void print_ll(LLNode *head);
int peek_ll(LLNode *head);

int main(){
    
    int result , size , i , val;
    LLNode *head = NULL , *new_head = NULL;
    
    printf("Enter the size of the stack..\n");
    scanf("%d" , &size);
    
    for (i = 0; i < size; i++) {
        scanf("%d" , &val);
        result = push_ll(&head , val);
        
        if (result == -1) {
            perror("push operation unsucessful\n");
        }
    }
    
    new_head = stack_sort(head);
    printf("Printing the Sorted Stack..\n");
    print_ll(new_head);
    
    return 0;
}

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


void print_ll(LLNode *head){
    
    while (head != NULL) {
        
        printf("%d\n",head->data);
        head = head->next;
    }
    
}

int peek_ll(LLNode *head){
    
    if(NULL == head){
        return -1;
    }
    
    int retval = head->data;
    return retval;
}

LLNode* stack_sort(LLNode *head){
    
    /*Creating another Stack*/
    
    LLNode *new_head = NULL , *temp = NULL;
    int retval , result;
    temp = head;
    
    retval = pop_ll(&head);
    
    while((temp != NULL) && (new_head->data > retval)){
        
        result = push_ll(&head , pop_ll(new_head));
        
        if (result == -1) {
            perror("push operation unsucessful\n");
        }
    }
    
    result = push_ll(&new_head , retval);
}
