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

    ll N1=N/2, N2=N-N1;
    ll N12[] = {N1,N2};

    vector P(2, vector<ll>{});
    rep(kkk,2) {
        rep(i,N12[kkk]) {
            ll p; cin>>p;
            P[kkk].push_back(p);
        }
    }

    vector<ll> allow(N);
    vector uv(N, vector<bool>(N));
    rep(i,K) {
        int u,v; cin>>u>>v; u--,v--;
        uv[u][v] = uv[v][u] = true;
        allow[u] |= (1ll<<v);
        allow[v] |= (1ll<<u);
    }
    rep(i,N) {
        allow[i] |= (1ll<<i);
    }
    for(int i=N1; i<N1+N2; i++) {
        allow[i] = allow[i] >> N1;
    }

    ll full[] = {1ll<<N1, 1ll<<N2};
    ll ans=0;
    vector X(2, vector<ll>{});
    rep(kkk,2) {
        X[kkk].resize(full[kkk],0);
        rep(i,N12[kkk]) X[kkk][1ll << i] = P[kkk][i];
        rep(S,full[kkk]) {
            rep(i,N12[kkk]) {
                ll S2 = S|(1ll<<i);
                if(kkk==1 && S2==10) {
                    cerr<<"debug"<<endl;
                }
                if((allow[i] & S) == 0) chmax(X[kkk][S2], X[kkk][S] + P[kkk][i]);
                else chmax(X[kkk][S2], X[kkk][S]);
            }
        }
    }
    vector<ll> fbt(N2);
    rep(i,N2) {
        fbt[i] = 1<<i;
        fbt[i] = ~fbt[i];
    }
    rep(S,full[0]) {
        ll S2 = full[1]-1;
        rep(i,N1) {
            if(!(S >> i & 1)) continue;
            rep(j,N2) {
                if(uv[i][N1+j]) S2 &= fbt[j];
            }
        }
        chmax(ans, X[0][S] + X[1][S2]);
    }
    cout<<min(ans,M)<<endl;
    return 0;
}