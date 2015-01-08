//
//  tree_basics.c
//  
//
//  Created by Love Bisaria on 1/7/15.
//
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node{
    
    struct tree_node *parent;
    int data;
    struct tree_node *left;
    struct tree_node *right;
    
}TreeNode;

typedef struct BST{
    
    struct tree_node *root;
    int size;
    
}BST;

TreeNode* find_node(TreeNode *root , int data);
TreeNode* insert_node(TreeNode *node , int val);
void print_inorder(TreeNode *root);

int main(){
    
    TreeNode *root = NULL , *retval = NULL;
    
    root = insert_node(root, 5);
    root = insert_node(root, -1);
    root = insert_node(root, 3);
    root = insert_node(root, -14);
    root = insert_node(root, 8);
    root = insert_node(root, 10);
    root = insert_node(root, 9);
    root = insert_node(root, 6);
    
    printf("Printing the Tree..!!\n");
    print_inorder(root);
    
    retval = find_node(root , 10);
    
    if(NULL == retval)
        printf("Element not found");
    else
        printf("%d",retval->data);
    
    return 0;
}

TreeNode* insert_node(TreeNode *node , int val){
    
    TreeNode *temp = NULL ;
    
    if(NULL == node){
        temp = (TreeNode*) malloc(sizeof(TreeNode));
        
        if(NULL == temp){
            perror("Out of Memory , Exiting..!!\n");
            exit(1);
        }
        temp->data = val;
        temp->left = temp->right = NULL;
        
        return temp;
    }
    
    if(val > (node->data)){
        node->right = insert_node(node->right , val);
    }
    else if(val < (node->data)){
        node->left = insert_node(node->left , val);
    }
    
    return node;
    
    
}

TreeNode* find_node(TreeNode *root , int data){
    
    if(NULL == root){
        return NULL;
    }
    
    if(data > root->data){
        return find_node(root->right , data);
    }
    
    if(data < root->data){
        return find_node(root->left , data);
    }
    
    else{
        return root;
    }
}

void print_inorder(TreeNode *root){
    
    if(NULL == root){
        return;
    }
    else{
        print_inorder(root->left);
        printf("%d\n",root->data);
        print_inorder(root->right);
    }
}
