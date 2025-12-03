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
    ll N, M;
    cin >> N;
    M=N;
    pair<int,int> IR;
    vector uv(N, vector<int>{});
    unordered_set<int> st;
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        if(st.contains(u) && st.contains(v)) {
            IR = {u,v};
            continue;
        }
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        st.insert(u); st.insert(v);
    }
    dsu UF(N);
    vector<bool> visit(N);
    int last = -1;
    auto func = [&](auto func, int cur)->void{
        visit[cur] = true;
        for(auto nx: uv[cur]) {
            if(visit[nx]) continue;
            if(cur != IR.first && cur != IR.second && nx != IR.first && nx != IR.second) {
                UF.merge(nx, cur);
            }
            func(func, nx);
        }
    };
    func(func, 0);
    int Q; cin>>Q;
    while(Q--) {
        int x, y; cin>>x>>y; x--,y--;
        if(UF.same(x,y)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}