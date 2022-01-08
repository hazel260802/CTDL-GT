#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//Cach mat thoi gian O(n)
int maxSubSeq1(int a[], int n){
    int s[10000];
    int start=0,end=0;
    s[0]=a[0];
    int ans=s[0];
    for(int i=1; i<n;i++){
        if(s[i-1]>0){
            s[i]=s[i-1]+a[i];
        }
        else {
        s[i]=a[i];
        }
        if(s[i]>ans){
            ans=s[i];
        }
    }
    printf("Day con co trong so lon nhat: \n");
    for (int i = start; i <= end;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("Trong so cua day:%d\n",ans);
    return 0;
}
int main(){
    int a[100],n;
    srand(time(NULL));
    printf("Nhap vao so phan tu mong muon:\n");
    scanf("%d",&n);
    printf("Sinh day ngau nhien: \n");
    for (int i = 0; i < n; i++){
        a[i]=-100+rand()%(101);
        printf("%d ",a[i]);
    }
    printf("\n");
    maxSubSeq1(a,n);
    return 0;
}