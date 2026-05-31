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

    vector sub(N, vector<bool>(N));
    vector<bool> visit(N);
    vector<pair<int,int>> par(N,{-1, -1});

    auto f1 = [&](auto f1, int cur)->void{
        visit[cur] = true;
        sub[cur][cur] = true;
        for(auto [nx, i]: uv[cur]) {
            if(visit[nx]) continue;
            chld[cur].emplace_back(nx, i);
            f1(f1, nx);
            rep(i,N) sub[cur][i] = sub[nx][i] | sub[cur][i];
            par[nx] = {cur, i};
        }
    };
    f1(f1, 0);
    vector<ll> cnt(N-1);
    auto f2 = [&](auto f2, int cur, int tgt)->void{
        if(cur == tgt) return;
        bool flg = false;
        for(auto [nx, i]: chld[cur]) {
            if(sub[nx][tgt]) {
                cnt[i]++;
                flg = true;
                f2(f2, nx, tgt);
                return;
            }                        
        }
        if(!flg) {
            auto [nx, i] = par[cur];
            cnt[i]++;
            f2(f2, nx, tgt);
        }
    };

    int cur = A[0];
    rep(i,M-1) {
        int tgt = A[i+1];
        f2(f2, cur, tgt);
        cur = tgt;
    }

    vector<ll> cnt2{};
    mint ans = 1;
    rep(i,N-1){
        if(cnt[i] == 0) ans*=2;
        else cnt2.emplace_back(cnt[i]);
    }
    mint ans2 = 0;
    auto f3 = [&](auto f3, int cur, ll r, ll b)->void{
        if(cur <= cnt2.size()-1) {
            if(cnt2[cur] > 0) {
                f3(f3, cur+1, r+cnt2[cur], b);
                f3(f3, cur+1, r, b+cnt2[cur]);
            }
        } else {
            if(r-b == K) {
                ans2++;
            }
        }
    };
    f3(f3, 0, 0, 0);
    ans *= ans2;
    cout<<ans.val()<<endl;
    return 0;
}