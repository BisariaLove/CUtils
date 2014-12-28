//
//  sum_llist.c
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
int add_num(LLNode *head1 , LLNode *head2 , LLNode **head_result , int *count,int len);

int main(){
    
    LLNode *head1 = NULL , *head2 = NULL  , *head_result = NULL;
    int count1 = 0 ,count2 = 0 , diff = 0 , gcount = 0;
    
    head1 = create_List();
    head2 = create_List();
    
    count1 = length_of_list(head1);
    count2 = length_of_list(head2);
    
    if(count1 > count2){
        
        diff = count1 - count2;
        
        while (diff > 0) {
            
            insert_beg(&(head2) , 0);
            
            diff--;
        }
    }else if(count2 > count1){
        
        diff = count2 - count1;
        
        while (diff > 0) {
            
            insert_beg(&(head1) , 0);
        }
        
    }
    
    printf("Printing List 1..\n");
    print_list(head1);
    printf("Printing List 2..\n");
    print_list(head2);
    
    int retval = add_num(head1 , head2 , &head_result , &gcount,count1);
    
    if(retval != 1){
        
        printf("Addition of Numbers Failed..\n");
        
    }
    
    printf("Printing Result List..\n");
    print_list(head_result);
    
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
    
    while (temp != NULL) {
        
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

void insert_beg(LLNode **head , int val){
    
    LLNode *temp = (LLNode *)malloc(sizeof(LLNode));
    
    temp->data = val;
    temp->next = (*head);
    (*head) = temp;
    
}

int add_num(LLNode *head1 , LLNode *head2 , LLNode **head_result , int *count,int len){
    
    int sum , dig , carry;
    
    if (head1 == NULL) {
        return 0;
    }
    
    
    
    carry = add_num(head1->next , head2->next , head_result , count,len);
    (*count)++;
    
    sum  = (head1->data) + (head2->data) + carry;
    
    dig = sum%10;
    
    carry = sum/10;
    
    insert_beg(head_result , dig);
    
    if(((*count) == len) && (carry > 0)){
        
        insert_beg(head_result , carry);
        
        return 1;
    }
    
    return carry;
    
    
}

