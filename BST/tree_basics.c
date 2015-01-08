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
void print_preorder(TreeNode *root);
void print_postorder(TreeNode *root);
TreeNode* find_min(TreeNode *root);
TreeNode* find_max(TreeNode *root);
TreeNode* delete_node(TreeNode* root , int data);

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
    
    printf("Printing the Tree Inorder..!!\n");
    print_inorder(root);
    
    printf("Printing the Tree Preorder..!!\n");
    print_preorder(root);
    
    printf("Printing the Tree Postorder..!!\n");
    print_postorder(root);
    
    retval = find_node(root , 10);
    
    if(NULL == retval)
        printf("Element not found..!!\n");
    else
        printf("elemnet Found: %d\n",retval->data);
    
    retval = find_min(root);
    
    if(NULL == retval)
        printf("Tree Empty..!!\n");
    else
        printf("Min of the Tree: %d\n",retval->data);
    
    retval = find_max(root);
    
    if(NULL == retval)
        printf("Tree Empty..!!\n");
    else
        printf("Max of the Tree: %d\n",retval->data);
    
    
    return 0;
}

TreeNode* find_min(TreeNode *root){
    
    if(NULL == root){
        return NULL;
    }
    if(root->left)
        return find_min(root->left);
    else
        return root;
}

TreeNode* find_max(TreeNode *root){
    
    if(NULL == root){
        return NULL;
    }
    if(root->right)
        return find_max(root->right);
    else
        return root;
    
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

TreeNode* delete_node(TreeNode* root , int data){
    
    TreeNode *temp = NULL;
    
    if(NULL == root){
        printf("Element not found..\n");
    }
    
    else if(data < root->data){
        root->left = delete_node(root->left , data);
    }
    else if(data > root->data){
        root->right = delete_node(root->right , data);
    }
    else{
        
        /*Case where node to be deleted has two children*/
        if(root->left && root->left){
            
            temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right , temp->data);
        }
        
        /*Case where node to be deleted has one or zero children*/
        else{
            temp = root;
            if(NULL == root->left)
                root = root->left;
            else if(NULL == root->right)
                root = root->left;
            free(temp);
            
        }
    }
    return root;
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

void print_preorder(TreeNode *root){
 
    if(NULL == root){
        return;
    }
    
    else{
        printf("%d\n" , root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_postorder(TreeNode *root){
    
    if(NULL == root){
        return;
    }
    else{
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d\n",root->data);
    }
}