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
    ll N, M, K;
    cin >> N >> M >> K;
    ll N1=N/2;
    ll N2=N-N1;

    vector<ll> P(N1),P2(N2);
    rep(i,N1) cin>>P[i];
    rep(i,N2) cin>>P2[i];


    vector uv(N, vector<bool>(N));
    rep(i,K) {
        int u,v; cin>>u>>v; u--,v--;
        uv[u][v] = uv[v][u] = true;
    }

    ll full = 1ll<<N1;
    ll full2 = 1ll<<N2;
    vector<ll> s1(full,0);
    vector<ll> s2(full2,0);
    ll ans=0;

    rep(kkk,2) {
        rep(i,N1) s1[1ll << i] = P[i];
        rep(S,full) {
            ll S2 = 0;
            rep(j,N1) {
                if(!uv[i][j]) {
                    S2 |= (1ll << j);
                }
            }
            ll S3 = ((1<<i) - 1);
            s1[S] = max(s1[S3 & S2]+P[i], s1[S3]);
        }
        swap(full,full2);
        swap(s1,s2);
        swap(N1,N2);
        swap(P,P2);
    }

    rep(S,full) {
        ll S2 = 0;
        rep(i,N1) {
            if(!(S >> i & 1)) continue;
            rep(j,N2) {
                if(uv[i][N1+j]) S2 |= (1ll << j);
            }
        }
        ll S3 = (full2-1) & (~S2);
        chmax(ans, s1[S] + s2[S3]);
    }
    cout<<min(ans,M)<<endl;
    return 0;
}