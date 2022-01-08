#include<stdio.h>
#define N 100
int s[N];
int a[N];
void solve(int a[],int n){
    s[0]=1;
    rs = s[0];
    for(int i=1; i<n;i++) {
        s[i]=i;
        for(int j=i-1;j>=0;j--){
            if(a[i]>a[j]){
                if(a[i]>a[j]){
                    if(s[j]+1>s[i])
                        s[i]=s[j]+1;
                }
            }
        rs=s[i]>rs?s[i]:rs;
    }
    printf("rs=%d\n",rs);
}
int main() {
    int n;
    printf("Nhap vao so phan tu: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    solve(a,n);
}