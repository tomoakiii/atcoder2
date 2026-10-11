#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<pair<int,int>> t0,t1;
    scc_graph G(N);
    rep(i,Q){
        int t,u,v; cin>>t>>u>>v;
        u--,v--;
        G.add_edge(u,v);
        if(t==1){
            t1.push_back({u,v});
        } else {
            t0.push_back({u,v});
        }
    }
    int id = 0;
    vector<int> ind(N);
    for(auto vv:G.scc()){
        for(auto v:vv){
            ind[v]=id;
        }
        id++;
    }
    vector uv(id,set<int>{});
    vector<int> in(id);
    for(auto [l,r]:t1){
        int il = ind[l], ir = ind[r];
        if(il==ir){
            cout<<"No"<<endl;
            return 0;
        }
        if(uv[il].contains(ir))continue;
        uv[il].insert(ir);
        in[ir]++;
    }
    for(auto [l,r]:t0){
        int il = ind[l], ir = ind[r];
        if(il==ir)continue;
        if(uv[il].contains(ir))continue;
        uv[il].insert(ir);
        in[ir]++;
    }
    queue<int> que;
    vector<ll> dist(id,0);
    rep(i,id){
        if(in[i]==0)que.push(i);
    }
    while(!que.empty()) {
        int q = que.front();
        que.pop();
        for(auto nx: uv[q]) {
            in[nx]--;
            chmax(dist[nx], dist[q]+1);
            if(in[nx]==0) que.push(nx);
        }
    }
    cout<< "Yes"<<endl;
    rep(i,N) {
        int d = ind[i];
        cout<<dist[d]+1<<" \n"[i==N-1];
    }
    return 0;
}