#include <stdio.h>
#define N 1000
int n,m;
int A[N][N];// A[v] is the list of adjacent nodes of v 
int szA[N];// szA[v] is the size of A[v]
// data structure for connected component
int ncc;
int icc[N];// icc[u] is the index of connected component of u 
void input(){
    scanf("%d%d",&n,&m);
    for(int v = 1; v <= n; v++) szA[v] = 0; 
    for(int k = 1; k <= m; k++){
        int u,v;
        scanf("%d%d",&u,&v);
        A[v][szA[v]] = u; 
        A[u][szA[u]] = v; 
        szA[v]++; 
        szA[u]++;
        } 
}
void dfs(int u){ 
    icc[u] = ncc;
    for(int i = 0; i < szA[u]; i++){ 
        int v = A[u][i];
        if(icc[v] == -1){
            // not visited
            dfs(v); 
        }
    } 
}
void dfsGraph(){
    for(int v = 1; v <= n; v++) icc[v] = -1;
    ncc = 0;
    for(int v = 1; v <= n; v++) if(icc[v] == -1){
        ncc++;
        dfs(v); 
    }
    for(int k = 1; k <= ncc; k++){
        printf("connected component %d: ",k);
        for(int v = 1; v <= n; v++) if(icc[v] == k) printf("%d ",v); 
        printf("\n");
    } 
}
void main(){
    input();
    dfsGraph();
}
    