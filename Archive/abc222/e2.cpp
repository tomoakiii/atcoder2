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
typedef modint998244353 mint;
int main(){
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(M);
    rep(i,M) {
        cin>>A[i];
        A[i]--;
    }
    
    vector uv(N, vector<pair<ll,int>>{});
    vector chld(N, vector<pair<ll,int>>{});
    rep(i,N-1) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v,i);
        uv[v].emplace_back(u,i);
    }

    vector sub(N, vector<int>(N, 0));
    vector<pair<int,int>> par(N,{-1, -1});

    
    auto f1 = [&](auto f1, int cur)->void{
        sub[cur][cur] = true;
        for(auto [nx, i]: uv[cur]) {
            if(nx == par[cur].first) continue;
            par[nx] = {cur, i};
            chld[cur].emplace_back(nx, i);
            f1(f1, nx);
            rep(j,N) sub[cur][j] |= sub[nx][j];
        }
    };
    f1(f1, 0);

    vector<ll> cnt(N-1, 0);
    auto f2 = [&](auto f2, int cur, int tgt)->void{
        if(cur == tgt) return;        
        for(auto [nx, i]: chld[cur]) {
            if(sub[nx][tgt]) {
                cnt[i]++;                
                f2(f2, nx, tgt);
                return;
            }                        
        }
        auto [nx, i] = par[cur];
        cnt[i]++;
        f2(f2, nx, tgt);
    };
    rep(is, M-1) f2(f2, A[is], A[is+1]);

    ll tot = 0;
    for(auto c: cnt) tot += c;
    if((tot+K)%2 > 0 || tot+K < 0) {
        cout<<0<<endl;
        return 0;
    }
    int sz = cnt.size();
    vector dp(N, vector<mint>(tot+K+2));
    dp[0][0] = 1;
    rep(i, N-1) {
        rep(j, tot+1) {
            dp[i+1][j] += dp[i][j];
            if(j + cnt[i] > tot+K+1) continue;
            dp[i+1][j+cnt[i]] += dp[i][j];
        }
    }
    mint ans = dp[N-1][(tot+K)/2];
    cout<<ans.val()<<endl;
    return 0;
}