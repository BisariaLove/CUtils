//
//  ll_of_ll.c
//  
//
//  Created by Love Bisaria on 12/30/14.
//
//

#include <stdio.h>
#include <stdlib.h>

LLNode* create_List();
void print_list(LLNode *head);

typedef struct node{
    int data;
    struct node* next;
} LLNode;

typedef struct list_of_list{
    
    struct node *head_of_list;
    struct stack_list *next_stack;
    
}LOLNode;


int main(){
    
    LLNode *head1 = NULL;
    LOLNode *head = NULL;
    
    head1 = create_List();
    
    insert_lol_node(&head , head1);
    
    head1 = create_List();
    
    insert_lol_node(&head , head1);
    
    
    
    
    return 0;
}

LLNode* create_List(){
    
    int size , val , i=0;
    LLNode *head = NULL , *temp = NULL , *current = NULL;
    
    printf("Enter the size of LinkedList..\n");
    scanf("%d" , &size);
    
    while (i<size) {
        
        temp = (LLNode*) malloc (sizeof(LLNode));
        
        printf("Enter the Node Element..\n");
        scanf("%d" , &val);
        
        temp->data = val;
        temp->next = NULL;
        
        if(head == NULL){
            
            head = current = temp;
            
        }else{
            
            current->next = temp;
            current = temp;
            temp = NULL;
        }
        
        i++;
    }
    
    return head;
    
}

void print_list(LLNode *head){
    
    LLNode *temp = NULL;
    
    temp = head;
    
    while (temp!= NULL) {
        
        printf("Data: %d\n" ,temp->data );
        temp = temp->next;
        
    }
    
}

/*Maintain a List of Lists , with insertion of the list node at the end*/

int insert_lol_node(LOLNode **head , LLNode *head1){
    
    LOLNode *temp = (LOLNode *) malloc(sizeof(LOLNode));
    
    if(temp == NULL)
        return -1;
    
    LOLNode *last = NULL
    
    temp->head_of_list = head1;
    temp->next = NULL;
    
    if(NULL == (*head)){
        
        (*head) = temp;
    
    }else{
        
        last = (*head);
        
        while (last->next != NULL) {
            last = last->next;
        }
        
        last->next = temp;
        last = temp;
    }
    
    return 1;
}

void print_lol_nodes(LOLNode *head){
    
    int i =0;
    while (head->next_stack != NULL) {
        printf("List %d head->data: %d" , head->head_of_list->data);
        
    }
    
}