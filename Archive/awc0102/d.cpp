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
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N),C(N);
    rep(i,N)cin>>P[i]>>C[i];
    vector uv(N, vector<ll>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
    }
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful){
        bool flg=true;
        ll sm=0;
        rep(i,N) {
            if(S>>i & 1) {
                sm+=P[i]-C[i];
                for(auto nx:uv[i]) {
                    if((S>>nx & 1) == 0) flg=false;
                }
            }
        }
        if(flg)chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}