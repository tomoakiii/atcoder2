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
    ll N;
    cin >> N;
    vector<int> C(N);
    rep(i,N) cin>>C[i];
    vector uv(N, vector<int>{});
    rep(i,N-1) {
        int u,v;
        cin >> u >> v; u--, v--;
        uv[u].push_back(v);
        uv[v].push_back(u);
    }
    multiset<int> st;
    vector<bool> ans(N, true);
    auto func = [&](auto func, int cur, int pre)->void{        
        if(st.contains(C[cur])) ans[cur] = false;
        st.insert(C[cur]);
        for(auto nx: uv[cur]){
            if (nx == pre) continue;
            func(func, nx, cur);
        }        
        st.erase(st.find(C[cur]));
    };
    func(func, 0, -1);
    rep(i,N) if(ans[i]) cout<<i+1<<endl;

    return 0;
}