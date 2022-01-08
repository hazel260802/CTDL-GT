#include<stdio.h>
#include<math.h>

int n,count;
int a[20];
int Ghinhan(){
    int i;
    count++;
    printf("%i. ",count);
    for(i=1;i<=n;i++)printf("%i ",a[i]);
    printf("\n");
}

int UCVh(int j, int k){
    /* UCVh nhan gia tri 1 khi va chi khi j thuoc Sk*/
    int i;
    for(i=1;i<=n;i++)
    if ((j==a[i])|| (fabs(j-a[i])==k-i))return 0;
    return 1;
}

int Hau (int i){
    int j;
    for(j=1;j<=n;j++)
        if (UCVh(j,i)){
            a[i]=j;
            if(i==n)Ghinhan();
            else Hau(i+1);
        }
}
int main(){
    printf("Input n= ");
    scanf("%d",&n);
    count=0;
    Hau(1);
    if(count==0)printf("No solution!\n");
    getchar();
    printf("\n Press enter to finish.\n");
    getchar();
}