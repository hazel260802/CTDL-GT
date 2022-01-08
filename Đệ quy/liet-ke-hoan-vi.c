#include<stdio.h>
int n;
int x[100];
int m[100];
void printSolution(){
    for (int i=1;i<=n;i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void TRY(int i){
    for (int v=1;v<=n;v++){
        if(!m[v]){
            x[i]=v;
            m[v]=1;// mark
            if(i==n)printSolution();
            else TRY(i+1);
            m[v]=0;//reset
            
        }
    }
}
int main(){
    printf("Nhap du lieu: ");
    scanf("%d",&n);
    for(int v=1;v<=n;v++)m[v]=0;
    TRY(1);
    return 0;
}