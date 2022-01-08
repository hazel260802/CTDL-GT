#include<stdio.h>
typedef struct DNode{
    int val;
    struct DNode* prev;
    struct DNode* next;
}DNode;
DNode* first;
DNode* last;

DNode* makeNode(int v){
    DNode* p= (struct DNode*) malloc(sizeof(struct DNode));
    p->val=v;
    p->val=v;
    p->next=NULL;
    p->prev=NULL;

    return p;
}
void printListHead(DNode* first){
    printf("Print list from head\n");
    DNode* p=first;
    while(p!= NULL){
        printf("[%d] -> ", p->val);
        p=p->next;
    }
    printf("\n");
}
void printListLast(DNode* last){
    DNode* p=last;
    printf("Print list from last\n");
    while(p!= NULL){
        printf("[%d] -> ", p->val);
        p=p->prev;
    }
    printf("\n");
}
DNode* locate1(DNode* first, int x){
    DNode* p=first;
    while(p!= NULL){
        if(p->val == x){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return NULL;
}
DNode* locate2(DNode* prev, int x){
    DNode* p=prev;
    while(p != NULL){
        if(q->next == p) return p;
        p=p->next;
    }
    return NULL;
}
DNode* next(DNode* first, DNode* p){
    DNode* q=first;
    while(q != NULL){
        if(q!= NULL){
            if(q==p)return q->next;
            q=q->next;
        }
    }
    return  NULL;
}
void insertLast(DNode* first, DNode* last, int x){
    DNode* p= makeNode(x);
    printf("Insert node q at last\n");
    if(first==NULL && last==NULL){
        first=p;
        last=p;
        printListLast();
    }
    else{
        q->prev=las;
        last->next=q;
        last=q;
        printListLast();
    }

}
void insertFirst(DNode* first, DNode* last, int x){
    DNode *q=makeNode(x);
    printf("Insert node q at first\n");
    if(first==NULL && last==NULL){
        first=q;
        last=q;
        printListHead();
    }
    else{
        q->next=first;
        first->prev=q;
        first=q;
        printListHead();
    }
}

void insertAt (DNode* first, DNode* last, DNode* p, int x){
    DNode* q= makeNode(x);
    if(p==first){
        if(first==NULL)
    }
}
void remove(DNode* first, DNode* last, DNode *p){
    if(p==first){
        first=first->next;
        first->prev=NULL;
    }
    else if(p==last){
        last=last->prev;
        last->next=NULL;
    }
    else{
        p->prev->next=p->next;
        p->next->prev = p->prev;
    }
}