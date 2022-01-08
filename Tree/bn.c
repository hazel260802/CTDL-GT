#include <stdio.h>
#include <stdlib.h>
/************************************/
/* PHẦN KHAI BÁO                    */
int stk[50], top;
struct BNode{
    int id;
    int visited; //danh dau node visited
    struct BNode* leftChild; // con trỏ đến nút con trái
    struct BNode* rightChild;// con trỏ đến nút con phải
};
typedef struct BNode BNode;
/************************************/
BNode* makeNode(int v){
    BNode* q= (struct BNode*)malloc(sizeof(struct BNode));
    q->leftChild= q->rightChild=NULL;
    q->id= v;
    return q;
}
BNode* insert(BNode* r, BNode* p, int v){
    BNode* n= makeNode(v);
    if(r== NULL||p == NULL)return NULL;
    else if(p->leftChild==NULL){
        p->leftChild=n;
    }
    else if(p->rightChild==NULL){
        p->rightChild=n;
    }
    return n;
}
BNode* r;
//--------------------------DÙNG VÒNG LẶP(WHILE)----------------------------------------------------------------
//Duyệt theo thứ tự giữa
void inorder(BNode* r) {
   BNode* p;
    while(r){
        if(r->leftChild==NULL){
            printf("%d ", r->id);
            r=r->rightChild;
        }
        else{
            p=r->leftChild;
            while(p->rightChild&&p->rightChild!=r){
                p=p->rightChild;
            }
            if(p->rightChild==NULL){
                p->rightChild=r;
                r=r->leftChild;
            }
            else {
                p->rightChild=NULL;
                printf("%d ", r->id);
                r=r->rightChild;
            }
        }
    }
}
//Duyệt theo thứ tự trước
void preorder(BNode* r) {
   BNode* p;
    while(r){
        if(r->leftChild==NULL){
            printf("%d ", r->id);
            r=r->rightChild;
        }
        else{
            p=r->leftChild;
            while(p->rightChild&&p->rightChild!=r){
                p=p->rightChild;
            }
            if(p->rightChild==NULL){
                p->rightChild=r;
                printf("%d ", r->id);
                r=r->leftChild;
            }
            else {
                p->rightChild=NULL;
                r=r->rightChild;
            }
        }
    }
}
//Duyệt theo thứ tự sau

void postorder(BNode* r) {
    BNode* temp=r;
    while(temp&&temp->visited==0){
     // Visited left subtree
        if (temp->leftChild && temp->leftChild->visited == 0)
            temp = temp->leftChild;
 
        // Visited right subtree
        else if (temp->rightChild && temp->rightChild->visited == 0)
            temp = temp->rightChild;
 
        // Print node
        else {
            printf("%d ", temp->id);
            temp->visited = 1;
            temp = r;
        }       
    }
}
//--------------------------DÙNG ĐỆ QUY------------------------------------------------
//Duyệt theo thứ tự giữa
void inOrder(BNode* r) {
    if(r == NULL) return;
    inOrder(r->leftChild);
    printf("%d ",r->id);
    inOrder(r->rightChild);
}
//Duyệt theo thứ tự trước

void preOrder(BNode* r) {
    if(r == NULL) return;
    printf("%d ",r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}

//Duyệt theo thứ tự sau
void postOrder(BNode* r) {
    if(r == NULL) return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ",r->id);
}
int count(BNode* r) {
    if(r == NULL) return 0;
    return 1 + count(r->leftChild) +count(r->rightChild);
}
void printTree_NLR(BNode *p){
	if (p != NULL){
        printf("%d ", p->id);
		printTree_NLR(p->leftChild);
		printTree_NLR(p->rightChild);
	}
}
int main (){
    printf("---------------Create a binary tree----------------\n");
    //-------------------------------------------------------ADD NODE----------------------------------------------------
    r=makeNode(10);
    
    BNode* p=insert(r,r,1);
    BNode* p1=insert(r,p,5);
    BNode* p2=insert(r,p,6);

    BNode* q=insert(r,r,2);
    BNode* q1=insert(r,q,4);
    BNode* q2=insert(r,q,7);

    printf("Binary tree after insertion\n");
    printTree_NLR(r);
    printf("\n");

    printf("The number of nodes in the tree: %d\n",count(r));

    printf("Traverse the tree in order from the beginning:\n");
    preorder(r);
    printf("\n");
    preOrder(r);
    printf("\n");
    printf("Traverse the tree in order from the middle:\n");
    inorder(r);
    printf("\n");
    inOrder(r);
    printf("\n");
    printf("Traverse the tree in order from the end:\n");
    postorder(r);
    printf("\n");
    postOrder(r);
    printf("\n");
    return 0;
}