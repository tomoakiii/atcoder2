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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    ll mx = -INF;
    vector<ll> mn(N, INF);
    rep(i,N){
        if(mn[i]) chmax(mx, A[i] - mn[i]);
        for(auto nx: uv[i]) {
            chmin(mn[nx], min(mn[i], A[i]));
        }
    }
    cout<<mx<<endl;
    return 0;
}