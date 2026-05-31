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
    vector<ll> X(N);
    rep(i,N) cin>>X[i];
    M = N-1;
    vector uv(N, vector<pair<ll,ll>>{});
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u].emplace_back(v, w);
        uv[v].emplace_back(u, w);
    }
    ll ans = 0;
    vector<bool> visit(N);
    auto f = [&](auto f, int cur) -> void{
        visit[cur] = true;
        for(auto [nx,w] : uv[cur]){
            if(visit[nx]) continue;
            f(f, nx);
            X[cur] += X[nx];
            ans += abs(X[nx]) * w;
        }
        //X[cur] = 0;
    };
    f(f,0);
    cout<<ans<<endl;
    return 0;
}