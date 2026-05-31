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
    ll N,M;
    cin >> N >> M;
    vector<ll> C(N);
    ll ans=0;
    rep(i,N) cin>>C[i];
    ll full=1ll<<M;
    vector<ll> cost(full,INF);
    vector<ll> cov(N);
    cost[0]=0;
    rep(i,N) {
        ll S=0;
        rep(j,M) {
            int a; cin>>a;
            if(a) S|=(1ll<<j);
        }
        cov[i]=S;
    }
    rep(S,full){
        if(cost[S]==INF)continue;
        rep(i,N){
            ll nx=S|cov[i];
            chmin(cost[nx],cost[S]+C[i]);
        }
    }
    if(cost[full-1]==INF)cout<<-1<<endl;
    else cout<<cost[full-1]<<endl;
    return 0;
}