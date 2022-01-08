#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int a[N];
int n;

//vi tri dau tien cua x trong danh sach
int locate(int x){
    for(int j=0; j<n;j++)
        if(a[j]==x)return j; 
    return -1;
}

//ham rong 
void makeNull(){
    n=0;
}

// tim phan tu ke tiep sau
int next(int p){
    if(0<=p && p<n-1)return p+1;
    return -1;
}

//tim phan tu phia truoc
int prev(int p){
    if(p>0 && p<n-1)return p-1;
    return -1;
}

//them phan tu
void insert(int x, int p){
    for(int j=n-1; j>=p; j--)
        a[j+1]=a[j];
    a[p]=x;
    n=n+1;
}

//xoa phan tu
void delete(int p){
    for(int j= p+1; j<=n-1; j++)
    a[j-1]=a[j];
    n=n-1;
}

//gia tri phan tu
int retrieve(int p){
    return a[p];
}
int main(){ 
    n=100;
    srand((int)time(0));
    for (int i = 0; i < 100; i++)
    {
        insert(rand() % 100, i);
    }
    for (int i = 0; i < 50; i++)
    {
        delete (rand() % 50);
    }
    for (int i = 0; i < 50; i++)
    {
        printf("\n%d", a[i]);
    }
    return 0;
}