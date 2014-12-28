//
//  check_pldrm_ll.c
//  CTCI - Question - 2.7
//
//  Created by Love Bisaria on 12/28/14.
//
//

#include <stdio.h>
#include <stdlib.h>

#define true   1
#define false  0

typedef struct node{
    
    int data;
    struct node *next;
    
} LLNode;

LLNode* create_List();
void print_list(LLNode *head);
int is_palindrome_reverse(LLNode *head , int length , LLNode **nextNode);
int length_of_list(LLNode *head);

int main(){
    
    LLNode *head = NULL , *nextNode = NULL;
    int retval = -1 , length = -1;
    
    head  = create_List();
    length = length_of_list(head);
    
    printf("Length of the list: %d\n",length);
    
    printf("Printing the List..\n");
    print_list(head);
    
    retval = is_palindrome_reverse(head , length , &nextNode);
    
    if(retval == false){
        printf("Not Palindrome..\n");
    }else{
        printf("Palindrome..\n");
    }
    
    return 0 ;
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

int length_of_list(LLNode *head){
    
    int len = 0;
    
    while (head != NULL) {
        
        len++;
        head = head->next;
    }
    
    return len;
    
}

/*Recursive method to check if a Linked List is Palindrome*/

int is_palindrome_reverse(LLNode *head , int length , LLNode **nextNode){
    
    int retval = -1;
    
    if((NULL == head) || (0 == length)){
        
        *(nextNode) = NULL;
        return true;
        
    }else if(1 == length){
        
        *(nextNode) = head->next;
        return true;
        
    }else if(2 == length){
        
        *(nextNode) = head->next->next;
        return (head->data == head->next->data);
        
    }
    
    retval = is_palindrome_reverse(head->next , length-2 , nextNode);
    
    if(false == retval || NULL == nextNode){
        
        return retval;
    }else{
        
        retval = (head->data == (*nextNode)->data);
        *(nextNode) = (*nextNode)->next;
        return retval;
    }
}

