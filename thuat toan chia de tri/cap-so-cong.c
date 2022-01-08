#include <stdio.h>
#define N 100
int s[N];
int a[N];

int csc(int a[], int n){
    s[0]=1;
    int rs=r[0];
    for(int i=1; i<=n; i++){
        s[i]=1;
        for(int j=i-1;j>=0; j--)
        if(a[i]-a[j]==1)
            if(s[j]+1>s[i])
            s[i]=s[j]+1;
        rs=s[i]>rs ? s[i]:rs;
    }
    printf("%d\n",rs);
}
int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    csc(a,n);
    return 0;
}