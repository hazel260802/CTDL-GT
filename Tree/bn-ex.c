#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

typedef struct tree_node{
    struct tree_node *left;
    struct tree_node *right;
    int data;
} TREE_NODE;

void Preorder_iter(TREE_NODE* root){
    TREE_NODE* curr=treeRoot;
    STACK* stack= createStack(MAX);//khoi tao stack
    while(curr!=NULL||IsEmpty(stack)){
        printf("%d: ",curr->data);//tham curr
        //neu co cay con phai, day cay con phai vao stack
        if(curr->right!= NULL)pushStack(stack, cur->right);
        if(curr->left!=NULL)cur=cur->left;//duyet cay con trai
        else popStack(stack,&curr);//duyet cay con phai
    }
    destroyStack(&stack);//giai phong stack
}
void Inorder_iter(TREE_NODE* root){
    TREE_NODE* curr = root;
    STACK* stack=createStack(MAX);//ktao stack
    while (curr!= NULL ||!IsEmpty(stack))
    {
        if(curr== NULL)popStack(stack,&curr);
        printf("%d ",curr->data);
        curr = curr->right;
    }
    else {
        pushStack(stack,curr);
        curr=curr->left;//duyet cay con trai
    }
    destroyStack(stack);//giai phong stack
}
void Postorder_iter(TREE_NODE* treeRoot){
    TREE_NODE* curr = treeRoot;
    STACK* stack = createStack(MAX);
    while(curr!=NULL || !IsEmpty(stack)){
        if(curr==NULL){
            while(!IsEmpty(stack)&&cur==Top(stack)->right){
                PopStack(stack, &curr);
                printf("%d ",curr->data);
            }
            curr=isEmpty(stack)? NULL: Top(stack)->right;
        }
        else{

        }
    }
}
int main(){

TREE_NODE *root, *leftChild, *rightChild;

//Tao nut con trai
leftChild = (TREE_NODE*)malloc(sizeof(TREE_NODE));
leftChild->data=20;
leftChild->left=leftChild->right=NULL;

//Tao nut con phai
rightChild = (TREE_NODE*)malloc(sizeof(TREE_NODE));
rightChild->data=30;
rightChild->right=rightChild->left=NULL;

//Tao nut goc
root= (TREE_NODE*)malloc(sizeof(TREE_NODE));
root->data=10;
root->left=leftChild;
root->right=rightChild;

root -> data  = 50; // gán 50 cho root
}