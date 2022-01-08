#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int value;
    struct Node* next;
}Node;

Node* p,q, h, head;

Node *makeNode(int x){
    Node* q = (struct Node*) malloc(sizeof(struct Node));
    q->value = x; 
    q->next = NULL;
return q;
}

Node* insertAfter(Node* h, Node* p, int x){
    if(p == NULL)return h;
    Node *newNode = makeNode(x);
    if(h==NULL)return newNode;
    newNode->next = p->next;
    p->next = newNode;
    return h;
}

void printList(Node *h){
    Node *p =h;
    printf("Print out a linked list of nodes\n");
    while(p != NULL){
        printf("[%d] ->  ", p->value);
        p = p->next;
    }
}
Node *findLast(Node *h){
    Node *p = h;
    while(p != NULL){
        if(p->next == NULL)return p;
        p = p->next;
    }
    return NULL;
}

Node* insertLast(Node* h, int x){
    Node *q= makeNode(x);
    if(h==NULL)return q;
    Node* p =h;
    while(p->next != NULL)
        p= p->next;
    p->next=q;
    return h;
}
Node* locate(Node* h, int x){
    Node* p = h;
    while(p != NULL){
        if(p->value == x) return p;
        p = p->next;
    }
    return NULL;
}
Node* prev(Node* h, Node* p){
    Node* q = h;
    while(q != NULL){
        if(q->next == p) return q;
        q = q->next;
    }
    return NULL;
}
//Insert 1 node moi vao trong vi tri cua node p

// Cach 1: 
Node* insertAt(Node* h, Node* p, int x){
    Node* pp = prev(h,p);
    // Tim thang dung truoc cua p la pp
    if(pp == NULL && p != NULL)  
    return h;
    Node* q = makeNode(x);
    if(pp == NULL){
        if(h == NULL)return q;
        q->next = h;
        return q;
    }q->next = p;    
    pp->next = q;
    return h;
}

// Cach 2: 
Node* insertAtRecursive(Node* h, Node* p, int x){
    if(p == NULL) return h;
    if(h == NULL || p == h){
        return makeNode(x);
    }
    else{
        h->next = insertAtRecursive(h->next,p,x);
        return h;
    }
}

// Tinh tong cac gia tri trong node

// Cach 1:
int sum(Node* h){
    Node* p = h;
    int S = 0;
    while(p != NULL) {
        S = S + p->value;p = p->next;
    } 
    return S; 
}

// Cach 2:
int sumRecursive(Node* h){
    if(h == NULL) return 0;
    return h->value + sumRecursive(h->next);
}

int main (){
    printf("Create a single linked list of nodes\n");
    Node *head;
    head=makeNode(100);
    printList(head);

    printf("Add a node after to the list\n");
    insertAfter(head,head,20);

    printf("Add a node at the last of the list\n");
    insertLast(head,30);
    insertLast(head,40);
    insertLast(head,50);
    insertLast(head,60);

    printf("Initial list\n");
    printList(head);

    printf("Insert node after one position\n");
    Node* n2= locate(head,30);
    printf("The value after n2: %d\n",n2->next->value);

    printf("Insert node before one position\n");
    Node* n1= prev(head,n2);
    printf("The value before n2: %d\n",n1->value);

    printf("Insert value before n2: ");
    insertAt(head,n2,2020);

    printf("List after changes: \n");
    printList(head);

    printf("\nThe last value of the list: %d\n", findLast(head)->value);
    return 0;

}
