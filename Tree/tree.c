#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int id;
    struct Node* leftMostChild;// con tro tro den nut con trai nhat
    struct Node* rightSibling;// con tro tro den nut anh em ben phai
    }Node;
Node* root;// con tro tro den nut goc


Node* makeNode(int v){
    Node* q = (struct Node*) malloc(sizeof(struct Node));
    q->id=v;
    q->leftMostChild =NULL;
    q->rightSibling=NULL;
    return q;
}

Node* insert(Node* r, Node* p, int v){
    Node* q = makeNode(v);
    if(r==NULL||p == NULL) return NULL;
    if(p->leftMostChild==NULL) {
            p->leftMostChild=q;
    }
        else{
            Node* h = p->leftMostChild;
            while((h->rightSibling)!=NULL) {
                h = h->rightSibling;
            }
            h->rightSibling = q;
        }
    return q;
}
//Tìm một nút có nhãn cho trước trên cây
Node* find(Node* r, int v){
    if(r == NULL) return NULL;
    if(r->id == v) return r;
    Node* p = r->leftMostChild;
    while(p != NULL){
        Node* h = find(p,v);
        if(h != NULL) return h;
        p = p->rightSibling;
    }
    return NULL;
}

//Duyệt theo thứ tự trước
void preOrder(Node* r){
    if(r == NULL) return;
    printf("%d ",r->id);
    Node* p = r->leftMostChild;
    while(p != NULL){
        preOrder(p);p = p->rightSibling;
    }
}

//Duyệt theo thứ tự giữa
void inOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    inOrder(p);
    printf("%d ",r->id);
    if(p != NULL) p = p->rightSibling;
    while(p != NULL){
        inOrder(p);
        p = p->rightSibling;
    }
}

//Duyệt theo thứ tự sau
void postOrder(Node* r){
    if(r == NULL) return;
    Node* p = r->leftMostChild;
    while(p != NULL){
        postOrder(p);
        p = p->rightSibling;
    }
    printf("%d ",r->id);
}

//Đếm số nút trên cây
int count(Node* r){
    if(r == NULL) return 0;
    int s = 1;
    Node* p = r->leftMostChild;
    while(p != NULL){
        s += count(p);
        p = p->rightSibling;
    }
    return s;
}

//Đếm số nút lá trên cây
int countLeaves(Node* r){
    if(r == NULL) return 0;
    int s = 0;
    Node* p = r->leftMostChild;
    if(p == NULL) s = 1;
    while(p != NULL){
        s += countLeaves(p);
        p = p->rightSibling;
    }
    return s;
}

//Độ cao của một nút
int height(Node* p){
    if(p == NULL) return 0;
    int maxh = 0;
    Node* q = p->leftMostChild;
    while(q != NULL){
        int h = height(q);
        if(h > maxh) maxh = h;
        q = q->rightSibling;
    }
    return maxh + 1;
}

//Độ sâu của một nút
int depthRecursion(Node* r, int v, int d){
    // d la do sau cua nut r
    if(r == NULL) return -1;
    if(r->id == v) return d;
    Node* p = r->leftMostChild;
    while(p != NULL){
        if(p->id == v) return d+1;
        int dv = depthRecursion(p,v,d+1);
        if(dv > 0) return dv;p = p->rightSibling;
        }
    return -1;
}
int depth(Node* r, int v){
    return depthRecursion(r,v,1);
}

//Tìm nút cha của một nút
Node* parent(Node* p, Node* r){
    if(r == NULL) return NULL;
    Node* q = r->leftMostChild;
    while(q != NULL){
        if(p == q) return r;
        Node* pp = parent(p, q);
        if(pp != NULL) return pp;
        q = q->rightSibling;
    }
    return NULL;
}
void printTree_NLR(Node *p){
	if (p != NULL){
        printf("%d ", p->id);
		printTree_NLR(p->leftMostChild);
		printTree_NLR(p->rightSibling);
	}
}
int main(){
    printf("Create a tree of nodes\n");
    root=makeNode(10);

    Node* p= insert(root,root, 2);
    Node* x1= insert(root,p,5);
    Node* x2= insert(root,p,6);

    Node* q= insert(root,root,3);
    Node* x3= insert(root,q,7);
    Node* x4= insert(root,q,8);

    printf("Find a node in the tree: ");
    printf("%d\n", (find(root,2))->id);

    printf("Find a parent of node x1: %d\n", (parent(x1,root))->id);
    printf("Find a parent of node x2: %d\n", (parent(x2,root))->id);

    printf("The height of node x1 in the tree: %d\n", height(x1));
    printf("The height of node x2 in the tree: %d\n",height(x2));

    printf("The depth of node x1 in the tree: %d\n",depth(root,x1->id));
    printf("The depth of node x2 in the tree: %d\n",depth(root,x2->id));

    printf("The number of nodes in the tree: %d\n",count(root));
    printf("The number of leaves in the tree: %d\n",countLeaves(root));

    printf("Tree after insertion\n");
    printTree_NLR(root);
    printf("\n");

    printf("Traverse the tree in order from the beginning:\n");
    preOrder(root);
    printf("\n");
    printf("Traverse the tree in order from the middle:\n");
    inOrder(root);
    printf("\n");
    printf("Traverse the tree in order from the end:\n");
    postOrder(root);
    printf("\n");
    return 0;
}