#include<stdio.h>
int x[100];


bSearch(int x[],int start, int finish, int y){
    if(start==finish){
        if(x[start]==y)
            return start;
        else return -1;
    }
    else{
        int m=(start+finish)/2;
        //Chia bai toan thanh 2 bai toan nho [start,m] & [m+1, finish]
        if(x[m]==y)return m;
        if(x[m]<y)return bSearch(x,m+1,finish,y);
        else return bSearch(x,start,m-1,y);
    }
}
int main() {
    int x[]= {2, 3, 4, 10, 40};
    int n = sizeof(x)/sizeof(x[0]);
    int y=10;
    int result = bSearch(x,0,n-1,y);
    if(result==-1)printf("No result\n");
    else printf("%d xuat hien tai chi so %d",y,result);
    return 0;
}