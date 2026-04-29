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

    vector<ll> C(N),P(N);
    rep(i,N) {
        cin>>C[i]>>P[i];
    }
    vector<pair<int,int>> uv(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[i]={u,v};
    }
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful){
        ll sm=0;
        ll cost=0;
        bool flg=true;
        rep(i,M){
            if((S>>uv[i].first & 1) && (S>>uv[i].second & 1)){
                flg=false;
                break;
            }
        }
        if(!flg)continue;
        rep(i,N){
            if(S>>i & 1) {
                sm+=P[i];
                cost+=C[i];
            }
        }
        if(cost<=K) chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;

}