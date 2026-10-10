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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,T;
    cin >> N >> M >> T;
    vector<ll> V(N);
    rep(i,N) cin>>V[i];
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M){
        int u,v; ll w;
        cin>>u>>v>>w;
        u--,v--;
        uv[u].push_back({v,w});
    }
    ll ful=1<<N;
    rep(S,ful){
        __int128_t sm=1;
        bool flg=false;
        rep(i,N){
            if(S>>i & 1) {
                if(sm*V[i]>=(__int128_t)T){
                    flg=true;
                }
            }
        }
        if(!flg)continue;
        
    }
    return 0;
}