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
typedef modint1000000007 mint;
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
    queue<int> que;
    que.push(0);
    vector<int> D(N, INFi);
    vector pi(N+1, vector<int>{});
    D[0] = 0;
    while(!que.empty()) {
        int q = que.front();
        que.pop();
        pi[D[q]].push_back(q);
        for(auto nx: uv[q]) {
            if(D[nx] <= D[q] +1 ) continue;
            D[nx] = D[q] + 1;            
            que.push(nx);
        }
    }
    vector<mint> dp(N);
    dp[0] = 1;
    rep(i,N+1) {
        for(auto cur: pi[i]) {
            for(auto nx: uv[cur]) {
                if(D[nx] == D[cur]+1) dp[nx] += dp[cur];
            }
        }        
    }
    cout<<dp[N-1].val()<<endl;
    return 0;
}