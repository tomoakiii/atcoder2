#include <bits/stdc++.h>
using namespace std;


struct node{
    int n;
    int v;
    vector<int> child; // 
    vector<int> side;
    int parent;
    node(){}
    bool operator<(node x){
        return (x.n > n);
    }
};
vector<node> tree;
vector<int> otxt;

void dfs(){

}


int main(){
    int cnt;
    int N, M, K;
    cin >> N >> M >> K;
    tree,resize(N);
    otxt.resize(M);
    if (K%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    if (K == 0){
        cout << "Yes" << endl << 0 << endl;
        return 0;
    }
    int u, v;
    vector<node> sd(N);
    for (int i=0; i<N; i++) sd[i].v = i;    
    for (int i=0; i<M; i++){
        cin >> u >> v;
        u--; v--;
        sd[u].child.push_back(v);
        sd[u].side.push_back(i);
        sd[u].n++;
        sd[v].child.push_back(u);
        sd[v].side.push_back(i);
        sd[v].n++;
    }
    vector<bool> visit(N, false);
    visit[0] = true;
    int cnt=0;
    auto dfs = [&]{}


        for (int n=0; n<side[i].n; n++){
            int a = side[i].child[n];
            int b = side[i].side[n];
            if (!visit[a]){
                tree[cnt].child.push_back(a);
                tree[cnt].side.push_back(b);
                tree[cnt].n++;
                que.push({a, i});  
            }
        }

    if (K==0){
        cout << "Yes" << endl;
        cout << cnt << endl;
        for (int i=0; i<cnt; i++){
            cout << otxt[i]+1 << " ";
        }
        cout << endl;
        return 0;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}