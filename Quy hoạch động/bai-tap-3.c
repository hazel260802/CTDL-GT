#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//cach mat thoi gian O(n2)
int maxSubSeq1(int a[], int n){
    int start=0,end=0;
    int s;
    int ans=-99999999;
    for(int i=0;i<n;i++){
        for (int j =i; j<n;j++) {
        s=0;
        for (int k =i; k<=j;k++){
            s=s+a[k];
        }
        if (s>ans) {
            ans=s;
        }
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
        a[i]=-100+rand()%(201);
        printf("%d ",a[i]);
    }
    printf("\n");
    maxSubSeq1(a,n);
    return 0;
}