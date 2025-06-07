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
    cin >> N >> M;
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    int cnt = 0;
    dsu UF(N);    
    vector res(N, vector<int>{});
    vector<int> ans(N);
    for(int i=N-1; i>=0; i--){
        ans[i] = cnt;
        cnt++;
        for(auto nx: res[i]){
            if(!UF.same(nx, i)) {
                cnt--;
                UF.merge(nx, i);
            }
        }
        for(auto nx: uv[i]){            
            if(nx<i) res[nx].push_back(i);
        }        
    }
    for(auto a: ans) cout << a << endl;
    return 0;
}