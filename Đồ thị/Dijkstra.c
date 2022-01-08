#include <stdio.h> 
#include <vector> 
#define MAX 100001 
#define INF 1000000 
using namespace std;
vector<int> A[MAX]; // A[v][i] is the i^th adjacent node to v 
vector<int> c[MAX]; // c[v][i] is the weight of the i^th adjacent arc
// (v,A[v][i]) to v
int n,m; // number of nodes and arcs of the given graph
int s,t; // source and destination nodes
// priority queue data structure (BINARY HEAP)
int d[MAX];// d[v] is the upper bound of the length of the shortest path from s
// to v (key)
int node[MAX];// node[i] the i^th element in the HEAP
int idx[MAX];// idx[v] is the index of v in the HEAP (idx[node[i]] = i) 
int sH;// size of the HEAP
bool fixed[MAX];
void swap(int i, int j){
    int tmp = node[i]; 
    node[i] = node[j]; 
    node[j] = tmp; 
    idx[node[i]] = i; idx[node[j]] = j;
}
void upHeap(int i){
    if(i == 0) return; while(i > 0){
        int pi = (i-1)/2; 
        if(d[node[i]] < d[node[pi]]){
            swap(i,pi);
        }else{
            break; 
        }
        i = pi; 
    }
}
void downHeap(int i){ 
    int L = 2*i+1; 
    int R = 2*i+2;
    int maxIdx = i;
    if(L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L; 
    if(R < sH && d[node[R]] < d[node[maxIdx]]) maxIdx = R; 
    if(maxIdx != i){
        swap(i,maxIdx); 
        downHeap(maxIdx); 
    }
}
void insert(int v, int k){// add element key = k, value = v into HEAP d[v] = k;
    node[sH] = v;
    idx[node[sH]] = sH;
    upHeap(sH);
    sH++; 
}   
int inHeap(int v){ 
    return idx[v] >= 0;
}
void updateKey(int v, int k){
    if(d[v] > k){
        d[v] = k;
        upHeap(idx[v]); 
    }else{
        d[v] = k;
        downHeap(idx[v]); 
    }
}
 
int deleteMin(){
    int sel_node = node[0]; 
    swap(0,sH-1);
    sH--;
    downHeap(0);
    return sel_node;
}
void input(){ 
    scanf("%d%d",&n,&m);
    for(int k = 1; k <= m; k++){
        int u,v,w; 
        scanf("%d%d%d",&u,&v,&w); 
        A[u].push_back(v); 
        c[u].push_back(w);
    }
    scanf("%d%d",&s,&t); 
}
void init(int s){ 
    sH = 0;
    for(int v = 1; v <= n; v++){ 
        fixed[v] = false; 
        idx[v] = -1;
    }
    d[s] = 0; 
    fixed[s] = true;
    for(int i = 0; i < A[s].size(); i++){
        int v = A[s][i];
        insert(v,c[s][i]); 
    }
}
void solve(){
    init(s);
    while(sH > 0){
        int u = deleteMin(); fixed[u] = true; 
        for(int i = 0; i < A[u].size(); i++){
            int v = A[u][i]; 
            if(fixed[v]) continue; 
            if(!inHeap(v)){
                int w = d[u] + c[u][i]; insert(v,w); }else{
                    if(d[v] > d[u] + c[u][i]) updateKey(v,d[u]+c[u][i]);
                } 
            }
        }
    int rs = d[t]; 
    if(!fixed[t]) rs = -1; 
    printf("%d",rs);
}
int main(){
   input();
   solve();
}
 