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
int length_of_list(LLNode *head);
void insert_beg(LLNode **head , int val);
LLNode* reverse_list(LLNode *head);

LLNode* reverse_list(LLNode *head);

int main(){
    
    LLNode* head1 = NULL ;
    
    head1 = create_List();
    print_list(head1);
    
    printf("Reversing the list..\n");
    head1 = reverse_list(head1);
    print_list(head1);
    
    return 0;
    
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

void insert_beg(LLNode **head , int val){
    
    LLNode *temp = (LLNode *)malloc(sizeof(LLNode));
    
    temp->data = val;
    temp->next = (*head);
    (*head) = temp;
    
}

int length_of_list(LLNode *head){
    
    int len = 0;
    
    while (head != NULL) {
        
        len++;
        head = head->next;
    }
    
    return len;
    
}

LLNode* reverse_list(LLNode *head){
    
    LLNode *p = NULL ,*q = NULL , *r = NULL;
    p = head ;
    q = p->next;
    
    while ((p != NULL)) {
        
        if (r == NULL) {
            
            r = p;
            r->next = NULL;
            
        }else{
            
            p->next = r;
            r = p;
        }
        
        p = q;
        if(q != NULL)
            q = q->next;
        
        
    }
    
    return r;
}