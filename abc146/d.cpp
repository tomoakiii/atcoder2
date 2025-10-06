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
    M = N-1;
    vector uv(N, vector<pair<ll,int>>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v,i);
        uv[v].emplace_back(u,i);
    }
    vector<int> color(M);
    set<int> st;
    auto dfs = [&](auto dfs, int cur=0, int pre=-1, int col=-1)->void{
        int x = 0;
        for(auto [nx, i]: uv[cur]) {
            if(x == col) x++;
            if(nx == pre) continue;
            else {
                color[i] = x+1;
                st.insert(x);
                dfs(dfs, nx, cur, x);
            }
            x++;
        }
    };
    dfs(dfs);
    cout<<st.size()<<endl;
    rep(i,M) cout<<color[i]<<endl;
    return 0;
}