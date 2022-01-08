#include<stdio.h>
#define N 100
int s[N][N];
int x[N],y[N];
void solve(int x[], int y[],int n, int m){
    int rs=0;
    for(int i=0;i<=n;i++) s[i][0]=0;
    for(int j=0;j<=m;j++) s[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i]==y[j])s[i][j]=s[i-1][j-1]+1;
            else{
                s[i][j]= s[i-1][j]>s[i][j-1] ? 
                s[i-1][j] : s[i][j-1];
            }
            rs=s[i][j]>rs ? s[i][j]:rs;
        }
    }
    printf("result = %d\n",rs);
}
int main() {
    printf("Nhap vao so phan tu cua mang 1: ");
    scanf("%d",&n);
    printf("Nhap vao so phan tu cua mang 2: ");
    scanf("%d",&m);
    for(int i=1;i<=n;i++){
        scanf("%d", &x[i]);
    }
    for(int j=1;j<=m;j++){
        scanf("%d",&y[j]);
    }
    solve(x,y,n,m);
    return 0;
}