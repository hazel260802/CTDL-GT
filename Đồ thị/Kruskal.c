//------Cây khung nhỏ nhất: thuật toán Kruskal----
 
#include <stdio.h> 
#define MAX 100001
// data structure for input graph 
int N, M;//N là số lượng gốc, M là số lượng cạnh
int u[MAX];//u,v thể hiện hai đầu mút
int v[MAX];
int c[MAX];//c thể hiện giá trị trọng số
int ET[MAX];//Danh sách cạnh trong cây khung
int nET;//Số lượng cạnh trong danh sách cạnh của các cây này

// data structure for disjoint-set
int r[MAX];// r[v] is the rank of the set v 
int p[MAX];// p[v] is the parent of v
long long rs; 
 
void unify(int x, int y){ 
    if(r[x] > r[y]) p[y] = x; //Nếu rank của x lớn hơn thì cha của y là x
    else{
        p[x] = y;
        if(r[x] == r[y]) r[y] = r[y] + 1; 
    }
}
void makeSet(int x){
    p[x] = x;
    r[x] = 0; 
}
int findSet(int x){ 
    if(x != p[x])p[x] = findSet(p[x]); 
    //biến tất cả các nút dọc theo đường đi từ x 
    //đến nút gốc thành nút con trực tiếp của nút gốc 
    return p[x];
}
   
//Sắp xếp theo thứ tự tăng dần trọng số
void swap(int *a, int *b){
    int tmp = a; a = b; b = tmp;
}
void swapEdge(int i,int j){ 
swap(c[i],c[j]);
swap(u[i],u[j]);
swap(v[i],v[j]);
}
int partition(int L,int R, int index){ 
    int pivot = c[index];
    swapEdge(index,R);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(c[i] < pivot){ 
            swapEdge(storeIndex,i); 
            storeIndex++;
        } 
    }
    swapEdge(storeIndex,R);
    return storeIndex; 
}
void quickSort(int L, int R){ 
    if(L < R){
        int index = (L+R)/2;
        index = partition(L,R,index);
        if(L < index) quickSort(L,index-1); 
        if(index < R) quickSort(index+1,R);
    } 
}
void QuickSort(){ 
    QuickSort(0,M-1);
}
void solve(){
    for(int x = 1; x <= N; x++) makeSet(x); //Thiết lập 1 rừng gồm n cây con
    QuickSort();//Sắp xếp các cạnh theo thứ tự không giảm
    rs = 0;//Giá trị của cây khung nhỏ nhất
    int count = 0;//Số lượng cạnh của cây
    nET = 0;
    //Duyệt qua tất cả các cạnh
    for(int i = 0;i < M; i++){
        //Tìm gốc của điểm i của 2 cây con u và v
        int ru = findSet(u[i]); 
        int rv = findSet(v[i]); 
        if(ru != rv){
            //Nếu u và v nằm trong 2 cây con khác nhau thì ghép 2 cây con (đưa thêm một cạnh)
            unify(ru,rv);
            nET++; ET[nET] = i;
            rs += c[i];
            count++;
            if(count == N-1) break;//Thêm vào đủ số lượng cạnh cần thiết
        } 
    }
    printf("%d\n",rs); 
}
void input(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < M; i++){
        scanf("%d%d%d",&u[i],&v[i],&c[i]);
    } 
}
int main(){
    input();
    solve();
}
  