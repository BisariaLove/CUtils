//
//  linked_list_demo.c
//  
//
//  Created by Love Bisaria on 12/27/14.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    
    int data;
    struct node *next;
    
} LLNode;

LLNode* create_List();
void print_list(LLNode *head);

int main(){
    
    LLNode* head1 = NULL ;
    
    head1 = create_List();
    print_list(head1);
    
    
}

/*LLNode* create_List(){
    
    int val;
    char ch = 'y';
    
    LLNode *head = NULL , *temp = NULL , *current = NULL;
    
    do {
        
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
        
        printf("Do you want to continue(y or n)..!!\n");
        ch = getchar();
        
    } while (ch == 'y');
    
    return head;
}*/

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