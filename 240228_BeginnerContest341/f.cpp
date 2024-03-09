#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

struct node{
    int w;
    ll a;
    vector<int> con; 
    bool operator<(const node& right ) const {
        return w < right.w;
    }
};

auto comp_idx(node* ptr){
  return [ptr](int l_idx, int r_idx){
    return ptr[l_idx] < ptr[r_idx];
  };
}

int main(){
    ll N, M;
    cin >> N >> M;

    vector<node> t(N);

    int u, v;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        t[u].con.push_back(v);
        t[v].con.push_back(u);
    }
    for (int i=0; i<N; i++)  cin >> t[i].w;
    for (int i=0; i<N; i++)  cin >> t[i].a;
    //インデックスの配列を準備

    int idx[N];
    for(int i=0; i<N; i++) idx[i] = i;
    sort(idx, idx+N, comp_idx(t));
    vector<ll> dp(N);
    for(int i=0; i<N; i++){
        int q = idx[i];
        
        
         
    }
    

    cout << cnt << endl;
    return 0;
}

