//
//  ll_of_ll.c
//  
//
//  Created by Love Bisaria on 12/30/14.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
} LLNode;

typedef struct list_of_list{
    
    struct node *head_of_list;
    struct list_of_list *next_stack;
    
}LOLNode;

LLNode* create_List();
void print_list(LLNode *head);
int insert_lol_node(LOLNode **head , LLNode *head1);
void print_lol_nodes(LOLNode *head);


int main(){
    
    LLNode *head1 = NULL;
    LOLNode *head = NULL;
    
    head1 = create_List();
    
    insert_lol_node(&head , head1);
    
    head1 = create_List();
    
    insert_lol_node(&head , head1);
    
    printf("Printing the Top of lists..\n");
    
    print_lol_nodes(head);
    
    
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
    
    LOLNode *last = NULL;
    
    temp->head_of_list = head1;
    temp->next_stack = NULL;
    
    if(NULL == (*head)){
        
        (*head) = temp;
    
    }else{
        
        last = (*head);
        
        while (last->next_stack != NULL) {
            last = last->next_stack;
        }
        
        last->next_stack = temp;
        last = temp;
    }
    
    return 1;
}

void print_lol_nodes(LOLNode *head){
    
    int i =0;
    while (head != NULL) {
        printf("List %d head->data: %d\n" , i,head->head_of_list->data);
        head = head->next_stack;
        
    }
    
}