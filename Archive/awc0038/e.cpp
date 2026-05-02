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
    
    vector uv(N, vector<bool>(N));
    rep(i,K) {
        int u,v; cin>>u>>v; u--,v--;
        uv[u][v] = uv[v][u] = true;        
    }    
    ll ans=0;
    vector X(2, vector<ll>{});    
    rep(kkk,2) {
        int n = N12[kkk];
        vector<ll> allow(n);
        int offs = 0;
        if(kkk==1) offs += N1;
        rep(i,n) {
            allow[i]|=(1ll<<i);
            rep(j,n) {
                if(uv[i+offs][j+offs]){
                    allow[i]|=(1ll<<j);
                    allow[j]|=(1ll<<i);
                }
            }
        }
        ll full = 1ll<<n;
        X[kkk].resize(full,0);        
        rep(S,full) {
            rep(i, n) {
                ll S2 = S|(1ll<<i);
                /*
                if(kkk==1 && S2==10) {
                    cerr<<"debug"<<endl;
                }
                */
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
    rep(S, (1ll)<<N1) {
        ll S2 = ((1ll)<<N2)-1;
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