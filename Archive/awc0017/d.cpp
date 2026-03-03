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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector uv(N, vector<ll>(N));
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        uv[u][v]=uv[v][u]=w;
    }
    ll F=1ll<<N;
    ll ans = -INF;
    rep(k,F) {
        ll mn = 0;
        ll sm = 0;
        int cnt=0;
        rep(i,N) {
            if((k>>i & 1) == 0) continue;
            sm += A[i];
            cnt++;
            for(int j=i+1;j<N;j++) {
                if((k>>j & 1) == 0) continue;
                mn += uv[i][j];
            }
        }
        if(cnt==K) chmax(ans, sm-mn);
    }
    cout<<ans<<endl;
    return 0;
}