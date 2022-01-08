#include<stdio.h>

int a[100];
// Tim tong cuc dai dai nhat trong day
int maxSeq(int* a, int l, int r){
    if(l==r)return a[l];
    int max;
    int mid= (l+r)/2;
    int mL = maxSeq(a,l,mid);
    int mR = maxSeq(a,mid+1,r);
    int mLR = maxLeft(a,l,mid)+maxRight(a,mid+1,r);
    max =mL;
    if(max<mR)max =mR;
    if(max<mLR)max =mLR;
    return max;
}
int maxxLeft(int* a, int l, int r){
    int max=-99999999;
    int s=0;
    for(int i=r;i>=1;i--){
        s+=a[i];
        if(s>max)max = s;
    }
    return max;
}
int maxxRight(int* a, int l, int r){
    int max=-99999999;
    int s=0;
    for(int i=1;i<=r;i++){
        s+=a[i];
        if(s>max)max = s;
    }
    return max;
}
int main() {
    readData();
    int rs = maxSeq(a,0,n-1);
    printf("result = %d\n",rs);
    return 0;
}